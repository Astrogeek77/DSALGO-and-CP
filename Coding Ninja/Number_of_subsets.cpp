// int helper(int i, int k, vector<int> &arr, vector<vector<int>> &dp)
// {
//     if (k == 0)
//         return 1;
//     if (i == 0)
//         return (k == arr[0]);

//     if (dp[i][k] != -1)
//         return dp[i][k];

//     int take = 0, ntake;
//     ntake = helper(i - 1, k, arr, dp);
//     if (k >= arr[i])
//         take = helper(i - 1, k - arr[i], arr, dp);
//     return dp[i][k] = (take + ntake);
// }

// int findWays(vector<int> &nums, int tar)
// {
//     int n = nums.size();
//     vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
//     return helper(n - 1, tar, nums, dp);
// }

// int findWays(vector<int> &arr, int k)
// {
//     int n = arr.size();
//     vector<vector<int>> dp(n, vector<int>(k + 1, 0));

//     for (int i = 0; i < n; i++)
//         dp[i][0] = 1;

//     if (arr[0] <= k)
//         dp[0][arr[0]] = 1;

//     for (int ind = 1; ind < n; ind++)
//     {
//         for (int tar = 0; tar <= k; tar++)
//         {
//             int take = 0, ntake;
//             ntake = dp[ind - 1][tar];

//             if (tar >= arr[ind])
//                 take = dp[ind - 1][tar - arr[ind]];
//             dp[ind][tar] = take + ntake;
//         }
//     }
//     return dp[n - 1][k];
// }

int findWays(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> prev(k + 1, 0), curr(k + 1, 0);

    for (int i = 0; i < n; i++)
        prev[0] = 1;

    if (arr[0] <= k)
        prev[arr[0]] = 1;

    for (int ind = 1; ind < n; ind++)
    {
        curr[0] = 1;
        for (int tar = 0; tar <= k; tar++)
        {
            int take = 0, ntake;
            ntake = prev[tar];

            if (tar >= arr[ind])
                take = prev[tar - arr[ind]];
            curr[tar] = take + ntake;
        }
        prev = curr;
    }
    return prev[k];
}

// IMP Change for cases like {0, 0, 1} with req sum 1;

// Reouccurence + Memoization

// int helper(int i, int k, vector<int> &arr, vector<vector<int>> &dp)
// {

//     if (i == 0)
//     {
//         if (nums[i] == 0 and k == 0)
//             return 2;
//         if (k == 0 || k == nums[0])
//             return 1;
//         return 0;
//     }

//     if (dp[i][k] != -1)
//         return dp[i][k];

//     int take = 0, ntake;
//     ntake = helper(i - 1, k, arr, dp);
//     if (k >= arr[i])
//         take = helper(i - 1, k - arr[i], arr, dp);
//     return dp[i][k] = (take + ntake);
// }

// int findWays(vector<int> &nums, int tar)
// {
//     int n = nums.size();
//     vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
//     return helper(n - 1, tar, nums, dp);
// }

// Tabulation

// int findWays(vector<int> &arr, int k)
// {
//     int n = arr.size();
//     vector<vector<int>> dp(n, vector<int>(k + 1, 0));

//     if (arr[0] == 0)
//         dp[0][0] = 2;
//     else
//         dp[0][0] = 1;

//     if (arr[0] != 0 and arr[0] <= k)
//         dp[0][arr[0]] = 1;

//     for (int ind = 1; ind < n; ind++)
//     {
//         for (int tar = 0; tar <= k; tar++)
//         {
//             int take = 0, ntake;
//             ntake = dp[ind - 1][tar];

//             if (tar >= arr[ind])
//                 take = dp[ind - 1][tar - arr[ind]];
//             dp[ind][tar] = take + ntake;
//         }
//     }
//     return dp[n - 1][k];
// }

int findWays(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> prev(k + 1, 0), curr(k + 1, 0);

    if (nums[i] == 0)
        prev[0] = 2;
    else
        prev[0] = 1;

    if (arr[0] != 0 and arr[0] <= k)
        prev[arr[0]] = 1;

    for (int ind = 1; ind < n; ind++)
    {
        curr[0] = 1;
        for (int tar = 0; tar <= k; tar++)
        {
            int take = 0, ntake;
            ntake = prev[tar];

            if (tar >= arr[ind])
                take = prev[tar - arr[ind]];
            curr[tar] = take + ntake;
        }
        prev = curr;
    }
    return prev[k];
}