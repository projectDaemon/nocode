class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """

        visited = {}
        i = 0
        j = 0
        count = len(s)
        max_len = 0

        while j < count:
            n = s[j]

            if n in visited:
                while s[i] != s[j]:
                    visited.pop(s[i])
                    i += 1
                i += 1
                j += 1
            else:
                visited[n] = 1
                j += 1

            cur_len = j - i
            max_len = max(cur_len, max_len)

        return max_len

s = Solution()
# print s.lengthOfLongestSubstring('bbbbb')
# print s.lengthOfLongestSubstring('abcabca')
print s.lengthOfLongestSubstring('dvdf')

