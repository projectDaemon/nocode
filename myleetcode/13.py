class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """

        relation = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000,
        }

        sum = 0
        temp = 0
        prev = None
        for i in range(len(s)):
            cur = relation[s[i]]
            if prev is None:
                prev = cur
                temp = cur
                continue

            if cur == prev:
                temp += cur
            elif cur > prev:
                sum += cur - temp
                temp = 0
            else: # cur < prev
                sum += temp
                temp = cur

            prev = cur

        sum += temp
        return sum

s = Solution()
print s.romanToInt('I')
print s.romanToInt('II')
print s.romanToInt('III')
print s.romanToInt('IV')
print s.romanToInt('V')
print s.romanToInt('VI')

print s.romanToInt('MCMXCVI')

