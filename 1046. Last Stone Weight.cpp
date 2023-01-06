#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue <int,std::vector<int>,std::less<int>> maxHeap;
        for (int stone : stones){
            maxHeap.push(stone);
        }
        while(maxHeap.size()>1){
            int firstStone = maxHeap.top();
            maxHeap.pop();
            int secondStone = maxHeap.top();
            maxHeap.pop();
            if(firstStone>secondStone){
                maxHeap.push(firstStone-secondStone);
            }
        }
        if(maxHeap.size()<1){
            return 0;
        }
        return maxHeap.top();
    }
};