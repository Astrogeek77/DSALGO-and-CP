// int helper(int i, int n, vector<int> &arr, vector<vector<int>> &dp)
// {
//     if (i == 0)
//     {
//         return (n * arr[0]);
//     }
//     if (dp[i][n] != -1)
//         return dp[i][n];
//     int take = INT_MIN, ntake;
//     ntake = 0 + helper(i - 1, n, arr, dp);
//     int rodLength = i + 1;
//     if (n >= rodLength)
//         take = arr[i] + helper(i, n - rodLength, arr, dp);
//     return dp[i][n] = max(take, ntake);
// }

// int cutRod(vector<int> &price, int n)
// {
//     vector<vector<int>> dp(n, vector<int>(n + 1, -1));
//     return helper(n - 1, n, price, dp);
// }

int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    for (int i = 0; i <= n; i++)
        dp[0][i] = i * price[0];

    for (int i = 1; i < n; i++)
    {
        for (int N = 0; N <= n; N++)
        {
            int take = INT_MIN, ntake;
            ntake = 0 + dp[i - 1][N];
            int rodLength = i + 1;
            if (N >= rodLength)
                take = price[i] + dp[i][N - rodLength];
            dp[i][N] = max(take, ntake);
        }
    }
    return dp[n - 1][n];
}

int cutRod(vector<int> &price, int n)
{
    vector<int> prev(n + 1, 0), curr(n + 1, 0);
    for (int i = 0; i <= n; i++)
        prev[i] = i * price[0];

    for (int i = 1; i < n; i++)
    {
        for (int N = 0; N <= n; N++)
        {
            int take = INT_MIN, ntake;
            ntake = 0 + prev[N];
            int rodLength = i + 1;
            if (N >= rodLength)
                take = price[i] + curr[N - rodLength];
            curr[N] = max(take, ntake);
        }
        prev = curr;
    }
    return prev[n];
}

int cutRod(vector<int> &price, int n)
{
    vector<int> prev(n + 1, 0);
    for (int i = 0; i <= n; i++)
        prev[i] = i * price[0];

    for (int i = 1; i < n; i++)
    {
        for (int N = 0; N <= n; N++)
        {
            int take = INT_MIN, ntake;
            ntake = 0 + prev[N];
            int rodLength = i + 1;
            if (N >= rodLength)
                take = price[i] + prev[N - rodLength];
            prev[N] = max(take, ntake);
        }
    }
    return prev[n];
}
