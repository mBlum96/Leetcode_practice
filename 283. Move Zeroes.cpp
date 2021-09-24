class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int right_ptr = std::distance(nums.begin(),nums.end())-1;
        int left_ptr = std::distance(nums.begin(),nums.begin());
        int temp;
        int n = nums.size();
        
        if(n<=1){
            return;
        }
        while(true){
            if(nums[left_ptr]==0){
                nums.erase(nums.begin()+left_ptr);
                nums.push_back(0);
                right_ptr--;
            }
            else{
                left_ptr++;
            }
            if(right_ptr==left_ptr){
                break;
            }
        }
    }
};
