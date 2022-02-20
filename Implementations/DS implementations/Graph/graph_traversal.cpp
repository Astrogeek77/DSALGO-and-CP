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
    }

    void BFS(int start)
    {
        list<int> queue; // list behaving like a queue

        visited[start] = true;
        queue.push_back(start);

        list<int>::iterator i;

        while (!queue.empty())
        {
            start = queue.front();
            cout << start << " ";
            queue.pop_front();

            for (i = adj[start].begin(); i != adj[start].end(); i++)
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
};

int main()
{
    // Graph g(4);
    // g.addEdge(0, 1);
    // g.addEdge(0, 2);
    // g.addEdge(1, 2);
    // g.addEdge(2, 0);
    // g.addEdge(2, 3);
    // g.addEdge(3, 3);

    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    // 0 ------> 1
    //           |
    //           |
    // 2         2

    cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
    g.BFS(2);
    cout << endl;

    cout << "Following is Depth First Traversal (starting from vertex 2) \n";
    g.DFS(2);
    cout << endl;

    cout << "Following is Depth First Traversal (Recursive) (starting from vertex 2) \n";
    g.DFSRecursive(2);
    cout << endl;

    g.reset();
    cout << "Path exists between 2 to 3: " << g.hasPathRecursive(2, 3) << endl;
    cout << "Path exists between 3 to 2: " << g.hasPathRecursive(3, 2) << endl;
    cout << "Path exists between 3 to 3: " << g.hasPathRecursive(3, 3) << endl;

    cout << "Path exists between 2 to 3: " << g.hasPath(2, 3) << endl;
    cout << "Path exists between 3 to 2: " << g.hasPath(3, 2) << endl;
    cout << "Path exists between 3 to 3: " << g.hasPath(3, 3) << endl;

    cout << "Path exists between 2 to 3: " << g.hasPathBFS(2, 3) << endl;
    cout << "Path exists between 3 to 2: " << g.hasPathBFS(3, 2) << endl;
    cout << "Path exists between 3 to 3: " << g.hasPathBFS(3, 3) << endl;

    

    return 0;
}