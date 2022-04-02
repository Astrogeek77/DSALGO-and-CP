#include "DG_utils.h"

int main()
{
    // ! Graph 1 (Cyclic)
    // Graph g(4);
    // g.addEdge(0, 1);
    // g.addEdge(0, 2);
    // g.addEdge(1, 2);
    // g.addEdge(2, 0);
    // g.addEdge(2, 3);
    // g.addEdge(3, 3);

    // ! Graph 2   (Acyclic)
    // Graph g(3);
    // g.addEdge(0, 1);
    // g.addEdge(1, 2);

    // ! Graph 3   (Cyclic)
    // Graph g(5);
    // g.addEdge(1, 0);
    // g.addEdge(0, 2);
    // g.addEdge(2, 1);
    // g.addEdge(0, 3);
    // g.addEdge(3, 4);

    // ! Graph 4   (Acyclic)
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    //?        Operations

    cout << "Following is Breadth First Traversal (starting from vertex 0): ";
    g.BFS(0);
    cout << endl;

    cout << "Following is Depth First Traversal (starting from vertex 0): ";
    g.DFS(0);
    cout << endl;

    g.reset();

    cout << "Following is Depth First Traversal (Recursive) (starting from vertex 0): ";
    g.DFSRecursive(0);
    cout << endl;

    cout << "BiPartite check using BFS: ";
    if (g.checkBiPartite1())
        cout << "Graph is Bipartile.\n";
    else
        cout << "Graph is not Bipartile.\n";

    cout << "BiPartite check using DFS: ";
    if (g.checkBiPartite2())
        cout << "Graph is Bipartile.\n";
    else
        cout << "Graph is not Bipartile.\n";

    cout << "Topological Sort (DFS): ";
    g.TopologicalSortDFS();

    cout << "Topological Sort (BFS): ";
    g.topSortBFS();

    

    // cout << "Path exists between 2 to 3: " << g.hasPathRecursive(2, 3) << endl;
    // cout << "Path exists between 3 to 2: " << g.hasPathRecursive(3, 2) << endl;
    // cout << "Path exists between 3 to 3: " << g.hasPathRecursive(3, 3) << endl;

    // cout << "Path exists between 2 to 3: " << g.hasPath(2, 3) << endl;
    // cout << "Path exists between 3 to 2: " << g.hasPath(3, 2) << endl;
    // cout << "Path exists between 3 to 3: " << g.hasPath(3, 3) << endl;

    // cout << "Path exists between 2 to 3: " << g.hasPathBFS(2, 3) << endl;
    // cout << "Path exists between 3 to 2: " << g.hasPathBFS(3, 2) << endl;
    // cout << "Path exists between 3 to 3: " << g.hasPathBFS(3, 3) << endl;

    // cout << "Shortest Path edges from 0 to 2: " << g.shortestPathBFS(0, 2) << endl;
    // cout << "Shortest Path edges from 3 to 1: " << g.shortestPathBFS(3, 1) << endl;
    // cout << "Shortest Path edges from 3 to 3: " << g.shortestPathBFS(3, 3) << endl;

    return 0;
}