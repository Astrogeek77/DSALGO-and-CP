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
        list<int> queue;

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

        list<int> stack;

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

    cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
    g.BFS(2);
    cout << endl;

    cout << "Following is Depth First Traversal (starting from vertex 2) \n";
    g.DFS(2);
    cout << endl;

    cout << "Following is Depth First Traversal (Recursive) (starting from vertex 2) \n";
    g.DFSRecursive(2);
    cout << endl;

    return 0;
}