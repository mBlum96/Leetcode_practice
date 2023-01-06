#include <vector>

using std::vector;

bool valid(int rowSize, int colSize,int row, int col){
    if(rowSize<=row || colSize<=col || row<0 || col<0){
        return false;
    }
    return true;
}

int DFS(vector<vector<int>>& grid, int row, int col){
    int rowSize = grid.size();
    int colSize = grid[0].size();
    if(row==rowSize){
        return col;
    }
    if(valid(rowSize,colSize,row,col)){
        if(grid[row][col]==1){
            if(valid(rowSize,colSize,row,col+1)&&
            grid[row][col+1]==1){
                return DFS(grid,row+1,col+1);
            }
        }
        else{
            if(valid(rowSize,colSize,row,col-1)&&
            grid[row][col-1]==-1){
                return DFS(grid,row+1,col-1);
            }
        }
    }
    return -1;
}


class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int rowSize = grid.size();
        int columnSize = grid[0].size();
        vector<int> ret;
        for(int i=0;i<columnSize;i++){
            ret.push_back(DFS(grid,0,i));
        }
        return ret;
    }
};