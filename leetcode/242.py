class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """

        ds = {}
        for i in range(len(s)):
            if s[i] in ds:
                ds[s[i]] += 1
            else:
                ds[s[i]] = 1

        dt = {}
        for i in range(len(t)):
            if t[i] in dt:
                dt[t[i]] += 1
            else:
                dt[t[i]] = 1

        if len(ds) != len(dt):
            return False

        for k in ds.keys():
            if k not in dt:
                return False
            if ds[k] != dt[k]:
                return False
        return True

s = Solution()
print s.isAnagram(u"anagram","nagaram")