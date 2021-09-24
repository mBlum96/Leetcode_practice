class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int right_ptr = n-1;
        int left_ptr = 0;
        int res;
        
        vector<int> outputVector(n);
        for(int i=n-1;i>=0;i--){
            if((nums[right_ptr]*nums[right_ptr])>(nums[left_ptr]*nums[left_ptr])){
                res=(nums[right_ptr]*nums[right_ptr]);
                right_ptr--;
            }
            else{
                res = nums.at(left_ptr)*nums.at(left_ptr);
                left_ptr++;
            }
            outputVector[i]=res;
        }
        return outputVector;
    }
};
