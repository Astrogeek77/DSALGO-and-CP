
// #include <bits/stdc++.h>
// long helper(int i, int buy, long *prices, int n, vector<vector<int>> &dp)
// {
//     if (i == n)
//         return 0;

//     if (dp[i][buy] != -1)
//         return dp[i][buy];

//     int pick, npick;
//     long profit = 0;
//     if (buy)
//     {
//         pick = (-prices[i] + helper(i + 1, 0, prices, n, dp));
//         npick = (0 + helper(i + 1, 1, prices, n, dp));
//         return profit = max(pick, npick);
//     }
//     else
//     {
//         pick = (prices[i] + helper(i + 1, 1, prices, n, dp));
//         npick = (0 + helper(i + 1, 0, prices, n, dp));
//         return profit = max(pick, npick);
//     }
//     return dp[i][buy] = profit;
// }

// long getMaximumProfit(long *values, int n)
// {
//     vector<vector<int>> dp(n, vector<int>(2, -1));
//     return helper(0, 1, values, n, dp);
// }

long getMaximumProfit(long *values, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    dp[0][0] = 0;
    dp[0][1] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (buy = 0; buy <= 1; buy++)
        {
            int pick, npick;
            long profit = 0;
            if (buy)
            {
                pick = (-prices[i] + dp[i + 1][0]);
                npick = (0 + dp[i + 1][1]);
                profit = max(pick, npick);
            }
            else
            {
                pick = (prices[i] + dp[i + 1][1]);
                npick = (0 + dp[i + 1][0]);
                profit = max(pick, npick);
            }
            dp[i][buy] = profit;
        }
    }
    return dp[n][1];
}
