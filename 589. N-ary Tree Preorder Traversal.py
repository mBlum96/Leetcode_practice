"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""


#I am going to keep the nodes I have left to go through in a stack
class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        out = []
        if(root==None): return out
        stack = [root,]
        while(stack):
            root = stack.pop()
            out.append(root.val)
            stack.extend(root.children[::-1])#stack is LIFO so we need to make sure we add the children
            #in the same manner we want to get them out (adding the last one first to the stack so it pops last)
        return out