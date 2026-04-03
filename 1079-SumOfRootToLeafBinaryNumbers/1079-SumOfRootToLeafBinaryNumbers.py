# Last updated: 4/3/2026, 1:57:54 PM
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def helper(self, root, currNum):
        if not root:
            return 0
        currNum = (currNum << 1) | root.val
        if not root.left and not root.right:
            return currNum
            
        return self.helper(root.left, currNum) + self.helper(root.right, currNum)

    def sumRootToLeaf(self, root: Optional[TreeNode]) -> int:
        return self.helper(root, 0)