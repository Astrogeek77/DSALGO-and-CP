#include <bits/stdc++.h>
using namespace std;

int f(int i, vector<int> &heights, vector<int> &dp, int k) // TC - O(n * k) and SC - O(2 * n)
{
    if (i == 0)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int minSteps = INT_MAX;

    for (int j = 1; j <= k; j++)
    {
        if (i - j < 0)
            break;
        int ithJump = f(i - j, heights, dp, k) + abs(heights[i] - heights[i - j]);
        minSteps = min(minSteps, ithJump);
    }

    return dp[i] = minSteps;

    // int firstJump = f(i - 1, heights, dp) + abs(heights[i] - heights[i - 1]);
    // int secondJump = INT_MAX;
    // if (i > 1)
    //     secondJump = f(i - 2, heights, dp) + abs(heights[i] - heights[i - 2]);

    // return dp[i] = min(firstJump, secondJump);
}

int frogTab(vector<int> &heights, vector<int> &dp, int k) // TC - O(n * k) and SC - O(n)
{
    dp[0] = 0;
    int n = heights.size();

    for (int i = 1; i < n; i++)
    {
        int minSteps = INT_MAX;
        if (dp[i] != -1)
            return dp[i];

        for (int j = 1; j <= k; j++)
        {
            if (i - j < 0)
                break;
            int ithJump = f(i - j, heights, dp, k) + abs(heights[i] - heights[i - j]);
            minSteps = min(minSteps, ithJump);
        }
        dp[i] = minSteps;
    }
    return dp[n - 1];
}

int main()
{
    int k = 3;
    // vector<int> heights = {30, 10, 60, 10, 60, 50};
    vector<int> heights = {10, 30, 40, 50, 20};
    // vector<int> heights = {40, 10, 20, 70, 80, 10, 20, 70, 80, 60};
    int n = heights.size();
    vector<int> dp(n, -1);
    cout << f(n - 1, heights, dp, k) << "\n";
    vector<int> dp2(n, -1);
    cout << frogTab(heights, dp2, k) << "\n";
}
