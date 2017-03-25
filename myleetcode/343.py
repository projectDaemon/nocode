class Solution(object):
    def integerBreak(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n < 4:
            return n-1

        count = n / 3
        result = pow(3, count)

        x = n % 3
        if x == 0:
            return result
        elif x == 1:
            return result/3*4
        return result*2


s = Solution()
print s.integerBreak(2)
print s.integerBreak(10)
