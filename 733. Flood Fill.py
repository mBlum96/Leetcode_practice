def painter(image: List[List[int]], sr:int, sc: int, color: int,rows:int ,columns: int, target: int):
    if(target==color): return
    if(image[sr][sc] == target):
        image[sr][sc] = color
    else:
        return
    if(sr<rows-1):
        painter(image, sr+1, sc, color, rows, columns, target)
    if(sr>0):
        painter(image,sr-1,sc,color,rows,columns, target)
    if(sc<columns-1):
        painter(image,sr,sc+1,color,rows,columns, target)
    if(sc>0):
        painter(image,sr,sc-1,color,rows,columns, target)
        

class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        painter(image,sr,sc,color,len(image),len(image[sr]),image[sr][sc])
        return image