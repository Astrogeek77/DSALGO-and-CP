// int helper(int i, vector<int> &num, int x, vector<vector<int>> &dp)
// {
//     if (i == 0)
//     {
//         if (x % num[0] == 0)
//             return x / num[0];
//         else
//             return 1e9;
//     }

//     if (dp[i][x] != -1)
//         return dp[i][x];

//     int ntake = 0 + helper(i - 1, num, x, dp);
//     int take = INT_MAX;
//     if (num[i] <= x)
//         take = 1 + helper(i, num, x - num[i], dp);
//     return dp[i][x] = min(take, ntake);
// }
// int minimumElements(vector<int> &num, int x)
// {
//     int n = num.size();
//     vector<vector<int>> dp(n, vector<int>(x + 1, -1));
//     int ans = helper(n - 1, num, x, dp);
//     if (ans >= 1e9)
//         return -1;
//     return ans;
// }

// IMP incase of infinite supply/multiple uses statements in ques .
// IMP take condition is considered for same i multiple times with
// IMP  changed conditions.

// int minimumElements(vector<int> &num, int x)
// {
//     int n = num.size();
//     vector<vector<int>> dp(n, vector<int>(x + 1, 0));

//     for (int i = 0; i <= x; i++)
//     {
//         if (x % num[0] == 0)
//             dp[0][i] = x / num[0];
//         else
//             dp[0][i] = 1e9;
//     }

//     for (int i = 1; i < n; i++)
//     {
//         for (int c = 0; c <= x; c++)
//         {
//             int ntake = 0 + dp[i - 1][c];
//             int take = INT_MAX;
//             if (num[i] <= x)
//                 take = 1 + dp[i][c - num[i]];
//             dp[i][x] = min(take, ntake);
//         }
//     }

//     int ans = dp[n - 1][x];
//     if (ans >= 1e9)
//         return -1;
//     return ans;
// }

int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    vector<int> prev(x + 1, 0), curr(x + 1, 0);

    for (int i = 0; i <= x; i++)
    {
        if (i % num[0] == 0)
            prev[i] = i / num[0];
        else
            prev[i] = 1e9;
    }

    for (int i = 1; i < n; i++)
    {
        for (int c = 0; c <= x; c++)
        {
            int ntake = 0 + prev[c];
            int take = 1e9;
            if (num[i] <= c)
                take = 1 + curr[c - num[i]];
            curr[c] = min(take, ntake);
        }
        prev = curr;
    }

    int ans = prev[x];
    if (ans >= 1e9)
        return -1;
    return ans;
}