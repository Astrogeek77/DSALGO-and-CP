#include <bits/stdc++.h>
// long helper(int i, int x, int *arr, vector<vector<long>> &dp)
// {
//     if (i == 0)
//     {
//         return (x % arr[i] == 0);
//     }

//     if (dp[i][x] != -1)
//         return dp[i][x];

//     long take = 0, ntake;
//     ntake = helper(i - 1, x, arr, dp);
//     if (x >= arr[i])
//         take = helper(i, x - arr[i], arr, dp);
//     return dp[i][x] = take + ntake;
// }
// long countWaysToMakeChange(int *coins, int n, int amount)
// {
//     vector<vector<long>> dp(n, vector<long>(amount + 1, -1));
//     return helper(n - 1, amount, coins, dp);
// }

long countWaysToMakeChange(int *arr, int n, int amount)
{
    vector<vector<long>> dp(n, vector<long>(amount + 1, -1));

    for (int t = 0; t <= amount; t++)
    {
        dp[0][t] = (t % arr[0] == 0);
    }

    for (int i = 1; i < n; i++)
    {
        for (int t = 0; t <= amount; t++)
        {
            long take = 0, ntake;
            ntake = dp[i - 1][t];
            if (t >= arr[i])
                take = dp[i][t - arr[i]];
            dp[i][t] = take + ntake;
        }
    }
    return dp[n - 1][amount];
}

long countWaysToMakeChange(int *arr, int n, int amount)
{
    vector<long> prev(amount + 1, 0), curr(amount + 1, 0);

    for (int t = 0; t <= amount; t++)
    {
        prev[t] = (t % arr[0] == 0);
    }

    for (int i = 1; i < n; i++)
    {
        for (int t = 0; t <= amount; t++)
        {
            long take = 0, ntake;
            ntake = prev[t];
            if (t >= arr[i])
                take = curr[t - arr[i]];
            curr[t] = take + ntake;
        }
        prev = curr;
    }
    return prev[amount];
}