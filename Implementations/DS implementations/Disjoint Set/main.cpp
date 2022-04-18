#include "DisjSet.h"

int main()
{
    DisjointSet djs(5);
    djs.Union(0, 2);
    djs.Union(4, 2);
    djs.Union(3, 1);

    if (djs.findPar(4) == djs.findPar(0))
        cout << "Same Component\n";
    else
        cout << "Different Component\n";

    if (djs.findPar(1) == djs.findPar(0))
        cout << "Same Component\n";
    else
        cout << "Different Component\n";

    return 0;
}