class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        count = len(nums)
        if count < 1:
            return

        # loop except the last one
        i = 0
        while i < count - 1:
            if nums[i] == 0:
                j = i+1
                while j < count:
                    if nums[j] != 0:
                        nums[i] = nums[j]
                        nums[j] = 0
                        break
                    j += 1
            i += 1



s = Solution()
nums = [0, 1, 0, 3, 12]
s.moveZeroes(nums)
print nums
