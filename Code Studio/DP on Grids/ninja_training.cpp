// int helper(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp){
// 	if(dp[day][last] != -1) return dp[day][last];

// 	if(day == 0){
// 		int mx = 0;
// 		for(int i = 0; i < 3; i++){
// 			if(i != last){
// 				mx = max(mx, points[day][i]);
// 			}
// 		}
// 		return mx;
// 	}

// 	int mx = 0;
// 	for(int i = 0; i < 3; i++){
// 		if(i != last){
// 			int pts = points[day][i] + helper(day - 1, i, points, dp);
// 			mx = max(mx, pts);
// 		}
// 	}
// 	return dp[day][last] = mx;
// }

// int ninjaTraining(int n, vector<vector<int>> &points)
// {
// 	vector<vector<int>> dp(n, vector<int>(4, -1));
// 	return helper(n - 1, 3, points, dp);
// }

// Tabulation
// int ninjaTraining(int n, vector<vector<int>> &points)
// {
// 	vector<vector<int>> dp(n, vector<int>(4, 0));
// 	dp[0][0] = max(points[0][1], points[0][2]);
// 	dp[0][1] = max(points[0][0], points[0][2]);
// 	dp[0][2] = max(points[0][0], points[0][1]);
// 	dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

// 	for(int day = 1; day < n; day++){
// 		for(int last = 0; last < 4; last++) {
// 			dp[day][last] = 0;
// 			int mx = 0;
// 			for(int task = 0; task < 3; task++){
// 				if(task != last){
// 					int pts = points[day][task] + dp[day - 1][task];
// 					mx = max(mx, pts);
// 					dp[day][last] = mx;
// 				}
// 			}
// 		}
// 	}
// 	return dp[n - 1][3];
// }

// Space Optimization - Tabulation
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> prev(4, 0);
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

    vector<int> temp(4, 0);
    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            int mx = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int pts = points[day][task] + prev[task];
                    mx = max(mx, pts);
                    temp[last] = mx;
                }
            }
        }
        prev = temp;
    }
    return prev[3];
}