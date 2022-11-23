# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


"""
if we have a BST, if q>p
example: 2 and 7, we know that 7 is larger than 2's parent so 
it cannot be it's decendant,
another example: 4 and 7, 7 is again larger than 4 parent so we
keep going up (stack?) until we either reach the root node or we 
find a value that is larger than 7, at that point we found the 
LCA
"""


def findAncestor(root: 'TreeNode',maxNode: int, minNode: int)-> 'TreeNode':
    if (root==None):
        return root
    if(maxNode>=root.val and minNode<=root.val):
        return root
    elif(maxNode<root.val):
        return findAncestor(root.left,maxNode,minNode)
    else:
        return findAncestor(root.right,maxNode,minNode)
    
    
    
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        maxNode = max(p.val,q.val)
        minNode = min(p.val,q.val)
        # stack = []
        return findAncestor(root,maxNode,minNode)
                