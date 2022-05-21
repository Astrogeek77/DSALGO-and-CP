#include <bits/stdc++.h>
// int f(int i, vector<int> &heights, vector<int> &dp){
// 	if( i == 0) return 0;
// 	if(dp[i] != -1) return dp[i];

// 	int firstJump = f(i - 1, heights, dp) + abs(heights[i] - heights[i - 1]);
// 	int secondJump = INT_MAX;
// 	if( i > 1) secondJump = f(i - 2, heights, dp) + abs(heights[i] - heights[i - 2]);

// 	return dp[i] = min(firstJump, secondJump);
// }

int frogJump(int n, vector<int> &heights)
{
    //  vector<int> dp(n + 1, -1);
    // 	f(n - 1, heights, dp);

    // 	vector<int> dp(n, 0);
    // 	dp[0] = 0;
    // 	for(int i = 1; i < n; i++){
    // 		int firstJump = dp[i - 1] + abs(heights[i] - heights[ i-1]);
    // 		int secondJump = INT_MAX;
    // 		if(i > 1) secondJump = dp[i - 2] + abs(heights[i] - heights[i-2]);
    // 		dp[i] = min(firstJump, secondJump);
    // 	}
    // 	return dp[n - 1];

    int prev = 0, prev1 = 0, curr;
    for (int i = 1; i < n; i++)
    {
        int fs = prev + abs(heights[i] - heights[i - 1]);
        int ss = INT_MAX;
        if (i > 1)
            ss = prev1 + abs(heights[i] - heights[i - 2]);
        curr = min(fs, ss);
        prev1 = prev;
        prev = curr;
    }
    return curr;
}