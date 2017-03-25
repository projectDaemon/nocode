class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """

        # key - list of strs
        d = {}
        for string in strs:
            sorted_string = ''.join(sorted(string))

            if sorted_string in d:
                d[sorted_string].append(string)
            else:
                d[sorted_string] = [string]

        result = []
        for k in d:
            result.append(sorted(d[k]))

        return result

s = Solution()
s.groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"])
