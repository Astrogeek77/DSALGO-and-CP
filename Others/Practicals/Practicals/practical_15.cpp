#include <bits/stdc++.h>
using namespace std;
int v = 14;
vector<vector<int>> graph(v);
vector<bool> visited(v, false);
void addEdge(int x, int y)
{
    graph[x].push_back(y);
    graph[y].push_back(x);
}
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    while (!q.empty())
    {
        int x = q.front();
        cout << x << "\t";
        q.pop();
        for (int &v : graph[x])
        {
            if (!visited[v])
            {
                q.push(v);
                visited[v] = true;
            }
        }
    }
}
int main()
{
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(0, 3);
    addEdge(1, 4);
    addEdge(1, 5);
    addEdge(2, 6);
    addEdge(2, 7);
    addEdge(3, 8);
    addEdge(8, 9);
    addEdge(8, 10);
    addEdge(9, 11);
    addEdge(9, 12);
    addEdge(9, 13);
    cout << "BFS traversal of the graph:\n";
    bfs(0);
}