# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

#we want to traverse the tree using DFS



    
    
class Solution:
    def traverser(self, root: Optional[TreeNode], depth: int, out: List[List[int]]):
        if(root):
            if(len(out)==depth):
                out.append([])
            out[depth].append(root.val)
            self.traverser(root.left,depth+1,out)
            self.traverser(root.right,depth+1,out)
                
            
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        out = []
        self.traverser(root,0,out)
        return out
            
        
        