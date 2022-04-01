#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph
{
    int V; // vertices
    list<int> *adj;
    bool *visited = new bool[V];

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
        // reset();
    }

    void reset()
    {
        for (int i = 0; i < V; i++)
            visited[i] = false;
    }

    void addEdge(int v, int u)
    {
        adj[v].push_back(u);
        // adj[u].push_back(v);
    }

    void printVector(vector<int> v)
    {
        for (auto x : v)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    vector<int> BFS()
    {
        vector<int> bfs;
        reset();

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                queue<int> queue;
                queue.push(i);
                visited[i] = true;

                while (!queue.empty())
                {
                    int node = queue.front();
                    bfs.push_back(node);
                    queue.pop();

                    for (auto v : adj[node])
                    {
                        if (!visited[v])
                        {
                            queue.push(v);
                            visited[v] = true;
                        }
                    }
                }
            }
        }
        reset();
        return bfs;
    }
};
