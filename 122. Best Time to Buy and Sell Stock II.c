#include <stdlib.h>


// my algorithm is going to follow this:
// if we have a share and we are profitable and the next day the stock is worth more, we hold
// if the stock goes down tomorrow we sell it today and buy tomorrow
// increment profit only when we sell
int maxProfit(int* prices, int pricesSize){
    int profit = 0;
    int loc_min = prices[0]; 
    int i=0;
    for(; i<pricesSize-1;i++){
        if(prices[i+1]>prices[i]){
            continue;
        }else{
            profit += prices[i] - loc_min;
            loc_min = prices[i+1];
        }
    }
    if(i>0 && prices[i]>prices[i-1]){
        profit += prices[i] - loc_min;
    }
    return profit;
}