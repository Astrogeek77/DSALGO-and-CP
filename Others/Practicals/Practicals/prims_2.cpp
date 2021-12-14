include<bits / stdc++.h>
using namespace std;

#define I INT_MAX

int cost[][7] = {
    {I, I, I, I, I, I, I},
    {I, I, 4, 4, I, I, I},
    {I, 4, I, 2, I, I, I},
    {I, 4, 2, I, 3, 2, 4},
    {I, I, I, 3, I, I, 3},
    {I, I, I, 2, I, I, 3},
    {I, I, I, 4, 3, 3, I}};
int near[7] = {I, I, I, I, I, I, I};
int t[2][5];
unordered_map<int, string> mp = {
    {1, "Ludhiana"},
    {2, "Jalandhar"},
    {3, "Patiala"},
    {4, "Amritsar"},
    {5, "Mansa"},
    {6, "Sangrur"}};
int main()
{
    int i = 2, j, k, u = 1, v, n = 6, min = I;
    while (i <= n)
    {
        if (min > cost[u][i])
        {
            v = i;
            min = cost[u][v];
        }
        i++;
    }
    t[0][0] = u;
    t[1][0] = v;
    near[u] = near[v] = 0;
    for (i = 1; i <= n; i++)
    {
        if (near[i] != 0)
        {
            if (cost[i][u] < cost[i][v])
                near[i] = u;
            else
                near[i] = v;
        }
    }
    for (i = 1; i < n - 1; i++)
    {
        min = I;
        for (j = 1; j <= n; j++)
        {
            if (near[j] != 0 && cost[j][near[j]] < min)
            {
                k = j;
                min = cost[j][near[j]];
            }
        }
        t[0][i] = k;
        t[1][i] = near[k];
        near[k] = 0;
        for (j = 1; j <= n; j++)
            if (near[j] != 0 && cost[j][k] < cost[j][near[j]])
                near[j] = k;
    }
    int minCost = 0;
    for (i = 0; i < n - 1; i++)
    {
        cout << mp[t[0][i]] << " <-> " << mp[t[1][i]] << "
            ("<<cost[t[0][i]][t[1][i]]<<" km)\n ";
            minCost += cost[t[0][i]][t[1][i]];
    }
    cout << "\nMinimum Cost is " << minCost << " km.";
}