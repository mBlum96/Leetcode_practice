# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
def validateTree(root: Optional[TreeNode],maximum: int, minimum: int)-> bool:
    if(root==None): return True
    if(root.val >= maximum or root.val <= minimum):
        return False
    return validateTree(root.left,root.val,minimum) and validateTree(root.right,maximum,root.val)
    
    

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        return validateTree(root,pow(2,32),-1*pow(2,32))