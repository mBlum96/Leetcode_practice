#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int,int> histogram;
        for(int candy : candyType){
            if(histogram.find(candy)==histogram.end()){
                histogram.insert({candy, 1});
            }
        }
        if(histogram.size()>=candyType.size()/2){
            return candyType.size()/2;
        }
        else{
            return histogram.size();
        }
    }
};

int main(){
    vector<int> candyType = {1,1,2,2,3,3};
    Solution sol;
    cout << sol.distributeCandies(candyType)<<endl;
    return 0;
}