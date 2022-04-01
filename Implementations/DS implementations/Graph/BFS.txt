#include <iostream>
#include <list>

using namespace std;

class Graph
{
    int V;
    list<int> *edges;

public:
    Graph(int V);
    void addEdge(int v, int w);
    void BFS(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    edges = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    edges[v].push_back(w);
}

void Graph::BFS(int u)
{
    // bool array maintaing the visited nodes
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        // in begining all the nodes are set as unvisited;
        visited[i] = false;

    // queue for FIFO operation
    list<int> queue;

    // starting node
    visited[u] = true;
    queue.push_back(u);

    // iterator for our list
    list<int>::iterator i;

    while (!queue.empty())
    {
        u = queue.front();
        cout << u << " ";
        queue.pop_front();

        for (i = edges[u].begin(); i != edges[u].end(); ++i)
        {
            if (!visited[*i])
            {
                // node is set to be visited
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Breadth First Traversal(BFS) "
         << "(starting from vertex 2) \n";
    g.BFS(2);

    return 0;
}