#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


//BFS based solution

int jump(int* nums, int numsSize){
    int numJumps = 0;
    int l = 0;
    int r = 0;
    while(r<numsSize-1){
        int max_jump = 0;//max jump is the maximum "index" we can land at
        for(int i =l; i<=r;i++){
            if (max_jump<nums[i]+i){
                max_jump = nums[i]+i;
            }
        }
        l = r+1;
        r = max_jump;//if we can jump from our current position further than the target, that means we can reach the target
        numJumps ++;
    }
    return numJumps;
}

// [2,3,1,1,4]
// [2,3,0,1,4]

// [2,1]