class Solution(object):
    def intToRoman(self, num):
        '''
        :type num: int
        :rtype: str
        '''
        relation = [
            ['', 'I', 'II', 'III', 'IV', 'V', 'VI', 'VII', 'VIII', 'IX'],
            ['', 'X', 'XX', 'XXX', 'XL', 'L', 'LX', 'LXX', 'LXXX', 'XC'],
            ['', 'C', 'CC', 'CCC', 'CD', 'D', 'DC', 'DCC', 'DCCC', 'CM'],
            ['', 'M', 'MM', 'MMM']
        ]
        return relation[3][num/1000] \
               + relation[2][num%1000/100] \
               + relation[1][num%100/10] \
               + relation[0][num%10]

s = Solution()
print s.intToRoman(1)
print s.intToRoman(2)
print s.intToRoman(3)
print s.intToRoman(4)
print s.intToRoman(5)
print s.intToRoman(50)
print s.intToRoman(500)
print s.intToRoman(3000)
