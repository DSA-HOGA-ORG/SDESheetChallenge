class Solution:
    def majorityElement(self, nums: list[int]) -> list[int]:
        count = {}

        for x in nums:
            count[x] = count.get(x, 0) + 1

        return [x for x in count if count[x] > len(nums) // 3]
