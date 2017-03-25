class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        m = {}
        for i in range(len(nums)):
            n = nums[i]
            if n in m:
                m[n] += 1
            else:
                m[n] = 1

        for n in m.keys():
            if m[n] == 1:
                return n
        return 0

