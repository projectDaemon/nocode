class Solution(object):
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        num = 0
        for i in range(len(s)):
            c = s[i]
            val = ord(c) - ord('A') + 1
            num += val * pow(26, len(s)-1-i)
        return num


s = Solution()
print s.titleToNumber('A')
print s.titleToNumber('B')
print s.titleToNumber('Z')
print s.titleToNumber('AA')
