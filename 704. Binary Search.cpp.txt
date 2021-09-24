class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = std::distance(nums.begin(), nums.begin());
        int right = std::distance(nums.begin(), nums.end())-1;
        int halfway = (right+(right-left))/2;
        while(nums[halfway]!=target){
            if (nums[halfway]>target){
                right = halfway-1;
            }
            else if(nums[halfway]<target){
                left = halfway+1;
            }
            halfway = (right+(right-left))/2;
            if(right<left){
                return -1;
            }
        }
        return halfway;
    }
};
