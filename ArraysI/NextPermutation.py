class Solution:
    def nextPermutation(self, nums: list[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        
        n  = len(nums) - 1
        breakPoint = -1

        for i in range(n - 1, -1, -1):
            if nums[i] < nums[i + 1]:
                breakPoint = i
                break

        if breakPoint == -1:
            nums.reverse()
            return

        for i in range(n, breakPoint, -1) :
            if(nums[i] > nums[breakPoint]) :
                nums[i], nums[breakPoint] = nums[breakPoint], nums[i]
                break


        i, j = breakPoint + 1, n 

        while i <= j :
            nums[i], nums[j] = nums[j], nums[i]
            i+=1
            j-=1


        return nums
