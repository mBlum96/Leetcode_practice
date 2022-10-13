#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define DEC 10

bool isPalindrome(int x){
    int len = log10(x)+1;
    char *buffer = NULL;
    buffer = malloc(sizeof(char) * (len+1));
    sprintf(buffer,"%d" ,x);
    
    for (int i = 0; i < (len/2 - 1); i++)
    {
        printf(buffer[i], "%d");
        printf(buffer[len-1-i], "%d");
        if(buffer[i]!=buffer[len-i-1]){
            free(buffer);
            return false;
        }
    }
    
    free(buffer);
    return true;
}