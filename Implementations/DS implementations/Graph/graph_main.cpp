// #include "graph_Boilerplate.h"
#include "graph_utils.h"

int main()
{
    // ! Graph 1
    // Graph g(4);
    // g.addEdge(0, 1);
    // g.addEdge(0, 2);
    // g.addEdge(1, 2);
    // g.addEdge(2, 0);
    // g.addEdge(2, 3);
    // g.addEdge(3, 3);

    // ! Graph 2
    Graph g(3);
    g.addEdge(0, 1);
    g.addEdge(1, 2);

    // ! Graph 3
    // Graph g(5);
    // g.addEdge(1, 0);
    // g.addEdge(0, 2);
    // g.addEdge(2, 1);
    // g.addEdge(0, 3);
    // g.addEdge(3, 4);

    //?        Operations

    cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
    g.BFS(2);
    cout << endl;

    cout << "Following is Depth First Traversal (starting from vertex 2) \n";
    g.DFS(2);
    cout << endl;

    cout << "Following is Depth First Traversal (Recursive) (starting from vertex 2) \n";
    g.DFSRecursive(2);
    cout << endl;

    // if (g.checkCycle())
    //     cout << "Graph contains cycle";
    // else
    //     cout << "Graph doesn't contain cycle";
    // return 0;

    // g.reset();
    // g.checkCycle() ? cout << "Graph contains cycle\n" : cout << "Graph doesn't contain cycle\n";
    // g.checkCycle2() ? cout << "Graph contains cycle\n" : cout << "Graph doesn't contain cycle\n";

    g.checkCycle2() ? cout << "Graph contains cycle\n" : cout << "Graph doesn't contain cycle\n";

    if (g.checkBiPartite1())
        cout << "Graph is Bipartile.";
    else
        cout << "Graph is not Bipartile.";

    // g.reset();
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