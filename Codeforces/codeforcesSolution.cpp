#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int n;
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        if (n <= 30)
            puts("NO");
        else
            printf("YES\n6 10 14 %d\n", n - 30);
    }
}

// for (int j = 3; j < (2 * GridSize); j++) {
        //     if (NumSQRS > 0) {
        //         if (j % 2 == 0) {
        //             NumSQRS - 4 * ;
        //             count++;
        //         }
        //         else {
        //             NumSQRS - (2 * (GridSize - 1));
        //             count++;
        //         }
        //         printf("%d", count);
        //         break;
        //     }
        // }
1
64

