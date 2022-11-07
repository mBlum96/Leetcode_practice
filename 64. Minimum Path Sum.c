#include <stdlib.h>
#include <limits.h>


int minPathSum(int** grid, int gridSize, int* gridColSize){
    int **reverseWeightGrid = (int **)malloc(gridSize*sizeof(int*));
    for(int i=0;i< *gridColSize;i++){
        reverseWeightGrid[i] = malloc(*gridColSize * sizeof(int));
    }
    for(int i=0;i<gridSize;i++){
        for(int j=0;j<*gridColSize;j++){
            reverseWeightGrid[i][j] = grid[i][j];
        }
    }
    // reverseWeightGrid[gridSize-1][*gridColSize-1] = grid[gridSize-1][*gridColSize-1];
    for(int i = gridSize-1;i>0;i--){
        for(int j=*gridColSize-1;j>0;j++){
            if(j==*gridColSize-1 && i==gridSize-1)continue;
            int right = INT_MAX;
            int down = INT_MAX;
            if(j<*gridColSize-1){
                right = grid[i][j+1];
            }
            if(i<gridSize-1){
                down = grid[i+1][j]; 
            }
            reverseWeightGrid[i][j] += (right<down ? right : down);
            // reverseWeightGrid[i][j] += grid[i][j];
        }
    }
    return grid[0][0];
}

