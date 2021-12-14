#include <bits/stdc++.h>
using namespace std;
int main()
{
    int P[] = {0, 1, 2, 5, 6},
        wt[] = {0, 2, 3, 4, 5},
        m = 8, n = 4, k[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= m; w++)
        {
            if (i == 0 || w == 0)
                k[i][w] = 0;
            else if (wt[i] <= w)
                k[i][w] = max(k[i - 1][w], k[i - 1][w - wt[i]] +
                                               P[i]);
            else
                k[i][w] = k[i - 1][w];
        }
    }
    cout << "Maximum possible value = Rs. " << k[n][m] << " ... with:\n\n";
    for (int i = n, j = m; i > 0 && j >= 0; i--)
    {
        if (k[i][j] == k[i - 1][j])
            cout << "Object " << i << "-> NOT included\n";
        else
        {
            cout << "Object " << i << "-> Included\n";
            j -= wt[i];
        }
    }
}
