// int helper(int i, int j, string &s, string &t, vector<vector<int>> &dp)
// {
//     // base case
//     if (j < 0)
//         return i + 1;
//     if (i < 0)
//         return j + 1;

//     // memoization
//     if (dp[i][j] != -1)
//         return dp[i][j];

//     // possibilities

//     // if Match, do nothing and strink the strings
//     if (s[i] == t[j])
//         return dp[i][j] = 0 + helper(i - 1, j - 1, s, t, dp);

//     else // no match =>
//     {

//         // insert
//         int ins = 1 + helper(i, j - 1, s, t, dp);

//         // delete
//         int del = 1 + helper(i - 1, j, s, t, dp);

//         // replace
//         int rep = 1 + helper(i - 1, j - 1, s, t, dp);

//         // best case
//         return dp[i][j] = min(ins, min(del, rep));
//     }
// }

// int editDistance(string s, string t)
// {
//     int n = s.size();
//     int m = t.size();
//     vector<vector<int>> dp(n, vector<int>(m, -1));
//     return helper(n - 1, m - 1, s, t, dp);
// }

// Tabulation

int editDistance(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++)
        dp[i][0] = i;
    for (int j = 0; j <= m; j++)
        dp[0][j] = j;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // if Match, do nothing and strink the strings
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 0 + dp[i - 1][j - 1];

            else // no match =>
            {

                // insert
                int ins = 1 + dp[i][j - 1];

                // delete
                int del = 1 + dp[i - 1][j];

                // replace
                int rep = 1 + dp[i - 1][j - 1];

                // best case
                dp[i][j] = min(ins, min(del, rep));
            }
        }
    }
    return dp[n][m];
}

// Space Optimization

int editDistance(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    // for (int i = 0; i <= n; i++)
    //     prev[0] = i;
    for (int j = 0; j <= m; j++)
        prev[j] = j;

    for (int i = 1; i <= n; i++)
    {
        curr[0] = i;
        for (int j = 1; j <= m; j++)
        {
            // if Match, do nothing and strink the strings
            if (s[i - 1] == t[j - 1])
                curr[j] = 0 + prev[j - 1];

            else // no match =>
            {

                // insert
                int ins = 1 + curr[j - 1];

                // delete
                int del = 1 + prev[j];

                // replace
                int rep = 1 + prev[j - 1];

                // best case
                curr[j] = min(ins, min(del, rep));
            }
        }
        prev = curr;
    }
    return prev[m];
}