int minSubsetSumDifference(vector<int> &arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    int k = sum;

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
    int mini = 1e9;
    for (int i = 0; i <= sum; i++)
    {
        if (prev[i])
        {
            int diff = abs(i - (sum - i));
            mini = min(mini, diff);
        }
    }
    return mini;
}
