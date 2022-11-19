class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minPrice = prices[0]
        profit = 0
        for day in prices:
            if(day<minPrice):
                minPrice = day
            if(profit<day-minPrice):
                profit = day-minPrice
        return profit