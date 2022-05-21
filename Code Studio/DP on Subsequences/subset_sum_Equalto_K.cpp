// bool helper(int i, int k, vector<int> &arr, vector<vector<int>> &dp){
// 	if(k == 0) return true;
// 	if(i == 0) return (k == arr[0]);

// 	if(dp[i][k] != -1) return dp[i][k];

// 	bool take = false, ntake;
// 	ntake = helper(i - 1, k, arr, dp);
// 	if(k >= arr[i]) take = helper(i - 1, k - arr[i], arr, dp);
// 	return dp[i][k] = (take || ntake);
// }

// bool subsetSumToK(int n, int k, vector<int> &arr) {
// 	vector<vector<int>> dp(n, vector<int> (k+1, -1));
//     return helper(n - 1, k, arr, dp);
// }

// bool subsetSumToK(int n, int k, vector<int> &arr)
// {
//     vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));

//     for (int i = 0; i < n; i++)
//         dp[i][0] = true;
//     if (arr[0] <= k)
//         dp[0][arr[0]] = true;

//     for (int i = 1; i < n; i++)
//     {
//         for (int t = 1; t <= k; t++)
//         {
//             bool take = false, ntake;
//             ntake = dp[i - 1][t];
//             if (t >= arr[i])
//                 take = dp[i - 1][t - arr[i]];
//             dp[i][t] = (take | ntake);
//         }
//     }
//     return dp[n - 1][k];
// }

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<bool> prev(k + 1, false), curr(k + 1, false);

    for (int i = 0; i < n; i++)
        prev[0] = true;
    if (arr[0] <= k)
        prev[arr[0]] = true;

    for (int i = 1; i < n; i++)
    {
        curr[0] = true;
        for (int t = 1; t <= k; t++)
        {
            bool take = false, ntake;
            ntake = prev[t];
            if (t >= arr[i])
                take = prev[t - arr[i]];
            curr[t] = (take || ntake);
        }
        prev = curr;
    }
    return prev[k];
}