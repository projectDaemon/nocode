

import math

def divide(a,b):
    if a > 0 > b or a < 0 < b:
        if a % b == 0:
            return a/b
        else:
            return int(math.ceil(a/b) + 1)
    else:
        return a/b


class Solution(object):
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        stack = []
        for token in tokens:
            if token in '+-*/':
                if len(stack) < 2:
                    print 'error'
                    return 0
                b = stack.pop()
                a = stack.pop()
                if token == '+':
                    c = a + b
                elif token == '-':
                    c = a - b
                elif token == '*':
                    c = a * b
                elif token == '/':
                    if a > 0 > b or a < 0 < b:
                        c = divide(a, b)
                    else:
                        c = a / b
                    # print 'c = ', c, ' a = ', a, ' b = ',b
                else:
                    print 'error no c'
                    return 0
                stack.append(c)
            else:
                # number
                num = int(token)
                stack.append(num)
            # print stack

        if len(stack) != 1:
            print 'error count'
            return 0
        return stack.pop()


# s = Solution()
# s.evalRPN(["2", "1", "+", "3", "*"])
# print s.evalRPN(["4", "13", "5", "/", "+"])
# print s.evalRPN(["10","6","9","3","+","-11","*","/","*","17","+","5","+"])
# print s.evalRPN(["4","-2","/","2","-3","-","-"])

