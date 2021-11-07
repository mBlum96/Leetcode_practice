#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    void check_if_major(vector<int>&nums, int candidate ,vector<int>&result){

        int counter =0;
        int num_size = nums.size();

        for (size_t i = 0; i < num_size; i++)
        {
            if(nums[i]==candidate){
                counter++;
            }
        }
        if(counter>num_size/3){
            if(result.size()>0 && result[0]!=candidate){ //there can be only two numbers max in the output vec
                result.push_back(candidate);
            }
            else if(result.size()<=0){
                result.push_back(candidate);
            }
        }
        
    }
    vector<int> majorityElement(vector<int>& nums) {
        //we are required to find elements that appear MORE than n/3 times.
        //that can only happen twice MAX
        //naive solution would have us using a histogram
        int first_candidate = nums[0];
        int second_candidate = first_candidate;
        int num_size = nums.size();
        int first_counter=0;
        int second_counter = 0; 
        vector<int> result;
        for (int num :nums){
            if(num!=first_candidate){
                second_candidate = num;
                break;
            }
        }

        for (size_t i = 0; i < num_size; i++)
        {
            if(nums[i]==first_candidate){
                first_counter++;
            }
            else if(nums[i]==second_candidate){
                second_counter++;
            }
            else{
                if(first_counter>0){
                    first_counter--;
                }
                if(second_counter>0){
                    second_counter--;
                }
            }
            if(first_counter==0){
                if(i!=num_size-1){
                    if(second_candidate!= nums[i+1]){
                        first_candidate = nums[i+1];
                    }
                }
                else{
                    first_candidate = nums[i];
                }
            }
            if(second_counter==0){
                if(i!=num_size-1){
                    if(first_candidate!= nums[i+1]){
                        second_candidate = nums[i+1];
                    }
                }
                else{
                    second_candidate = nums[i];
                }
            }
            
        }
        
        check_if_major(nums, first_candidate, result);
        check_if_major(nums, second_candidate, result);
        return result;
    }
};
int main(){
    vector<int> nums = {1,1,2,2,7,7,8,8,9,3,9,3,9,3,9,3,9,3,9,3,9,3,9,3,9,3,9,3,9,3,9,3,9,3,9,3,9,3};
    Solution sol;
    vector<int> result = sol.majorityElement(nums);
    for (int i : result){
        cout<<i<<endl;
    }
    return 0;
}