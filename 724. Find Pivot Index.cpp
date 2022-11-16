#include <vector>

using std::vector;


//The smart thing to do would be to use a solution we have for 1480 
//running sum of 1d array
int vectorSum(vector<int>& nums) {
    int sum = 0;
    for (int i=0;i<nums.size();i++){
        sum+=nums[i];
    }
    return sum;
}

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int rightSum = vectorSum(nums) - nums[0];
        int pivot = 0;
        int leftSum = 0;
        while(pivot<nums.size()-1){
            if(rightSum==leftSum){
                return pivot;
            }
            leftSum +=nums[pivot];
            pivot++;
            rightSum -= nums[pivot];
        }
        if(leftSum==0)return pivot;
        return -1;
    }
};