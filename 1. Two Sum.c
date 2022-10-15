#include <stdio.h>
#include <stdlib.h>

int comperator(const void* p1, const void* p2){
    return(*(int*)p1 - *(int*)p2);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *ans = malloc(sizeof(int) * 2);
    ans[0] = -1;
    ans [1] = -1;
    int *arrcpy = malloc(sizeof(int) * numsSize);
    for(int i =0; i<numsSize;i++){
        arrcpy[i] = nums[i];
    }
    int *values[2] = {0};
    int *ptr = arrcpy;
    int r = numsSize-1;
    int l = 0;
    //we want to sort the array
    qsort(ptr,numsSize,sizeof(int),comperator);
    
    while(r>l){
        if(arrcpy[l]+arrcpy[r]>target){
            r--;
        }
        else if(arrcpy[l]+arrcpy[r]<target){
            l++;
        }
        else{
            values[0] = arrcpy[l];
            values[1] = arrcpy[r];
            break;
        }
    }
    r = numsSize-1;
    l = 0;
    while(1){
        if(nums[r]!=values[0]&&nums[r]!=values[1]){
            r--;
            continue;
        }
        if(nums[l]!=values[0]&&nums[l]!=values[1]){
            l++;
            continue;
        }
        else{
            ans[0] = l;
            ans[1] = r;
            break;
        }
    }
    
    free(arrcpy);
    *returnSize = 2;
    return ans;
}