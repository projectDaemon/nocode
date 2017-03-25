class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """

        d = dict.fromkeys(nums,0)
        for n in nums:
            d[n] += 1

        res = sorted(d.iteritems(), key=lambda x: x[1], reverse=True)
        return [d[0] for d in res[:k]]

# s = Solution()
# print s.topKFrequent([1,1,1,2,2,3],2)
