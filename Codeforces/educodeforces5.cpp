#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    int n;
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (a[0] + a[1] <= a[n - 1])
        {
            cout << 1 << " " << 2 << " " << n << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
}
