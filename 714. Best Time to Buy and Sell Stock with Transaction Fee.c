#include <stdlib.h>

//so at each day we can either sell a stock we bought on a previous day
//or keep it to sell at a later day
//we can either buy a stock or skip it 

int findMaxProfit(int previousProfit, int currentProfit){
    if(previousProfit>currentProfit){
        return previousProfit;
    }
    return currentProfit;
}

int findMinBuy(int previousEffectiveBuy, int currentEffectivePrice){
    if(previousEffectiveBuy>currentEffectivePrice){
        return currentEffectivePrice;
    }
    return previousEffectiveBuy;
}

int maxProfit(int* prices, int pricesSize, int fee){
    int profit = 0;//we calculate the current transaction profit
    int effectiveBuy = prices[0];//effective buy price is the price of the stock minus our profits,
    //meananing == how much extra cash we need to invest into buying it
    int currentProfit = 0;//the profit we can get if we sell today the stock we are holding
    for(int i=0; i<pricesSize;i++){
        currentProfit = prices[i]-fee-effectiveBuy;
        profit = findMaxProfit(profit,currentProfit);//we'll assume that the transaction fee is only
        //charged when we sell a stock, the effectiveBuy here is the one calculated for i-1 since we haven't updated it
        //for the current iteration yet
        effectiveBuy = findMinBuy(effectiveBuy,prices[i]-profit);
    }
    return profit;
}