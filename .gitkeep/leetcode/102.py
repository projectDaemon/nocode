# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

import Queue

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        result = []
        if root is None:
            return result

        q = Queue.Queue()
        q.put(root)

        while not q.empty():
            same_depth = []
            for i in range(q.qsize()):
                node = q.get()
                same_depth.append(node.val)
                if node.left:
                    q.put(node.left)
                if node.right:
                    q.put(node.right)
            result.append(same_depth)
        return result



