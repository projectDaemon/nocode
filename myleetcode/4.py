class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        x = sorted(nums1 + nums2)
        y = len(x)
        if y % 2 == 0:
            return (x[y/2-1]+x[y/2])/2.0
        return x[y/2]


s = Solution()
print s.findMedianSortedArrays([1,2,3,4,5,6,7],[8,9,10])
print s.findMedianSortedArrays([1,2,3,4,5,6,7],[8,9])
