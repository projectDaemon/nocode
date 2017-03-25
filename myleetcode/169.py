class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        d = {}
        for i in range(len(nums)):
            n = nums[i]
            if n in d:
                d[n] += 1
            else:
                d[n] = 1

        import math
        t = math.floor(len(nums)/2)
        for k in d.keys():
            if d[k] > t:
                return k

        return None
