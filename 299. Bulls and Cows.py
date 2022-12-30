class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        hashMap = Counter(secret)
        bulls = 0
        cows = 0
        #first loop to calculate bulls second
        #to calculate cows
        for i in range(len(guess)):
            if(guess[i] in hashMap):
                if(guess[i] == secret[i]):
                    hashMap[guess[i]] -= 1
                    bulls += 1
                    if(hashMap[guess[i]]==0):
                        del(hashMap[guess[i]])
        for i in range(len(guess)):
            if(guess[i] in hashMap):
                if(guess[i]!= secret[i]):
                    cows+=1
                    hashMap[guess[i]]-=1
                    if(hashMap[guess[i]]==0):
                        del(hashMap[guess[i]])
        ret = "{}A{}B".format(bulls,cows)
        return ret