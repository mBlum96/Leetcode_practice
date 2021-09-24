class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;
        vector<int> outputVec;
        for (int i=0; i<nums.size(); i++){
            hashmap.insert(make_pair(nums[i],i));
        }
        for (int num : nums){
            if (hashmap.count(target - num)>0){
                outputVec.push_back(hashmap.find(num)->second);
                outputVec.push_back(hashmap.find(target-num)->second);
                return outputVec;
            }
        }
        return outputVec;
    }
};
