# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        if len(preorder) == 0: return None

        result = TreeNode(preorder[0])
        if len(preorder) == 1: return result

        for i in range(len(preorder)):
            if preorder[0] == inorder[i]:
                mid = i
                break
        else:
            mid = 0
            
        
        result.left = self.buildTree(preorder[1:mid+1], inorder[0:mid])
        result.right = self.buildTree(preorder[mid+1:], inorder[mid+1:])   
        
        return result
        