#include <limits.h>

int returnMax(int val1, int val2){
    if(val1>val2){
        return val1;
    }
    return val2;
}

int returnMin(int val1, int val2){
    if(val1>val2){
        return val2;
    }
    return val1;
}

int maxProfit(int* prices, int pricesSize){
    if(pricesSize==0){
        return 0;
    }
    int firstBuy = INT_MAX;
    int firstSell = 0;
    int secondBuy = INT_MAX;
    int secondSell = 0;

    for(int i=0;i<pricesSize;i++){//we want to buy the second time after we sell the first time 
        //we are using the profit from the first sell to buy the seconed time
        //the effective buying price for the second stock is the price of the stock
        //minus the profits we got from the first stock sell
        firstBuy = returnMin(firstBuy,prices[i]);
        firstSell = returnMax(firstSell, prices[i]-firstBuy);
        secondBuy = returnMin(secondBuy, prices[i]-firstSell);
        secondSell = returnMax(secondSell, prices[i]-secondBuy);
    }
    return returnMax(secondSell,firstSell);
}