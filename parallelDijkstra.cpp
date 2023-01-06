//This is a parallel dijkstra algorithm 

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <future>
#include <iomanip>
#include <limits>

using namespace std;
using namespace std::chrono;

class Edge
{
public:
	int dest;
	int weight;
	Edge(int d, int w) : dest(d), weight(w) {};
};

class Graph
{
public:
	int V;
	vector<vector<Edge>> adjList;
	vector<int> dist;
	vector<int> prev;

	Graph(int v) : V(v)
	{
		adjList.resize(v);
		dist.resize(v);
		prev.resize(v);
	}

	void addEdge(int src, int dest, int weight)
	{
		adjList[src].push_back(Edge(dest, weight));
	}

	void printGraph()
	{
		for (int i = 0; i < V; i++)
		{
			cout << i << ": ";
			for (auto edge : adjList[i])
			{
				cout << edge.dest << "(" << edge.weight << ") ";
			}
			cout << endl;
		}
	}

	void printDist()
	{
		for (int i = 0; i < V; i++)
		{
			cout << i << ": " << dist[i] << endl;
		}
	}

	void printPrev()
	{
		for (int i = 0; i < V; i++)
		{
			cout << i << ": " << prev[i] << endl;
		}
	}
};

class Compare
{
public:
	bool operator()(pair<int, int> p1, pair<int, int> p2)
	{
		return p1.second > p2.second;
	}
};

void dijkstra(Graph &g, int src)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
	g.dist[src] = 0;
	pq.push(make_pair(src, 0));

	while (!pq.empty())
	{
		int u = pq.top().first;
		pq.pop();
		for (auto edge : g.adjList[u])
		{
			int v = edge.dest;
			int weight = edge.weight;
			if (g.dist[v] > g.dist[u] + weight)
			{
				g.dist[v] = g.dist[u] + weight;
				g.prev[v] = u;
				pq.push(make_pair(v, g.dist[v]));
			}
        }
    }
    //print g.dist:
    for (int i = 0; i < g.V; i++)
    {
        cout << i << ": " << g.dist[i] << endl;
    }

}

void parallelDijkstra(Graph &g, int src, int numThreads)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    g.dist[src] = 0;
    pq.push(make_pair(src, 0));

    mutex mtx;
    condition_variable cv;
    atomic<bool> done = false;
    atomic<int> numTasks = 0;

    auto dijkstraTask = [&g, &pq, &mtx, &cv, &done, &numTasks]()
    {
        while (true)
        {
            int u;
            {
                unique_lock<mutex> lk(mtx);
                cv.wait(lk, [&pq, &done]() { return !pq.empty() || done; });
                if (done)
                {
                    break;
                }
                u = pq.top().first;
                pq.pop();
                numTasks++;
            }

            for (auto edge : g.adjList[u])
            {
                int v = edge.dest;
                int weight = edge.weight;
                if (g.dist[v] > g.dist[u] + weight)
                {
                    g.dist[v] = g.dist[u] + weight;
                    g.prev[v] = u;
                    unique_lock<mutex> lk(mtx);
                    pq.push(make_pair(v, g.dist[v]));
                }
            }

            {
                unique_lock<mutex> lk(mtx);
                numTasks--;
                if (numTasks == 0)
                {
                    cv.notify_all();
                }
            }
        }
    };

    vector<thread> threads;
    for (int i = 0; i < numThreads; i++)
    {
        threads.push_back(thread(dijkstraTask));
    }

    for (auto &t : threads)
    {
        t.join();
    }

    //print g.dist:
    for (int i = 0; i < g.V; i++)
    {
        cout << i << ": " << g.dist[i] << endl;
    }
}

int main()
{
    int numThreads = 4;
    // int numVertices = 10000;
    int numVertices = 30;
    // int numEdges = 100000
    int numEdges = 100;
    int src = 0;
    // int dest = 9999;
    int dest = 29;
    int weight = 1;

    Graph g(numVertices);
    for (int i = 0; i < numEdges; i++)
    {
        g.addEdge(rand() % numVertices, rand() % numVertices, weight);
    }

    auto start = high_resolution_clock::now();
    dijkstra(g, src);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by serial Dijkstra: " << duration.count() << " microseconds" << endl;

    start = high_resolution_clock::now();
    parallelDijkstra(g, src, numThreads);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by parallel Dijkstra: " << duration.count() << " microseconds" << endl;

    return 0;
}