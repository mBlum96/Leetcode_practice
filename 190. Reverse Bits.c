#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

uint32_t reverseBits(uint32_t n) {
    uint32_t mask = 1;
    uint32_t result = 0;
    for(int i=0;i<32;i++){
        result <<=1 ;
        if(mask&n){
            result|=1;
        }
        mask<<=1;
    }
    return result;
}