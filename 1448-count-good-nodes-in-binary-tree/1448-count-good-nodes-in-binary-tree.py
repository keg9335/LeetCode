# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        self.count = 0
        maximum = -1e4
        self.checkGoodNode(root, maximum)
        
        return self.count
                
    
    def checkGoodNode(self, root, maximum):
        if root:
            if root.val >= maximum:
                self.count += 1
                maximum = root.val
            self.checkGoodNode(root.left, maximum)
            self.checkGoodNode(root.right, maximum)
        