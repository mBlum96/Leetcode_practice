#Greedy solution, we delete the target string and do so in O(n) time

#If we get the followup question we should get a variable to be the index we are concerned with 
#and that way we don't change the t string but just move the index/pointer so we get a substring of it 
#to consider in each iteration
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        tDict = {}
        for c in s:
            if(c not in t):
                return False
            else:
                t=t[t.index(c)+1:]
                # print(t)
        return True
