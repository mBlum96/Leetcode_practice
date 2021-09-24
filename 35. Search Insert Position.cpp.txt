class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int upper = std::distance(nums.begin(),nums.end())-1;
        int lower = 0;
        int mid = (lower + upper)/2;
        
        if(nums[upper]<target){
            return (upper+1);
        }
        else if (nums[lower]>target){
            return 0;
        }
        
        while(nums[mid]!=target){
            if(nums[mid]>target){
                upper = mid-1;
            }
            else if(nums[mid]<target){
                lower = mid+1;
            }
            mid = (lower + upper)/2;
            if (lower>upper){
                if(nums[lower]>target){
                    return (mid+1);
                }
                else{
                    return (mid-1);
                }
            }
        }
        return mid;
    }
};
