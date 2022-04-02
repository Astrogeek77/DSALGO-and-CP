#include <iostream>
#include <list>
using namespace std;

class Graph
{
    int v; // vertices
    list<int> *adj;
    bool *visited = new bool[v];

public:
    // TODO: constructor
    Graph(int v)
    {
        this->v = v;
        adj = new list<int>[v];
        // reset();
    }

    // TODO: reseter for visited vector
    void reset()
    {
        for (int i = 0; i < v; i++)
            visited[i] = false;
    }

    // TODO: Util to add edges
    void addEdge(int v, int u)
    {
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    // TODO :  Check for cycle util for BFS
    bool checkCycleUtil(int s)
    {
        // vector<int> parent(V, -1);

        // Create a queue for BFS
        queue<pair<int, int>> q;

        visited[s] = true;
        q.push({s, -1});

        while (!q.empty())
        {

            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto it : adj[node])
            {
                if (!visited[it])
                {
                    visited[it] = true;
                    q.push({it, node});
                }
                else if (parent != it)
                    return true;
            }
        }
        return false;
    }

    // TODO: Check for cycle using BFS
    bool checkCycle()
    {
        reset();
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
                if (checkCycleUtil(i))
                    return true;
        }
        return false;
    }

    // TODO: check for cycle util using DFS
    bool checkCycleUtilDFS(int node, int parent)
    {
        visited[node] = true;
        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                if (checkCycleUtilDFS(it, parent))
                    return true;
            }
            else if (parent != it)
                return true;
        }
        return false;
    }

    // TODO: check for cycle using DFS
    bool checkCycle2()
    {
        reset();
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
                if (checkCycleUtilDFS(i, -1))
                    return true;
        }
        return false;
    }

    // TODO: Has Path using BFS
    bool hasPathBFS(int src, int dest)
    {
        reset();
        list<int> queue; // list behaving like a queue

        visited[src] = true;
        if (src == dest)
            return true;
        queue.push_back(src);

        list<int>::iterator i;

        while (!queue.empty())
        {
            src = queue.front();
            queue.pop_front();
            for (i = adj[src].begin(); i != adj[src].end(); i++)
            {
                if (*i == dest)
                    return true;
                if (!visited[*i])
                {
                    visited[*i] = true;
                    queue.push_back(*i);
                }
            }
        }
        return false;
    }

    // TODO: Has Path using DFS (Stack)
    bool hasPath(int src, int dest)
    {
        reset();

        list<int> stack; // list behaving like a stack

        visited[src] = true;
        if (src == dest)
            return true;
        stack.push_front(src);

        list<int>::iterator i;

        while (!stack.empty())
        {
            src = stack.front();
            stack.pop_front();

            for (i = adj[src].begin(); i != adj[src].end(); i++)
            {
                if (*i == dest)
                    return true;
                if (!visited[*i])
                {
                    visited[*i] = true;
                    stack.push_front(*i);
                }
            }
        }
        return false;
    }

    // TODO: Has Path using DFS (Recursion)
    bool hasPathRecursive(int src, int dest)
    {
        visited[src] = true;
        if (src == dest)
            return true;

        list<int>::iterator i;

        for (i = adj[src].begin(); i != adj[src].end(); i++)
        {
            if (!visited[*i])
                if (hasPathRecursive(*i, dest))
                    return true;
        }
        return false;
    }

    // TODO: Util to calculate Number of Components
    void markVisited(int v)
    {
        visited[v] = true;

        list<int>::iterator i;

        for (i = adj[v].begin(); i != adj[v].end(); ++i)
            if (!visited[*i])
                markVisited(*i);
    }

    // TODO: to calculate Number of Components
    int numComponents()
    {
        reset();
        int count = 0;

        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                markVisited(i);
                count++;
            }
        }
        return count;
    }

    // TODO:to Find the largest Component
    int largestComponent()
    {
        reset();
        int largest = 0;
        int size = 0;

        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                size = exploreSize(i);
                largest = max(largest, size);
            }
        }
        return largest;
    }

    // TODO: to find size of a component
    int exploreSize(int v)
    {
        visited[v] = true;
        int size = 1;

        list<int>::iterator i;

        for (i = adj[v].begin(); i != adj[v].end(); ++i)
            if (!visited[*i])
            {
                size += exploreSize(*i);
            }
        return size;
    }

    // TODO: Shortest Path using BFS
    int shortestPathBFS(int src, int dest)
    {
        reset();
        list<int> queue; // list behaving like a queue

        visited[src] = true;
        if (src == dest)
            return 0;
        queue.push_back(src);
        int count = 0;

        list<int>::iterator i;

        while (!queue.empty())
        {
            src = queue.front();
            queue.pop_front();
            for (i = adj[src].begin(); i != adj[src].end(); i++)
            {
                if (*i == dest)
                    return count;
                if (!visited[*i])
                {
                    visited[*i] = true;
                    queue.push_back(*i);
                    count++;
                }
            }
        }
        return -1;
    }
};