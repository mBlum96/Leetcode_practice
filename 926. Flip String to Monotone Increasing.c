#include <stdlib.h>
#include <string.h>




int minFlipsMonoIncr(char * s){
    int numOfOnes = 0;
    int numOfFlips = 0;
    while(*s!='\0'){
        if(*s=='1'){
            numOfOnes++;
        }
        else if(numOfOnes>0){//meaning we get a zero after a one (string needs to be monotonous increasing, so that is a possible issue)
            numOfFlips++;
            numOfOnes--;
        }
        s++;
    }
    
    return numOfFlips;
}