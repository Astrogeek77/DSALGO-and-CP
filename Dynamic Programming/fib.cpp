#include <iostream>
#include <vector>

using namespace std;

/*
    Memoization - Top Down DP - from other cese towards base cases
    Tabulation - Bottom Up DP - from base cases to other cases
*/

int fibmemo(int n, vector<int> &fib) // TC - O(n) and SC - O(n) + O(n) (memoization)
{
    if (n <= 1)
        return n;
    if (fib[n] != -1)
        return fib[n];
    return fib[n] = fibmemo(n - 1, fib) + fibmemo(n - 2, fib);
}

int fibtab(int n, vector<int> &dp) // (Tabulation)   TC - O(n) and SC - O(n)
{
    dp[0] = 0, dp[1] = 1; // we eliminated the recursion stack space here.

    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}

int fibtab2(int n) // (Tabulation)   TC - O(n) and SC - O(1)
{
    int prev2 = 0, prev = 1, curr; // here we eliminated the extra array space required completely.

    for (int i = 2; i <= n; i++)
    {
        curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    return curr;
}

int main()
{
    int n;
    cin >> n;
    vector<int> fib(n + 1, -1); // DP 1D array for memoization
    // memset(fib, -1, sizeof fib);
    cout << fibmemo(n, fib) << "\n";

    vector<int> fib2(n + 1, 0);
    cout << fibtab(n, fib2) << "\n";

    cout << fibtab2(n) << "\n";
}