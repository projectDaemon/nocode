class Solution(object):
    def canWinNim(self, n):
        """
        :type n: int
        :rtype: bool
        """
        return n % 4 != 0


s = Solution()
print s.canWinNim(4)
print s.canWinNim(5)
