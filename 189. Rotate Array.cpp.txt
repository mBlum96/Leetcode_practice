  class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        int prev_value;
        int curr_index;
        int next_index;
        int temp;
        int j=0;
        
        if(k==0){
            return;
        }
        for (int i=0; j<n; i++){
            curr_index = i;
            prev_value = nums[i];
            while(true){
                next_index = (curr_index + k)%n;
                temp = nums[next_index];
                nums[next_index] = prev_value;
                prev_value = temp;
                curr_index = next_index;
                j++;
                if(i==curr_index){
                    break;
                }
            }
        }
    }
};
