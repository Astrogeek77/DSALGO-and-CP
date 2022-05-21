#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, x, y;
    scanf("%d%d%d%d", &n, &m, &x, &y);
    for (int i = 1; i <= n; i++)
    {
        printf("%d %d\n", x, y);
        for (int j = 1; j <= m; j++)
        {
            if (j != y)
                printf("%d %d\n", x, j);
        }
        if (y == m)
        {
            y = m - 1;
        }
        else
        {
            y = m;
            x = x % n + 1;
        }
    }
}

// int main()
// {
//     int n, m, x, y;
//     cin >> n >> m >> x >> y;
//     x--;
//     y--;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             printf("%d %d\n", x + 1, y + 1);
//             if (j != m - 1)
//                 y = (y + 1) % m;
//         }
//         x = (x + 1) % n;
//     }

//     return 0;
// }