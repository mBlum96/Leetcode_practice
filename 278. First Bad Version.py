# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        left = 1
        right = n
        while(right>left):
            mid = int((left+right)/2)
            if(isBadVersion(mid)):
                right = mid
            else:
                left = mid+1
        return left