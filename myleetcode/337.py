# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution(object):
    def rob(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        return self.go_rob(root)[0]

    def go_rob(self, root):
        """

        :param root:
        :return:  max rob , rob left and right
        """
        if root is None:
            return 0, 0

        rob_root_left, not_rob_root_left = self.go_rob(root.left)
        rob_root_right, not_rob_root_right = self.go_rob(root.right)
        return max(rob_root_left + rob_root_right , not_rob_root_left + not_rob_root_right + root.val), \
               rob_root_left + rob_root_right


