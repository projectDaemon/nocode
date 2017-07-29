class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        sorted_nums = sorted(nums)

        x = 0
        y = len(sorted_nums) - 1
        while x < len(sorted_nums) and y > x:
            sum = sorted_nums[x] + sorted_nums[y]
            if sum > target:
                y -= 1
            elif sum < target:
                x += 1
            else:
                break

        num1 = sorted_nums[x]
        num2 = sorted_nums[y]

        res = []
        for x in range(len(nums)):
            if num1 == nums[x]:
                res.append(x)
            elif num2 == nums[x]:
                res.append(x)

        return res







s = Solution()
print s.twoSum([7,2,10,11],9)