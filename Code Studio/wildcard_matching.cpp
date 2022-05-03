// #include <bits/stdc++.h>
// bool helper(int i, int j, string &s, string &t, vector<vector<int>> &dp)
// {
//     // base cases
//     if (i < 0 and j < 0)
//         return true;
//     if (i < 0 and j >= 0)
//         return false;
//     if (j < 0 and i >= 0)
//     {
//         for (int k = 0; k <= i; k++)
//             if (s[k] != '*')
//                 return false;
//         return true;
//     }

//     // memoize
//     if (dp[i][j] != -1)
//         return dp[i][j];

//     // all possibilties
//     if (s[i] == t[j] || s[i] == '?')
//         return dp[i][j] = helper(i - 1, j - 1, s, t, dp);
//     else if (s[i] == '*')
//         return dp[i][j] = helper(i - 1, j, s, t, dp) | helper(i, j - 1, s, t, dp);
//     else
//         return dp[i][j] = false;

//     // take the best - > poosibilities
// }

// bool wildcardMatching(string s, string t)
// {
//     int n = s.size();
//     int m = t.size();
//     vector<vector<int>> dp(n, vector<int>(m, -1));
//     return helper(n - 1, m - 1, s, t, dp);
// }

// Shifted Index  to avoid negitive indexing

#include <bits/stdc++.h>
bool helper(int i, int j, string &s, string &t, vector<vector<int>> &dp)
{
    // base cases
    if (i == 0 and j == 0)
        return true;
    if (i == 0 and j > 0)
        return false;
    if (j == 0 and i > 0)
    {
        for (int k = 1; k <= i; k++)
            if (s[k - 1] != '*')
                return false;
        return true;
    }

    // memoize
    if (dp[i][j] != -1)
        return dp[i][j];

    // all possibilties
    if (s[i - 1] == t[j - 1] || s[i - 1] == '?')
        return dp[i][j] = helper(i - 1, j - 1, s, t, dp);
    else if (s[i - 1] == '*')
        return dp[i][j] = helper(i - 1, j, s, t, dp) | helper(i, j - 1, s, t, dp);
    else
        return dp[i][j] = false;

    // take the best - > poosibilities
}

bool wildcardMatching(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return helper(n, m, s, t, dp);
}

// Tabulation

#include <bits/stdc++.h>

bool wildcardMatching(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    dp[0][0] = true;
    for (int j = 1; j <= m; j++)
        dp[0][j] = false;
    for (int i = 1; i <= n; i++)
    {
        bool flag = true;
        for (int k = 1; k <= i; k++)
        {
            if (s[k - 1] != '*')
            {
                flag = false;
                break;
            }
        }
        dp[i][0] = flag;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // all possibilties
            if (s[i - 1] == t[j - 1] || s[i - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];
            else if (s[i - 1] == '*')
                dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
            else
                dp[i][j] = false;
        }
    }
    // return the result - > poosibilities
    return dp[n][m];
}

// Space Optimization

#include <bits/stdc++.h>

bool wildcardMatching(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    prev[0] = true;

    // for (int j = 1; j <= m; j++)
    //     prev[j] = false;

    for (int i = 1; i <= n; i++)
    {
        bool flag = true;
        for (int k = 1; k <= i; k++)
        {
            if (s[k - 1] != '*')
            {
                flag = false;
                break;
            }
        }
        curr[0] = flag;
        for (int j = 1; j <= m; j++)
        {
            // all possibilties
            if (s[i - 1] == t[j - 1] || s[i - 1] == '?')
                curr[j] = prev[j - 1];
            else if (s[i - 1] == '*')
                curr[j] = prev[j] | curr[j - 1];
            else
                curr[j] = false;
        }
        prev = curr;
    }
    // return the result - > poosibilities
    return prev[m];
}