// int helper(int i, int j1, int j2, int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
// {
//     if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
//         return -1e9;
//     if (i == n - 1)
//     {
//         if (j1 == j2)
//             return grid[i][j1];
//         else
//             return grid[i][j1] + grid[i][j2];
//     }

//     if (dp[i][j1][j2] != -1)
//         return dp[i][j1][j2];

//     int mx = INT_MIN;
//     for (int di = -1; di <= 1; di++)
//     {
//         for (int dj = -1; dj <= 1; dj++)
//         {
//             int ans;
//             if (j1 == j2)
//             {
//                 ans = grid[i][j1] + helper(i + 1, j1 + di, j2 + dj, n, m, grid, dp);
//             }
//             else
//             {
//                 ans = grid[i][j1] + grid[i][j2] + helper(i + 1, j1 + di, j2 + dj, n, m, grid, dp);
//             }
//             mx = max(ans, mx);
//         }
//     }
//     return dp[i][j1][j2] = mx;
// }

// int maximumChocolates(int m, int n, vector<vector<int>> &grid)
// {
//     vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
//     return helper(0, 0, n - 1, m, n, grid, dp);
// }

// int maximumChocolates(int n, int m, vector<vector<int>> &grid)
// {
//     vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

//     for (int j1 = 0; j1 < m; j1++)
//     {
//         for (int j2 = 0; j2 < m; j2++)
//         {
//             if (j1 == j2)
//                 dp[n - 1][j1][j2] = grid[n - 1][j2];
//             else
//                 dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
//         }
//     }

//     for (int i = n - 2; i >= 0; i--)
//     {
//         for (int j1 = 0; j1 < m; j1++)
//         {
//             for (int j2 = 0; j2 < m; j2++)
//             {
//                 int mx = INT_MIN;
//                 for (int di = -1; di <= 1; di++)
//                 {
//                     for (int dj = -1; dj <= 1; dj++)
//                     {
//                         int ans;
//                         if (j1 == j2)
//                             ans = grid[i][j1];
//                         else
//                             ans = grid[i][j1] + grid[i][j2];

//                         if (j1 + di < 0 || j1 + di >= m || j2 + dj < 0 || j2 + dj >= m)
//                             ans += -1e9;
//                         else
//                             ans += dp[i + 1][j1 + di][j2 + dj];
//                         mx = max(ans, mx);
//                     }
//                 }
//                 dp[i][j1][j2] = mx;
//             }
//         }
//     }
//     return dp[0][0][m - 1];
// }

int maximumChocolates(int n, int m, vector<vector<int>> &grid)
{
    vector<vector<int>> next(m, vector<int>(m, 0));

    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
                next[j1][j2] = grid[n - 1][j2];
            else
                next[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        vector<vector<int>> curr(m, vector<int>(m, 0));
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int mx = INT_MIN;
                for (int di = -1; di <= 1; di++)
                {
                    for (int dj = -1; dj <= 1; dj++)
                    {
                        int ans;
                        if (j1 == j2)
                            ans = grid[i][j1];
                        else
                            ans = grid[i][j1] + grid[i][j2];

                        if (j1 + di < 0 || j1 + di >= m || j2 + dj < 0 || j2 + dj >= m)
                            ans += -1e9;
                        else
                            ans += next[j1 + di][j2 + dj];
                        mx = max(ans, mx);
                    }
                }
                curr[j1][j2] = mx;
            }
        }
        next = curr;
    }
    return next[0][m - 1];
}