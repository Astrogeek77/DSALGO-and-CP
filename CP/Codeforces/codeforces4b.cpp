#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    unsigned long long int r, g, b, w;
    for (int i = 0; i < n; i++)
    {
        scanf("%llu", &r);
        scanf("%llu", &g);
        scanf("%llu", &b);
        scanf("%llu", &w);

        if (r > 0 && b > 0 && g > 0 && w > 0 || r == 0 && b == 0 && g == 0 && w == 0)
        {
            // if (r == 0 && b == 0 || r == 0 && g == 0  || r == 0 && w == 0 || g == 0 && b == 0
            // || w == 0 && b == 0|| w == 0 && g == 0 )
            // {

            // }
            // if( r == 0 || b == 0 || g == 0 || w == 0 || )
            // {

            // }
            printf("Yes\n");
        }
        else
        {
            printf("no\n");
        }
    }
    return 0;
}