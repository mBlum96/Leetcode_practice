// my approach is quite unique
// I decided to give a score to each direction, we start at 0
// two turns to the same direction will dedact a point 

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool isRobotBounded(char * instructions){
    int direction =0;
    int histogram[4] = {0};//north=0,east=1,south=2,west=3
    char c;
    char *instructions_ptr = instructions;
    for(int i=0; i<4; i++){
        while((c=*instructions)!='\0'){
            printf("curr instruction is %c \n", *instructions);
            // int temp_direction = direction;
            if(c=='G'){
                printf("got here \n");

                histogram[direction]=+1;
                // printf("norht is: %d \n",histogram[0]);
            }
            else if (c=='R'){
                direction = abs((direction + 1)%4);
            }
            else{
                direction = abs((direction - 1)%4);
            }
            // printf("norht is: %d \n",histogram[0]);
            // printf("curr instruction is %c \n", *instructions);
            // printf("direction is %d",direction);
            instructions++;
        }
        instructions = instructions_ptr;
    }
    if((histogram[0]!=histogram[2])){
        return false;
    }
    if(histogram[1]!=histogram[3]){
        return false;
    }
    return true;
}