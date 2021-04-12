#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vll vector<pair<ll, ll>>
#define vl vector<ll>
#define f(i, a, b) for (i = a; i < b; i++)
#define re return 0

const ll mod = 1e9 + 7;
const ll mod2 = 1999999973;
const ll inf = 1e18;
const int infs = 1e9 + 1000;
const int N = 100000;
const long double PI = acos(-1);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, i, j;
        cin >> n >> m;
        int a[n], b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                if (a[i] == b[j])
                    break;
            }
            if (j != m)
                break;
        }
        if (i != n)
            cout << "YES\n"
                 << 1 << " " << a[i] << endl;
        else
            cout << "NO" << endl;
    }
}
