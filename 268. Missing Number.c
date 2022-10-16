#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


//naive solution:

int comperator(const int *a , const int *b){
    return (*a - *b);
}


int missingNumber(int* nums, int numsSize){
    qsort(nums,numsSize, sizeof(int),comperator);
    for(int i =0;i<numsSize;i++){
        if(i!=nums[i]){
            return i;
        }
    }
    return numsSize;
}

//bit manipulation solution
//this works because of the commutativity and associativity of xor
int missingNumber(int* nums, int numsSize){
    uint32_t ret = 0;
    for(int i =0;i<numsSize;i++){
        ret ^= i;
        ret ^= nums[i];
    }
    return ret^=numsSize;
}