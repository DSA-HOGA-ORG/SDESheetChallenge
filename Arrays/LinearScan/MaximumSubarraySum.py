class Solution:
    def maxSubArray(self, nums: list[int]) -> int:
        maxAns = nums[0]
        currentSum = 0

        for i in range(len(nums)) :
            currentSum += nums[i]
            maxAns = max(currentSum, maxAns)

            if currentSum < 0:
                currentSum = 0

        return maxAns
