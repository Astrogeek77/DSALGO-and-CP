// #include <bits/stdc++.h>
// #include <string>
// #include <cmath>
// #include <iostream>
// #include <algorithm>
// using namespace std;

// #define ll long long
// #define ull unsigned long long
// #define pb push_back
// #define vll vector<pair<ll, ll>>
// #define vl vector<ll>
// #define vi vector<ll int>
// #define f(i, a, b) for (int i = a; i < b; i++)
// #define fa(i, a, b) for (int i = a; i >= b; i--)
// #define re return 0
// #define all(x) x.begin(), x.end()
// #define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// #define debug(x) cerr << "[" << #x << "]:" << x << endl;
// #define endl "\n"

// const ll mod = 1e9 + 7;
// const ll mod2 = 1999999973;
// const ll inf = 1e18;
// const int infs = 1e9 + 1000;
// const int N = 100000;
// const long double PI = acos(-1);

// int main()
// {
//     ll t, n, m, k;
//     cin >> t;
//     while (t--)
//     {
//         cin >> n >> m >> k;

//         ll x = min(n / k, m);
//         m -= x, k -= 1;
//         ll y = (m - 1 + k) / k;
//         cout << x - y << endl;
//     }
// }

// **************************

// #include <bits/stdc++.h>
// #include <string>
// #include <cmath>
// #include <iostream>
// #include <algorithm>
// using namespace std;

// #define ll long long
// #define ull unsigned long long
// #define pb push_back
// #define vll vector<pair<ll, ll>>
// #define vl vector<ll>
// #define vi vector<ll int>
// #define f(i, a, b) for (int i = a; i < b; i++)
// #define fa(i, a, b) for (int i = a; i >= b; i--)
// #define re return 0
// #define all(x) x.begin(), x.end()
// #define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// #define debug(x) cerr << "[" << #x << "]:" << x << endl;
// #define endl "\n"

// const ll mod = 1e9 + 7;
// const ll mod2 = 1999999973;
// const ll inf = 1e18;
// const int infs = 1e9 + 1000;
// const int N = 100000;
// const long double PI = acos(-1);

// int main()
// {
//     ll t, n, m, k;
//     cin >> t;
//     while (t--)
//     {
//         cin >> n >> m;

//         if ((m * n) % 2 != 0)
//             cout << (m * n) / 2 + 1 << endl;
//         else
//             cout << (m * n) / 2 << endl;
//     }
// }

// ****************************

// #include <bits/stdc++.h>
// #include <string>
// #include <cmath>
// #include <iostream>
// #include <algorithm>
// using namespace std;

// #define ll long long
// #define ull unsigned long long
// #define pb push_back
// #define vll vector<pair<ll, ll>>
// #define vl vector<ll>
// #define vi vector<ll int>
// #define f(i, a, b) for (int i = a; i < b; i++)
// #define fa(i, a, b) for (int i = a; i >= b; i--)
// #define re return 0
// #define all(x) x.begin(), x.end()
// #define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// #define debug(x) cerr << "[" << #x << "]:" << x << endl;
// #define endl "\n"

// const ll mod = 1e9 + 7;
// const ll mod2 = 1999999973;
// const ll inf = 1e18;
// const int infs = 1e9 + 1000;
// const int N = 100000;
// const long double PI = acos(-1);

// int main()
// {
//     ll t, n, m, k;
//     cin >> t;
//     while (t--)
//     {
//         ll a, b;
//         cin >> a >> b;

//         cout << min(max(2 * a, b), max(a, 2 * b)) * min(max(2 * a, b), max(a, 2 * b)) << endl;
//     }
// }

// ***************************

// #include <bits/stdc++.h>
// #include <string>
// #include <cmath>
// #include <iostream>
// #include <algorithm>
// using namespace std;

// #define ll long long
// #define ull unsigned long long
// #define pb push_back
// #define vll vector<pair<ll, ll>>
// #define vl vector<ll>
// #define vi vector<ll int>
// #define f(i, a, b) for (int i = a; i < b; i++)
// #define fa(i, a, b) for (int i = a; i >= b; i--)
// #define re return 0
// #define all(x) x.begin(), x.end()
// #define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// #define debug(x) cerr << "[" << #x << "]:" << x << endl;
// #define endl "\n"

// const ll mod = 1e9 + 7;
// const ll mod2 = 1999999973;
// const ll inf = 1e18;
// const int infs = 1e9 + 1000;
// const int N = 100000;
// const long double PI = acos(-1);

// int main()
// {
//     ll t;
//     cin >> t;
//     while (t--)
//     {
//         ll n, d;
//         cin >> n >> d;

//         if (n >= d)
//             cout << "YES" << endl;
//         else
//         {
//             for (int x = 1; x <= d - n; x++)
//             {
//                 ll m = ceil((float)d / (x + 1));
//                 // cout << "M: " << m << endl;
//                 if (m + x <= n)
//                 {
//                     cout << "YES" << endl;
//                     break;
//                 }
//                 else if (x >= n)
//                 {
//                     cout << "NO" << endl;
//                     break;
//                 }
//             }
//         }
//     }
// }

// ***************************

#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define vll vector<pair<ll, ll>>
#define vl vector<ll>
#define vi vector<ll int>
#define f(i, a, b) for (int i = a; i < b; i++)
#define fa(i, a, b) for (int i = a; i >= b; i--)
#define re return 0
#define all(x) x.begin(), x.end()
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define debug(x) cerr << "[" << #x << "]:" << x << endl;
#define endl "\n"

const ll mod = 1e9 + 7;
const ll mod2 = 1999999973;
const ll inf = 1e18;
const int infs = 1e9 + 1000;
const int N = 100000;
const long double PI = acos(-1);

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, d;
        cin >> n >> d;
        ll x = 1;
        bool result = true;

        if (n >= d)
            cout << "YES" << endl;
        else
        {
            while (result)
            {
                ll m = ceil((float)d / (x + 1));
                // cout << "M: " << m << endl;
                if (m + x <= n)
                {
                    cout << "YES" << endl;
                    result = false;
                    break;
                }
                else if (x >= n)
                {
                    cout << "NO" << endl;
                    result = false;
                    break;
                }
                x++;
            }
        }
    }
}
