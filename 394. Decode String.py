class Solution:
    def decodeString(self, s: str) -> str:
        stack = []
        curNum = 0
        curString = ""
        ret = ""
        for c in s:
            if c.isdigit():
                curNum = curNum*10 + int(c)
            elif c=='[':
                stack.append(curNum)
                stack.append(curString)
                curNum = 0
                curString = ""
            elif c==']':
                # print(stack)
                prevString = stack.pop()
                prevNum = int(stack.pop())
                curString = prevString + prevNum*curString
            else:
                curString+= (c)
        return curString