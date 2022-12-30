class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        count = 0
        l=0
        r=0
        hashMap = {}
        hashMax = 0
        while(r<len(s)):
            hashMap[s[r]]= hashMap.get(s[r],0)+1
            hashMax = max(hashMap.values())
            if(r-l+1-hashMax>k):
                hashMap[s[l]]-=1
                l+=1
            else:
                count = max(count,r-l+1)
            r+=1
        return count