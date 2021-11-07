#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> result;
    int odd = N%2;
    
    if(odd){
        result.push_back(0);
        if(N==1){
            return result;
        }
    }

    for (size_t i = 0; i < N/2; i++)
    {
        result.push_back(i);
        result.push_back(-i);
    }
    
    return result;

}


vector<int> result;
