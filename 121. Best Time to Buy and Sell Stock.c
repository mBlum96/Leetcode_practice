#include <stdio.h>
#include <stdlib.h>



int maxProfit(int* prices, int pricesSize){
    int i =0;
    int min = prices[i];
    int profit =0;
    
    for(i=1;i<pricesSize;i++){
        if(prices[i]-min>profit){
            profit = prices[i]-min;
        }
        
        if(min>prices[i]){
            min = prices[i];
        }
    
    }
    return profit;
}

//another implementation (wanted to test myself again without looking at how
//I implemented it in the first place)
int maxProfit(int *prices, int pricesSize){
    int i=0;
    int min = prices[0];
    int profit = 0;
    for(int i=0;i<pricesSize;i++){
        if(min>prices[i]){
            min = prices[i];
        }else if(profit < prices[i]-min){
            profit = prices[i] - min;
        }
    }
    return profit;
}