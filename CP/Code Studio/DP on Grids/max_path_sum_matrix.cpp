// int helper(int i, int j, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp){
// 	if(j < 0 || j >= m) return -1e9;
// 	if(i == 0) return matrix[0][j];

// 	if(dp[i][j] != -1) return dp[i][j];

// 	int up = matrix[i][j] + helper(i - 1, j, m, matrix, dp);
// 	int Rdiag = matrix[i][j] + helper(i - 1, j + 1, m, matrix, dp);
// 	int Ldiag = matrix[i][j] + helper(i - 1, j - 1, m, matrix, dp);

// 	return dp[i][j] = max(up, max(Ldiag, Rdiag));
// }

// int getMaxPathSum(vector<vector<int>> &matrix)
// {
// 	int n = matrix.size();
//     int m = matrix[0].size();

// 	vector<vector<int>> dp(n, vector<int> (m, -1));

// 	int maxi = -1e9;
//     for(int j=0; j<m;j++){
//         int ans = helper(n-1, j, m, matrix, dp);
//         maxi = max(maxi,ans);
//     }
// 	return maxi;
// }

// int getMaxPathSum(vector<vector<int>> &matrix)
// {
// 	int n = matrix.size();
//     int m = matrix[0].size();

// 	vector<vector<int>> dp(n, vector<int> (m, 0));

// 	for(int j=0; j<m; j++){
//         dp[0][j] = matrix[0][j];
//     }

// 	for(int i = 1; i < n; i++){
// 		for(int j = 0; j < m; j++){

// 			int up = matrix[i][j] + dp[i - 1][j];
// 			int Rdiag = matrix[i][j], Ldiag = matrix[i][j];

// 			Ldiag += (j-1) >= 0 ? dp[i - 1][j - 1] : -1e9;
// 			Rdiag += (j+1) < m ? dp[i - 1][j + 1] : -1e9;
// 			dp[i][j] = max(up, max(Ldiag, Rdiag));
// 		}
// 	}
// 	int maxi = -1e9;
//     for(int j=0; j<m;j++){
//         int ans = dp[n-1][j];
//         maxi = max(maxi,ans);
//     }
// 	return maxi;
// }

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> prev(m, 0);

    for (int j = 0; j < m; j++)
    {
        prev[j] = matrix[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        vector<int> curr(m, 0);
        for (int j = 0; j < m; j++)
        {

            int up = matrix[i][j] + prev[j];
            int Rdiag = matrix[i][j], Ldiag = matrix[i][j];

            Ldiag += (j - 1) >= 0 ? prev[j - 1] : -1e9;
            Rdiag += (j + 1) < m ? prev[j + 1] : -1e9;
            curr[j] = max(up, max(Ldiag, Rdiag));
        }
        prev = curr;
    }
    int maxi = -1e9;
    for (int j = 0; j < m; j++)
    {
        int ans = prev[j];
        maxi = max(maxi, ans);
    }
    return maxi;
}