# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """

        h1 = l1
        h2 = l2

        l3 = None
        h3 = None

        next_sum = 0
        while True:
            val1 = 0
            val2 = 0
            if h1 is not None:
                val1 = h1.val
            if h2 is not None:
                val2 = h2.val

            cur = val1 + val2 + next_sum
            next_sum = cur / 10
            cur %= 10

            if h3 is None:
                h3 = ListNode(cur)
                l3 = h3
            else:
                h3.next = ListNode(cur)
                h3 = h3.next

            if h1 is not None:
                h1 = h1.next
            if h2 is not None:
                h2 = h2.next

            if h1 is None and h2 is None:
                break

        if next_sum > 0:
            h3.next = ListNode(next_sum)

        return l3


