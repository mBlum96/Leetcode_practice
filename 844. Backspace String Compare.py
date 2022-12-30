def stackManager(stack: list, s: str):
    for c in s:
        if c == '#':
            if(stack):
                stack.pop()
        else:
            stack.append(c)

class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        stackS = []
        stackT = []
        stackManager(stackS, s)
        stackManager(stackT, t)
        return stackS == stackT
