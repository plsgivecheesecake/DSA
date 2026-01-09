# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        # Level sum means BFS, so we use a queue
        max_level_sum = float("-inf")
        level_with_max_sum = 1
        level = 1
        q = deque([root])
        while q:
            level_size = len(q)
            level_sum = 0
            for i in range(level_size):
                node = q.popleft()
                level_sum += node.val
                if node.left: q.append(node.left)
                if node.right: q.append(node.right)
            if max_level_sum < level_sum:
                max_level_sum = level_sum
                level_with_max_sum = level
            level += 1
        return level_with_max_sum
