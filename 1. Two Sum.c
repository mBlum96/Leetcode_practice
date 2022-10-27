#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

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

#define HASH_SIZE 269 //this should be a prime number so there are no unnecicary modulo hits
//hashmap solution
static int hash_arr[HASH_SIZE];

struct Node{
    int index;
    struct Node *next;
};

int hash(int value){//this is the hash function
    return abs((value%HASH_SIZE));
}

void initHashTable(struct Node *ht){
    for(int i=0; i< HASH_SIZE;i++){
        ht[i].index = -1;
        ht[i].next = NULL;
    }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int *ret = (int *)malloc(*returnSize * sizeof(int));

    struct Node *ht = (struct Node *)malloc(sizeof(struct Node) * HASH_SIZE);
    initHashTable(ht);

    int hash_num;
    //fill hash table with nums[i]-i pairs (at the nums[i] location we will find i)
    for(int i =0;i<numsSize;i++){
        hash_num = hash(nums[i]);
        if(ht[hash_num].index==-1){
            ht[hash_num].index = i;
        }else{
            //slot is not empty, need to link at list
            struct Node *new = (struct Node *)malloc(sizeof(struct Node));
            new->index = i;
            new->next=NULL;

            struct Node *temp = &ht[hash_num];
            while(temp->next!=NULL){//looping through the list so we get to the first free node
                temp = temp->next;
            }
            temp->next = new;
        }
    }
    //check hashtable for coresponding pair
    for(int i=0;i<numsSize;i++){
        hash_num = hash(target - nums[i]);
        if(ht[hash_num].index==-1) continue;//check if a corresponding pair exist

        if(nums[ht[hash_num].index] == target - nums[i] && ht[hash_num].index != i){//checking that I do not return the index itself
            ret[0] = i;
            ret[1] = ht[hash_num].index;
            return ret;
        }else{
            struct Node *temp = ht[hash_num].next;
            while(temp!=NULL){
                if(nums[temp->index]==target-nums[i]&&temp->index!=i){
                    ret[0] = i;
                    ret[1] = temp->index;
                    return ret;
                }
                temp=temp->next;
            }
        }
    }
    return ret;
}