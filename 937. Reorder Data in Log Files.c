
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comperator(const char **a, const char **b){
    int ptrA, ptrB = 0;
    int lenA = strlen(a[0]);
    int lenB = strlen(b[0]);
    while(a[0][ptrA]!=' '){
        ptrA++;
    }
    ptrA++;
    while(b[0][ptrB]!=' '){
        ptrB++;
    }
    ptrB++;
    if(isalpha(a[0][ptrA]) && isalpha(b[0][ptrB])){
        int lexCmp = strcmp(&a[0][ptrA],&b[0][ptrB]);
        if(!lexCmp){//if they are lexicographically the same, we sort by the header
            return strcmp(a[0],b[0]);
        }
        else{
            return lexCmp;
        }
    }
    else if(isalpha(b[0][ptrB])){
        return 1;
    }
    //this is kind of redundent, could have just written return -1
    else if (isalpha(a[0][ptrA])){
        return -1;
    }
    else{
        return 0;
    }
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** reorderLogFiles(char ** logs, int logsSize, int* returnSize){
    *returnSize = logsSize;
    qsort(logs,logsSize,sizeof(char*),comperator);
    return logs;
}
