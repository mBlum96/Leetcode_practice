#include <vector>
#include <iostream>


#define VISITED -101

using std::vector;
using std::iostream;

//algorithm:
/*
if up is visited/NULL go right
if right is visited/NULL go down
if down is visited/NULL go left
if left is visited/NULL go up
if can't got anywhere break
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int maxRow = matrix.size();
        int maxCol = matrix[0].size();
        vector<int> ret;
        if(maxRow==1){
            return matrix[0];
        }
        if(maxCol==1){
            for(int i=0;i<maxRow;i++){
                ret.push_back(matrix[i][0]);
            }
            return ret;
        }
        int i=0;
        int j=0;
        int counter =0;
        while(matrix[i][j]!=VISITED){
            // std::cout<<counter<<std::endl;
            // std::cout<<"matrix:"<<matrix[i][j]<<std::endl;          
            ret.push_back(matrix[i][j]);
            counter++;
            if(counter>=maxRow*maxCol) break;
            matrix[i][j] = VISITED;
            if(i==0 && j<maxCol-1){
                j++;
                continue;
            }
            if(j==maxCol-1 && i<maxRow-1){
                i++;
                continue;
            }
            if(i==maxRow-1 && j>0){
                j--;
                continue;
            }
            if(j==0 && i>1){
                i--;
                continue;
            }
            if(matrix[i-1][j] == VISITED && matrix[i][j+1]!=VISITED){
                j++;
                continue;
            }
            if(matrix[i][j+1] == VISITED && matrix[i+1][j]!=VISITED){
                i++;
                continue;
            }
            if(matrix[i+1][j] == VISITED && matrix[i][j-1]!=VISITED){
                j--;
                continue;
            }
            if(matrix[i][j-1] == VISITED && matrix[i-1][j]!=VISITED){
                i--;
                continue;
            }
            break;
        }
        return ret;
    }
};