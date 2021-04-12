#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
ll m, n, t, a, b, c, d, x, y, z, count = 0, value = 0;
bool check = true, result = true;
vector<ll> vec1, vec2;
string S, T;
#define test  \
    cin >> t; \
    while (t--)
#define show(x) cout << x << endl;
#define take(x) cin >> x;

int main()
{
    IOS;
    test
    {
        ll n, k, temp = 0;
        cin >> n >> k;

        for(int i = 2; i < k; i++)
        {
          if(n % i == 0)
          {
            temp = i;
            break;
          }
        }
        n += n + (k - 1) * 2 + temp;
        cout << n << endl;
    }
}
