class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        i = len(a)-1
        j = len(b)-1

        sum = ''
        z = 0
        while True:
            if i<0 and j < 0:
                break
            x = 0
            if i >=0 and a[i] == '1':
                x = 1
            y = 0
            if j >=0 and b[j] == '1':
                y = 1

            if x + y + z == 3:
                z = 1
                sum = '1' + sum
            elif x+y+z == 2:
                z = 1
                sum = '0' + sum
            elif x+y+z == 1:
                z = 0
                sum = '1' + sum
            else:
                z = 0
                sum = '0' + sum
            i-=1
            j-=1
        if z == 1:
            sum = '1' + sum

        return sum


s = Solution()
print s.addBinary('1','11')






