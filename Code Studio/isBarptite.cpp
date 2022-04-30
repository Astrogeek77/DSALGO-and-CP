#include <bits/stdc++.h>
bool isbipartite(int node, vector<int> adj[], int color[])
{
    if (color[node] == -1)
        color[node] = 1;
    for (auto it : adj[node])
    {
        if (color[it] == -1)
        {
            color[it] = 1 - color[node];
            if (!isbipartite(it, adj, color))
                return false;
        }

        else if (color[it] == color[node])
            return false;
    }
    return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges)
{
    int n = edges[0].size();
    vector<int> adj[n];
    int color[n];
    memset(color, -1, sizeof color);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (edges[i][j] == 1)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (!isbipartite(i, adj, color))
                return false;
        }
    }

    return true;
}