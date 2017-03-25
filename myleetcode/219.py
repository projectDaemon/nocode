class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        d = {}
        for i in range(len(nums)):
            n = nums[i]
            if n in d:
                d[n].append(i)
            else:
                d[n] = [i]

        print d

        for key in d.keys():
            arr = d[key]
            if len(arr) <= 1:
                continue

            print arr

            i = 0
            j = len(arr) - 1
            b = True
            while i < j:
                print 'i = ', i , ' j = ', j, ' k = ',k
                if abs(arr[j] - arr[i]) <= k:
                    return True
                if b:
                    i += 1
                else:
                    j -= 1
                b = not b
        return False


s = Solution()
# print s.containsNearbyDuplicate([1, 2], 2)
# print s.containsNearbyDuplicate([1,0,1,1], 1)
# print s.containsNearbyDuplicate([4,1,2,3,1,5], 3)
# print s.containsNearbyDuplicate([-1, -1], 1)
print s.containsNearbyDuplicate([1, 2,1], 1)
