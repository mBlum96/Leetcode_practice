def dfs(grid, row, col, maxRow, maxCol):
    if(grid[row][col]=='0'):
        return
    grid[row][col] = '0'
    if(row>0):
        dfs(grid,row-1,col,maxRow,maxCol)
    if(row<maxRow):
        dfs(grid,row+1,col,maxRow,maxCol)
    if(col>0):
        dfs(grid,row,col-1,maxRow,maxCol)
    if(col<maxCol):
        dfs(grid,row,col+1,maxRow,maxCol)
    


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        rowLen = len(grid)
        colLen = len(grid[0])
        count = 0
        for i in range(rowLen):
            for j in range(colLen):
                if(grid[i][j]=='1'):
                    count += 1
                    dfs(grid,i,j,rowLen-1,colLen-1)
        return count