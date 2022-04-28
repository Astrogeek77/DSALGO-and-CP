int mod = (int)(1e9 + 7);
// int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
// 	vector<vector<int>> dp(n, vector<int> (m, 0));
// 	for(int i = 0; i < n; i++){
// 		for(int j = 0; j < m; j++){
// 			if(i == 0 and j == 0) {
// 				dp[i][j] = 1;
// 				continue;
// 			}
// 			if(mat[i][j] == -1) {
// 				dp[i][j] = 0;
// 				continue;
// 			}
// 			int up = 0, left = 0;
// 			if(i>0) up = dp[i - 1][j];
// 			if(j>0) left = dp[i][j-1];
// 			dp[i][j] = (up + left) % mod;
// 		}
// 	}
// 	return dp[n-1][m-1];
//  }

int mazeObstacles(int n, int m, vector<vector<int>> &mat)
{
    vector<int> prev(n, 0);
    for (int i = 0; i < n; i++)
    {
        vector<int> curr(m, 0);
        for (int j = 0; j < m; j++)
        {
            if (i == 0 and j == 0)
            {
                curr[j] = 1;
                continue;
            }
            if (mat[i][j] == -1)
            {
                curr[j] = 0;
                continue;
            }
            int up = 0, left = 0;
            if (i > 0)
                up = prev[j];
            if (j > 0)
                left = curr[j - 1];
            curr[j] = (up + left) % mod;
        }
        prev = curr;
    }
    return prev[m - 1];
}
