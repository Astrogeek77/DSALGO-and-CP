#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <stack>
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
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }

    // TODO: util to print a given vector
    void printVector(vector<int> v)
    {
        for (auto x : v)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    // TODO: Breath First Traversal/Search of a Graph
    void BFS(int s)
    {
        // vector<int> bfs[v];
        // Mark all the vertices as not visited
        reset();

        // Create a queue for BFS
        list<int> queue; // list behaving like a queue

        visited[s] = true;
        queue.push_back(s);

        // 'i' will be used to get all adjacent
        // vertices of a vertex
        list<int>::iterator i;

        while (!queue.empty())
        {
            // Dequeue a vertex from queue and print it
            s = queue.front();
            cout << s << " ";
            queue.pop_front();

            // Get all adjacent vertices of the dequeued
            // vertex s. If a adjacent has not been visited,
            // then mark it visited and enqueue it
            for (i = adj[s].begin(); i != adj[s].end(); ++i)
            {
                if (!visited[*i])
                {
                    visited[*i] = true;
                    queue.push_back(*i);
                }
            }
        }
        reset();
    }

    // TODO: Depth First Traversal/Search of a Graph
    void DFS(int start)
    {
        reset();
        list<int> stack; // list behaving like a stack

        visited[start] = true;
        stack.push_front(start);

        list<int>::iterator i;

        while (!stack.empty())
        {
            start = stack.front();
            cout << start << " ";
            stack.pop_front();

            for (i = adj[start].begin(); i != adj[start].end(); i++)
            {
                if (!visited[*i])
                {
                    visited[*i] = true;
                    stack.push_front(*i);
                }
            }
        }
    }

    // TODO: Depth First Recursive Traversal of a graph
    void DFSRecursive(int start)
    {
        visited[start] = true;
        cout << start << " ";

        list<int>::iterator i;

        for (i = adj[start].begin(); i != adj[start].end(); i++)
        {
            if (!visited[*i])
                DFSRecursive(*i);
        }
    }

    // TODO: check for Bipartite graph util using BFS
    bool checkBiPartiteBFS(int s, vector<int> &color)
    {
        color[s] = 1;

        queue<int> q;
        q.push(s);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto it : adj[node])
            {
                if (color[it] == -1)
                {
                    color[it] = 1 - color[node];
                    q.push(it);
                }
                else if (color[it] == color[node])
                    return false;
            }
        }
        return true;
    }

    // TODO: check for Bipartite graph using BFS
    bool checkBiPartite1()
    {
        reset();
        vector<int> color(v, -1);

        for (int i = 0; i < v; i++)
        {
            if (color[i] == -1)
                if (!checkBiPartiteBFS(i, color))
                    return false;
        }
        return true;
    }

    // TODO: check for Bipartite graph util using DFS
    bool checkBiPartiteDFS(int node, vector<int> &color)
    {
        color[node] = 1;
        for (auto it : adj[node])
        {
            if (color[it] == -1)
            {
                color[it] = 1 - color[node];
                if (!checkBiPartiteDFS(it, color))
                    return false;
            }
            else if (color[it] == color[node])
                return false;
        }
        return true;
    }

    // TODO: check for Bipartite graph using DFS
    bool checkBiPartite2()
    {
        reset();
        vector<int> color(v, -1);

        for (int i = 0; i < v; i++)
        {
            if (color[i] == -1)
                if (!checkBiPartiteDFS(i, color))
                    return false;
        }
        return true;
    }

    // TODO Util for Topological Sort using DFS
    void topSort1(int node, stack<int> &stack)
    {
        visited[node] = true;

        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                topSort1(it, stack);
            }
        }
        stack.push(node);
    }

    // TODO Topological Sort using DFS
    void TopologicalSortDFS()
    {
        // ! Only Possible in DAGs
        reset();
        vector<int> topSort;
        stack<int> stack;

        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                topSort1(i, stack);
            }
        }

        while (!stack.empty())
        {
            topSort.push_back(stack.top());
            stack.pop();
        }
        printVector(topSort);
    }

    // TODO Topological Sort using BFS
    void topSortBFS()
    {
        reset();
        vector<int> inDegree(v, 0);
        vector<int> topSort;
        queue<int> q;

        for (int i = 0; i < v; i++)
        {
            for (auto it : adj[i])
                inDegree[it]++;
        }

        for (int i = 0; i < v; i++)
        {
            if (inDegree[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topSort.push_back(node);

            for (auto it : adj[node])
            {
                inDegree[it]--;
                if (inDegree[it] == 0)
                    q.push(it);
            }
        }
        printVector(topSort);
    }

    bool checkCycle(){}

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
            if (src == dest)
                return true;
            stack.pop_front();

            for (i = adj[src].begin(); i != adj[src].end(); i++)
            {
                if (!visited[*i])
                {
                    visited[*i] = true;
                    stack.push_front(*i);
                }
            }
        }
        return false;
    }

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
            if (src == dest)
                return true;

            for (i = adj[src].begin(); i != adj[src].end(); i++)
            {
                if (!visited[*i])
                {
                    visited[*i] = true;
                    queue.push_back(*i);
                }
            }
        }
        return false;
    }

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
