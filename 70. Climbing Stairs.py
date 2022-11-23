#the base case is you have the first stair which you have two options
#then on the second you again have two options from each step that you landed on
#from thhe frtist step



# Memorization solution:
options={}


def countOptions(n:int):
    if(n not in options):
        options[n] = countOptions(n-1) + countOptions(n-2)
    return options[n]

class Solution:
    def climbStairs(self, n: int) -> int:
        options[1] = 1
        options[2] = 2
        return countOptions(n)

# class Solution:
#     def climbStairs(self, n: int) -> int:
#         one = 1
#         two = 1
#         for i in range(n-1):
#             temp = one
#             one = one + two 
#             two = temp
#         return one