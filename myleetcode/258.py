class Solution(object):
    def addDigits(self, num):
        """
        :type num: int
        :rtype: int
        """
        if num == 0:
            return 0
        import math
        return int(num - 9 * math.floor((num-1) / 9))


s = Solution()
print s.addDigits(38)
