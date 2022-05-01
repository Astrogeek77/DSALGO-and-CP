int lcs(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Print LCS;

    int len = dp[n][m];
    int i = n;
    int j = m;
    int idx = len - 1;

    string str = "";
    for(int i = 0; i < len; i++)
        str += "$"; // dummy values

    while(i > 0 and j > 0){
        if(s[i-1] == t[j - 1]) {
            str[idx] = s[i - 1];
            idx--;
            i--;
            j--;
        }
        else if (s[i-1] > t[j-1])
            i--;
        else
            j--;
    }
    return str;
}