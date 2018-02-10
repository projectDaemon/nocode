# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        import sys

        if root is None:
            return 0
        # leaf
        if not root.left and not root.right:
            return 1

        # below not leaf
        left = self.minDepth(root.left) + 1
        if left == 1:
            left = sys.maxint

        right = self.minDepth(root.right) + 1
        if right == 1:
            right = sys.maxint

        return min(left, right)
