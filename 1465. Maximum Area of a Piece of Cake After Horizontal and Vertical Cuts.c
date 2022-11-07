int comperator(const void* val1, const void* val2){
    return *(int *)val1 - *(int *)val2;
}


int findMaxLen(int totalLen, int *cutsArr, int cutsArrSize){
    int i =0 ;
    int max = cutsArr[0];
    for(i=1; i<cutsArrSize ; i++){
        if(cutsArr[i] - cutsArr[i-1] > max){
            max = cutsArr[i] - cutsArr[i-1];
        }
    }
    if(totalLen-cutsArr[i-1] > max){
        max = totalLen-cutsArr[i-1];
    }
    return max;
}

int maxArea(int h, int w, int* horizontalCuts, int horizontalCutsSize, int* verticalCuts, int verticalCutsSize){
    int **matrix = malloc(sizeof(int)*h*w);
    qsort(horizontalCuts,horizontalCutsSize,sizeof(int),comperator);
    qsort(verticalCuts,verticalCutsSize,sizeof(int),comperator);
    long maxHight = findMaxLen(h, horizontalCuts,horizontalCutsSize);
    long maxWidth = findMaxLen(w, verticalCuts, verticalCutsSize);
    return (maxHight*maxWidth)%(long)(pow(10,9)+7);

}