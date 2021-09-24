class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> hashmap;
        std::vector<int> outputVec;
        for (int i=0; i<nums.size(); i++){
            hashmap.insert(std::make_pair(nums[i],i));
        }
        int count =0;
        for (int num : nums){
            if (target-num == num){
                if (count>0){
                    outputVec.push_back(hashmap.find(target-num)->second); 
                }
                else{
                    for (int j=0; j<nums.size(); j++){
                        if (num == nums[j]){
                            count++;
                            if (count > 1){
                                outputVec.push_back(j);
                            }
                        }
                    }
                }
            }
            else if (hashmap.count(target - num)>0){
                outputVec.push_back(hashmap.find(num)->second);
                if (outputVec.size()<2){
                    outputVec.push_back(hashmap.find(target-num)->second);
                }
                return outputVec;
            }
        }
        return outputVec;
    }
};
