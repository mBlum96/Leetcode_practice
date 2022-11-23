class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        arr_d = {}
        for num in arr:
            if num not in arr_d:
                arr_d[num] = 1
            else:
                arr_d[num] += 1
        counter =0
        arr_d = sorted(arr_d.values())
        for item in arr_d:
            if(k >= item):
                k-=item
                del item
            else:
                k=0
                counter+=1
        return counter