/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize){
    *returnSize = 2;
    if(numsSize<=2){
        return nums;
    }
    int *ret = (int *)malloc(*returnSize * sizeof(int));
    for(int i =0;i < *returnSize;i++){
        ret[i] = 0;
    }
    int totalXor = 0;
    for(int i=0;i<numsSize;i++){
        totalXor ^= nums[i];
    }
    //now we need to find the first bit that is different between the two
    //numbers that make up our totalXor
    //that should be the first bit that is one in the xor
    //to find the first bit that is one we do totalXor &= (-totalXor)
    totalXor &= (-totalXor);
    for(int i=0;i<numsSize;i++){
        if(totalXor&nums[i]){
            ret[0] ^= nums[i];
        }else{
            ret[1] ^= nums[i];
        }
    }

    return ret;
}