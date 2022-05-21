int helper(int i, vector<int> &wt, vector<int> &val, int w, vector<vector<int>> &dp){
	if(i == 0) {
		if(wt[0] <= w) return val[0];
		else return 0;
	}

	if(dp[i][w] != -1) return dp[i][w];

	int ntake = 0 + helper(i - 1, wt, val, w, dp);
	int take = INT_MIN;
	if(wt[i] <= w) take = val[i] + helper(i - 1, wt, val, w - wt[i], dp);
	return dp[i][w] = max(take, ntake);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
	int m = weight.size();

	vector<vector<int>> dp(n, vector<int> (maxWeight + 1, -1));
	return helper(n-1, weight, value, maxWeight, dp);
}

int knapsack(vector<int> wt, vector<int> val, int n, int W)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    for (int i = wt[0]; i <= W; i++)
        dp[0][i] = val[0];

    for (int ind = 1; ind < n; ind++)
    {
        for (int w = 0; w <= W; w++)
        {
            int ntake = 0 + dp[ind - 1][w];
            int take = INT_MIN;
            if (wt[ind] <= w)
                take = val[ind] + dp[ind - 1][w - wt[ind]];
            dp[ind][w] = max(take, ntake);
        }
    }
    return dp[n - 1][W];
}

int knapsack(vector<int> wt, vector<int> val, int n, int W)
{
    vector<int> prev(W + 1, 0), curr(W + 1, 0);

    for (int i = wt[0]; i <= W; i++)
        prev[i] = val[0];

    for (int ind = 1; ind < n; ind++)
    {
        for (int w = 0; w <= W; w++)
        {
            int ntake = 0 + prev[w];
            int take = INT_MIN;
            if (wt[ind] <= w)
                take = val[ind] + prev[w - wt[ind]];
            curr[w] = max(take, ntake);
        }
        prev = curr;
    }
    return prev[W];
}

int knapsack(vector<int> wt, vector<int> val, int n, int W)
{
    vector<int> prev(W + 1, 0);

    for (int i = wt[0]; i <= W; i++)
        prev[i] = val[0];

    for (int ind = 1; ind < n; ind++)
    {
        for (int w = W; w >= 0; w--)
        {
            int ntake = 0 + prev[w];
            int take = INT_MIN;
            if (wt[ind] <= w)
                take = val[ind] + prev[w - wt[ind]];
            prev[w] = max(take, ntake);
        }
    }
    return prev[W];
}