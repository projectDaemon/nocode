class Solution(object):
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        current = 0
        result = [0]
        block_count = 1

        while current != num:
            for i in range(0, block_count):
                result.append(result[i] + 1)
                current += 1
                if current == num:
                    break
            block_count = len(result)
        return result

s = Solution()
print s.countBits(5)
print s.countBits(8)
print s.countBits(10)
print s.countBits(100)




