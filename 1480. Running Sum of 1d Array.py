class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        current_sum = 0
        new_list = []
        for num in nums:
            current_sum += num
            new_list.append(current_sum)
        return new_list
            