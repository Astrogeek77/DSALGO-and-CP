#include <bits/stdc++.h>
using namespace std;

int main() {
    int numGrid;
    scanf("%d", &numGrid);

    for (int i = 0; i < numGrid; i++) {

        long int GridSize;
        int count = 0;
        scanf("%ld", &GridSize);
        long int NumSQRS = GridSize * GridSize;
        int j = 1;
        int a = 2;
        if (GridSize == 3) {
            count = 2;
        }
        while (NumSQRS > 0 && GridSize > 3) {
            if (j % 2 == 1) {
                NumSQRS = NumSQRS - (4 * (GridSize - a));
                a++;
            }
            else {
                NumSQRS = NumSQRS - 4;
            }
            j++;
            count++;
        }
        printf("%d\n", count);

    }
    return 0;
}