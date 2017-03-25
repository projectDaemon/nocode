class Solution(object):
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """

        result = ''
        while True:
            result = str(chr(ord('A') + (n-1) % 26)) + result
            n = (n-1) / 26
            if n == 0:
                break
        return result


s = Solution()
for i in range(26 * 4):
    print i, ' - ', s.convertToTitle(i + 1)

