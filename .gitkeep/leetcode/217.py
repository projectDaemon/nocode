class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        m = {}
        for i in range(len(nums)):
            n = nums[i]
            if n in m:
                return True
            m[n] = 1
        return False


