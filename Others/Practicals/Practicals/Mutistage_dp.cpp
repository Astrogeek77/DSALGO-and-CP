#include <bits/stdc++.h>
using namespace std;
int main()
{
    int stages = 4, n = 8, cost[n + 1], d[n + 1], path[stages + 1],
        c[n + 1][n + 1] = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 2, 1, 3, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 2, 3, 0, 0},
            {0, 0, 0, 0, 0, 6, 7, 0, 0},
            {0, 0, 0, 0, 0, 6, 8, 9, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 6},
            {0, 0, 0, 0, 0, 0, 0, 0, 4},
            {0, 0, 0, 0, 0, 0, 0, 0, 5}};
    cost[n] = 0;
    for (int i = n - 1; i > 0; i--)
    {
        int min = INT_MAX;
        for (int k = i + 1; k <= n; k++)
        {
            if (c[i][k] != 0 && c[i][k] + cost[k] < min)
            {
                min = c[i][k] + cost[k];
                d[i] = k;
            }
        }
        cost[i] = min;
    }
    path[1] = 1;
    path[stages] = n;
    for (int i = 2; i < stages; i++)
        path[i] = d[path[i - 1]];
    cout << "Shortest path of the MultiStage graph:\n";
    for (int i = 1; i <= stages; i++)
        cout << path[i] << "\t";
}
