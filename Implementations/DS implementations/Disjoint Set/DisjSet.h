#include <iostream>
#include <vector>

using namespace std;

class DisjointSet
{
    int *rank, *parent;
    int n;

public:
    DisjointSet(int n)
    {
        rank = new int[n];
        parent = new int[n];
        this->n = n;
        makeSet();
    }

    void makeSet()
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int findPar(int i)
    {
        if (i == parent[i])
            return i;
        return parent[i] = findPar(parent[i]); // Path Compression
    }

    void Union(int u, int v)
    {
        u = findPar(u);
        v = findPar(v);

        if (rank[u] < rank[v])
            parent[u] = v;
        else if (rank[u] > rank[v])
            parent[v] = u;
        else
        {
            // any of the either can be assigned
            parent[v] = u;
            rank[u]++;
        }
    }
};