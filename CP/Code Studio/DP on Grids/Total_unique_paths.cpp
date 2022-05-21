// int dp[101][101];
// int solve(int m,int n){
// 	if(m<0 || n<0) return 0;
// 	if(m==0  || n==0) return 1;
// 	if(dp[m][n]> 0) return dp[m][n];
// 	else return dp[m][n]=solve(m-1,n) +solve(m,n-1); 
// }

// int uniquePaths(int m, int n) {
// 	return solve(m-1,n-1);
// }



// Tabulation
// int uniquePaths(int m, int n) {
// 	vector<vector<int>> dp(m, vector<int> (n, 0));
	
// 	dp[0][0] = 1;
// 	for(int i = 0; i < m; i++){
// 		for(int j = 0; j < n; j++){
// 			if(i == 0 and j == 0) continue;
// 			int up = 0, left = 0;
// 			if(i>0) up = dp[i - 1][j];
// 			if(j>0) left = dp[i][j-1];
// 			dp[i][j] = up + left;
// 		}
// 	}
// 	return dp[m-1][n-1];
// }



// Space optimization
int uniquePaths(int m, int n) {
	vector<int> prev(n, 0);
	
	prev[0] = 1;
	for(int i = 0; i < m; i++){
		vector<int> temp(n, 0);
		for(int j = 0; j < n; j++){
			if(i == 0 and j == 0) {
				temp[j] = 1;
				continue;
			}	
			int up = 0, left = 0;
			if(i>0) up = prev[j];
			if(j>0) left = temp[j - 1];
			temp[j] = up + left;
		}
		prev = temp;
	}
	return prev[n-1];
}