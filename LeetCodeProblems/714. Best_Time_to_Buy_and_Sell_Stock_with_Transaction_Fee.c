#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int maxProfit(int* prices, int pricesSize, int fee)
{
    int current_profit = -prices[0];
    int profit = 0;

    for (int indx = 0; indx < pricesSize; indx++)
    {
        current_profit = MAX(current_profit, profit - prices[indx]);
        profit = MAX(profit, current_profit + prices[indx] - fee);
    }
    


    return current_profit;
}