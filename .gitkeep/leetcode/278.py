# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

import time

# def isBadVersion(version):
#     return version >= 3

class Solution(object):
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """

        l = 1
        r = n
        while l < r:
            m = l + (r - l)/2
            print 'l = ',l,' r =',r,' m =',m
            if isBadVersion(m):
                r = m
            else:
                l = m

            if l == r:
                break
            if l+1==r and l==m:
                break
        return r




# s = Solution()
# print s.firstBadVersion(4)


