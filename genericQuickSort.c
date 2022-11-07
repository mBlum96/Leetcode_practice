#include <stdio.h>
#include <string.h>


//we require to get the size of the dst and the src.
//e.g. if they are strings of different length we pass strlen(src)*sizeof(char)
//for the first and in a similar fashion for the second
//If we are swaping different len strings we may cause buffer overflow 
//so I decided at the end to only allow one size parameter
//meaning that this is only intended for swaping same sized strings/types
void genericSwap(void *dst, void *src,int size){
    void *temp = malloc(size);
    memcpy(temp,dst,size);
    memcpy(dst,src,size);
    memcpy(src,temp,size);
    free(temp);
}

//we require the user to implement a compare function for they're datatype
//such that we return 1 if ptrA > ptrB and 0 if the opposite
//WHY? because if they pass struct "Person" I don't know if to sort them based on
// their age or their name
int comperator(void *ptrA, void *ptrB){

}

int partition(void **arr, int l, int r, int typeSize){
    int pivot = arr[l];
    int i = l+1;
    while(r>i){
        if(comperator(pivot,arr[r])){
            genericSwap(arr[r],arr[i],typeSize);
            i++;
        }
        r--;
    }
    genericSwap(arr[i],arr[l],typeSize);
    return i;
}


void genericQuickSort(void **arr, int arrSize, int typeSize){
    int l=0;
    int r = typeSize-1;
    if(r>l){
        int pivot = partition(arr,l,r,typeSize);
        genericQuickSort(arr,l,pivot-1);
        genericQuickSort(arr,pivot+1,r);
    }
}