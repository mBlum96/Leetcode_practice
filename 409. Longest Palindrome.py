# class Solution:
#     def longestPalindrome(self, s: str) -> int:
#         lenPolindrome = 0
#         occurances = {}
#         for c in s:
#             if c not in occurances:
#                 occurances[c] = 1
#             else:
#                 occurances[c] += 1
#         maxOdd = 0
#         for occurance in occurances.values():
#             if(occurance%2!=0):
#                 if(occurance>maxOdd):
#                     if(maxOdd!=0):
#                         lenPolindrome+=maxOdd-1
#                     maxOdd=occurance
#                 else:
#                     lenPolindrome+=occurance-1
#             else:
#                 lenPolindrome += occurance
#         return (lenPolindrome + maxOdd)

    
class Solution:
    def longestPalindrome(self, s: str) -> int:
        ans = 0
        
        #instead of using dict, we can do the bellow 6 lines in a single line
        #using collections:
        #collections.Counter(s).values()
        #or we can use counter (datatype):
        #occurances =Counter(s) 
        
        
        # occurances = {}
        # for c in s:
        #     if c not in occurances:
        #         occurances[c] = 1
        #     else:
        #         occurances[c] += 1
        occurances = Counter(s)
        for occurance in occurances.values():
            ans += int(occurance / 2) * 2
            if ans % 2 == 0 and occurance % 2 == 1:
                ans += 1
        return ans