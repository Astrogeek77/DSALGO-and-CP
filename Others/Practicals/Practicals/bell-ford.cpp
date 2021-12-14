#include <bits/stdc++.h>
#define V 7
#define E 10
#define I INT_MAX
using namespace std;
int edges[][E] = {
    {1, 1, 1, 2, 3, 3, 4, 4, 5, 6},
    {2, 3, 4, 5, 2, 5, 3, 6, 7, 7},
    {3, 4, 5, 1, 1, 2, 2, 1, 3, 3}},
    dist[V + 1] = {I, 0, I, I, I, I, I, I};
unordered_map<int, string> mp = {
    {2, "Bebe Nanki Rd"},
    {3, "Dugri Rd"},
    {4, "Sua Rd"},
    {5, "Gill Rd"},
    {6, "GNE Entrance Way"},
    {7, "GNDEC"}};
int main()
{
    for (int i = 0; i < V - 1; i++)
    {
        bool changed = false;
        for (int j = 0; j < E; j++)
        {
            int u = edges[0][j], v = edges[1][j], weight = edges[2][j];
            if (dist[u] != I && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                changed = true;
            }
        }
        if (!changed)
            break;
    }
    for (int i = 2; i <= V; i++)
        cout << mp[i] << ": " << dist[i] << " km\n";
}