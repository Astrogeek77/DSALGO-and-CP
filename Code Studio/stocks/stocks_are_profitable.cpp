#include <bits/stdc++.h>
int maximumProfit(vector<int> &prices)
{
    int mn = prices[0], profit = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        int cost = prices[i] - mn;
        profit = max(profit, cost);
        mn = min(prices[i], mn);
    }
    return profit;
}