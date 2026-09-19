class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        minPrice = float('inf')

        profit = 0

        for p in prices:
            if p < minPrice :
                minPrice = p

            else :
                profit = max(profit, p - minPrice)


        return profit
