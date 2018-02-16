# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        prev = None
        t = head
        while t is not None:
            cur = t
            ori_next = t.next
            t.next = prev
            prev = cur
            t = ori_next

        return prev



