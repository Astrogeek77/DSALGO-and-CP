#include <iostream>
#include <list>
#include <vector>
#include <queue>
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
        // reset();

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
        reset();
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

    // TODO: check for Bipartite graph using DFS
    bool checkBiPartite1()
    {
        vector<int> color(v, -1);

        for (int i = 0; i < v; i++)
        {
            if (color[i] == -1)
                if (!checkBiPartiteBFS(i, color))
                    return false;
        }
        return true;
    }

    

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
