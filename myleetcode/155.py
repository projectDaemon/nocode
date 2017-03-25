class MinStack(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.data = []
        self.length = 0
        self.min = None


    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        if x is None:
            return
        if len(self.data) <= self.length:
            self.data.append(x)
        else:
            self.data[self.length] = x
        self.length += 1
        if self.min is None:
            self.min = x
        else:
            self.min = min(self.min, x)



    def pop(self):
        """
        :rtype: void
        """
        if self.length == 0:
            return

        x = self.data[self.length - 1]
        self.data[self.length - 1] = None
        self.length -= 1

        if self.min == x:
            self.min = None
            for i in range(self.length):
                if self.min is None:
                    self.min = self.data[i]
                else:
                    self.min = min(self.data[i], self.min)


    def top(self):
        """
        :rtype: int
        """
        if self.length == 0:
            return None
        return self.data[self.length - 1]



    def getMin(self):
        """
        :rtype: int
        """
        return self.min



# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()

minStack = MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
print minStack.getMin();   #--> Returns -3.
minStack.pop();
print minStack.top();      #--> Returns 0.
print minStack.getMin();   #--> Returns -2.