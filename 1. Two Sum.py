class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashMap = {}
        res = []
        for i in range(len(nums)):
            hashMap[i] = target - nums[i]
        for i in range(len(nums)):
            if(nums[i] in hashMap):
                res.append(i)
                res.append(hashMap[nums[i]].key)