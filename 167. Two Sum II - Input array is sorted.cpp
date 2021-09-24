class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int r_ptr = numbers.size()-1;
        int l_ptr =0;
        while(true){
            if(numbers[r_ptr]+numbers[l_ptr]>target){
                r_ptr--;
            }
            else if(numbers[r_ptr]+numbers[l_ptr]<target){
                l_ptr++;
            }
            else{
                vector<int> result;
                result.push_back(l_ptr+1);
                result.push_back(r_ptr+1);
                return result;
            }
        }
    }
};
