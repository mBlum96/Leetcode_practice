class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if(len(s)!=len(t)):
            return False
        sToTDict = {}
        tToSDict = {}
        for char1,char2 in zip(s,t):
            if(char1 not in sToTDict) and (char2 not in tToSDict):
                sToTDict[char1] = char2
                tToSDict[char2] = char1
            elif (sToTDict.get(char1) != char2) or (tToSDict.get(char2)!=char1):
                return False
        return True
        
            