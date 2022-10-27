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
    for(int i=0; i<4; i++){// do it 4 times to avoid cycle scenerio as false
        while((c=*instructions)!='\0'){
            if(c=='G'){
                histogram[direction]++;
            }
            else if (c=='R'){
                direction = (direction + 1)%4;
                
            }
            else{
                direction = (direction - 1)%4;
            }
            if(direction<0){
                direction +=4;
            }
            instructions++;
        }
        instructions = instructions_ptr;
        // for(int j=0;j<4;j++){
        //     printf("on the %d loop the histogram's %d element is %d \n",i,j,histogram[j]);
        // }
    }
    
    // for(int i=0;i<4;i++){
    //     printf("the histogram's %d element is %d \n",i,histogram[i]);
    // }
    if((histogram[0]!=histogram[2])){
        return false;
    }
    if(histogram[1]!=histogram[3]){
        return false;
    }
    return true;
}

//another solution without looping 4 times

// my approach is quite unique
// I decided to give a score to each direction, we start at 0
// two turns to the same direction will dedact a point 

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool isRobotBounded(char * instructions){
    int direction[2] = {0,1};
    char c;
    int position[2] = {0,0};
    int prevDirX;
    int prevDirY;
    
    while((c=*instructions)!='\0'){
        prevDirX = direction[0];
        prevDirY = direction[1];
        if(c=='G'){
            position[0] += direction[0];
            position[1] += direction[1];
        }
        else if (c=='R'){
            direction[0] = prevDirY;
            direction[1] = prevDirX * (-1);
        }
        else{
            direction[0] = prevDirY * (-1);
            direction[1] = prevDirX;
        }
        instructions++;
    }
    return(((position[0]==0)&&(position[1]==0)) || ((direction[0]!=0)||(direction[1]!=1)));
}