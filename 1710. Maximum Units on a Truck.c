#include <stdlib.h>

//we want to use quick sort to sort the boxes by the number of units for each
//box
int comperator(const void *boxType1, const void *boxType2){
    int val1 = (*(int **)boxType1)[1];
    int val2 = (*(int **)boxType2)[1];
    return val1<val2;
}

int maximumUnits(int** boxTypes, int boxTypesSize, int* boxTypesColSize, int truckSize){
    int result = 0;
    qsort(boxTypes,boxTypesSize,sizeof(int) * (*boxTypesColSize),comperator);
    int i=0;
    while(truckSize>0 && i<boxTypesSize){
        result += boxTypes[i][1];
        boxTypes[i][0]--;
        truckSize--;
        if(boxTypes[i][0]<1){
            i++;
        }
    }
    return result;
}