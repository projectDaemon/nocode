class Solution(object):
    def isNumber(self, s):
        """
        :type s: str
        :rtype: bool
        """
        ss = s.strip(' ')
        if len(ss) == 0:
            return False

        start = ord('0')
        end = ord('9')

        result = True
        ecount = 0
        pointcount = 0
        zerocount = 0
        numbercount = 0

        index = 0
        for n in list(ss):
            x = ord(n)

            if n == '0':
                zerocount += 1

            if start <= x <= end:
                index += 1
                numbercount += 1
                continue

            if n == '+' or n == '-':
                if len(ss) == 1:
                    result = False
                    break

                if index != 0:
                    if index > 0 and ss[index -1] == 'e':
                        if index == len(ss)-1:
                            result = False
                            break
                    else:
                        result = False
                        break
                if len(ss) > index+1 and ss[index+1] == 'e':
                    result = False
                    break

                index += 1
                continue

            if n == 'e':
                if index == 0:
                    result = False
                    break
                if index == len(ss) - 1:
                    result = False
                    break
                if zerocount >= index + 1:
                    result = False
                    break

                ecount += 1
                index += 1
                continue

            if n == '.':
                if index == 0 and len(ss)>1 and ss[index+1] == 'e':
                    result = False
                    break
                if ecount > 0:
                    result = False
                    break
                pointcount += 1
                index += 1
                continue

            result = False
            break

        if result:
            if ecount > 1 or pointcount > 1:
                result = False
            elif ecount == 1 and len(ss) == 1:
                result = False
            elif pointcount == 1 and len(ss) == 1:
                result = False

            if numbercount == 0:
                result = False

        return result

s = Solution()
# print s.isNumber('1')
# print s.isNumber(' 123 ')
# print s.isNumber(' 1.0 ')
# print s.isNumber(' 0.1 ')
# print s.isNumber(' 2e10 ')
# print '----------'
# print s.isNumber('a')
# print s.isNumber('a 1')
# print s.isNumber('a b')
# print s.isNumber('.e3')
# print s.isNumber('.3')
# print s.isNumber(" 005047e+6")
print s.isNumber('4e+')
