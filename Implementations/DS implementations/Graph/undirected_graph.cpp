#include "UDG_utils.h"
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

    // if (g.checkCycle())
    //     cout << "Graph contains a cycle";
    // else
    //     cout << "Graph doesn't contain a cycle";
    // return 0;

    // g.reset();
    // g.checkCycle() ? cout << "Graph contains cycle\n" : cout << "Graph doesn't contain cycle\n";
    // g.checkCycle2() ? cout << "Graph contains cycle\n" : cout << "Graph doesn't contain cycle\n";

    g.checkCycle2() ? cout << "Graph contains cycle\n" : cout << "Graph doesn't contain cycle\n";

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