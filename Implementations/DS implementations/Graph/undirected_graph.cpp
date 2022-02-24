#include <iostream>
#include <list>
using namespace std;

class Graph
{
    int v; // vertices
    list<int> *adj;
    bool *visited = new bool[v];

public:
    Graph(int v)
    {
        this->v = v;
        adj = new list<int>[v];
        // reset();
    }

    void reset()
    {
        for (int i = 0; i < v; i++)
            visited[i] = false;
    }

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v);
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

    void markVisited(int v)
    {
        visited[v] = true;

        list<int>::iterator i;

        for (i = adj[v].begin(); i != adj[v].end(); ++i)
            if (!visited[*i])
                markVisited(*i);
    }

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

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 2);

    // Graph g(5);
    // g.addEdge(1, 0);
    // g.addEdge(2, 3);
    // g.addEdge(3, 4);

    // 0 ------> 1
    //           |
    //           |
    // 2         2

    g.reset();
    // cout << "Path exists between 2 to 3: " << g.hasPathRecursive(2, 3) << endl;
    // cout << "Path exists between 3 to 2: " << g.hasPathRecursive(3, 2) << endl;
    // cout << "Path exists between 3 to 3: " << g.hasPathRecursive(3, 3) << endl;

    // cout << "Path exists between 2 to 3: " << g.hasPath(2, 3) << endl;
    // cout << "Path exists between 3 to 2: " << g.hasPath(3, 2) << endl;
    // cout << "Path exists between 3 to 3: " << g.hasPath(3, 3) << endl;

    cout << "Path exists between 1 to 3: " << g.hasPathBFS(1, 3) << endl;
    cout << "Path exists between 2 to 4: " << g.hasPathBFS(2, 4) << endl;
    cout << "Path exists between 3 to 3: " << g.hasPathBFS(3, 3) << endl;

    g.reset();
    cout << "Path exists between 1 to 3: " << g.hasPathRecursive(1, 3) << endl;
    cout << "Path exists between 2 to 4: " << g.hasPathRecursive(2, 4) << endl;
    cout << "Path exists between 3 to 3: " << g.hasPathRecursive(3, 3) << endl;

    cout << "Path exists between 1 to 3: " << g.hasPath(1, 3) << endl;
    cout << "Path exists between 2 to 4: " << g.hasPath(2, 4) << endl;
    cout << "Path exists between 3 to 3: " << g.hasPath(3, 3) << endl;

    cout << "Number of Components: " << g.numComponents() << endl;

    cout << "Largest Component: " << g.largestComponent() << endl;

    cout << "Shortest Path edges from 0 to 2: " << g.shortestPathBFS(0, 2) << endl;
    cout << "Shortest Path edges from 3 to 0: " << g.shortestPathBFS(3, 1) << endl;
    cout << "Shortest Path edges from 3 to 3: " << g.shortestPathBFS(3, 3) << endl;

    return 0;
}