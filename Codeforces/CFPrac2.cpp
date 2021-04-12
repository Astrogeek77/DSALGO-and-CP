// #include <bits/stdc++.h>
// #include <string>
// #include <cmath>
// using namespace std;

// #define ll long long
// #define ull unsigned long long
// #define pb push_back
// #define vll vector<pair<ll, ll>>
// #define vl vector<ll>
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
//     int t, n;
//     cin >> t;
//     while (t--)
//     {
//         cin >> n;

//         cout << n / 2 + 1 << endl;
//     }
// }

// *****************************

// #include <bits/stdc++.h>
// #include <string>
// #include <cmath>
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
//     ll int t, n, m;
//     cin >> t;
//     while (t--)
//     {
//         cin >> n >> m;

//         int arr[n][m];

//         f(i, 0, n)
//         {
//             f(j, 0, m)
//             {
//                 cin >> arr[i][j];
//             }
//         }

//         int count = 0;
//         f(i, 0, n)
//         {
//             f(j, 0, m)
//             {
//                 int rsum = 0, csum = 0;
//                 f(x, 0, n)
//                     rsum += arr[x][j];
//                 f(y, 0, m)
//                     csum += arr[i][y];

//                 if (rsum == 0 && csum == 0)
//                 {
//                     count++;
//                     arr[i][j] = 1;
//                     break;
//                 }
//             }
//         }

//         if (count % 2 == 0)
//             cout << "Vivek" << endl;
//         else
//             cout << "Ashish" << endl;
//     }
// }

// ******************************

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
//     ll t, a, b;
//     cin >> t;
//     while (t--)
//     {
//         cin >> a >> b;
//         ll ans = 0;
//         if (a < b)
//             swap(a, b);

//         if (a == b)
//             cout << 0 << endl;
//         else if (a % b != 0 || (a / b) % 2 != 0)
//             cout << -1 << endl;
//         else
//         {
//             ll result = a / b;
//             while (result % 8 == 0)
//                 result /= 8, ans++;
//             while (result % 4 == 0)
//                 result /= 4, ans++;
//             while (result % 2 == 0)
//                 result /= 2, ans++;
//             if (result == 1)
//                 cout << ans << endl;
//             else
//                 cout << -1 << endl;
//         }
//     }
// }

// #include <iostream>
// #include <algorithm>
// #define ll long long
// using namespace std;
// int t;
// ll a, b;

// int main()
// {
//     cin >> t;
//     while (t--)
//     {
//         cin >> a >> b;
//         ll ans = 0;
//         if (a < b)
//             swap(a, b);

//         if (a == b)
//             cout << 0 << endl;
//         else if (a % b != 0 || (a / b) % 2 != 0)
//             cout << -1 << endl;
//         else
//         {
//             ll d = a / b;
//             while (d % 8 == 0)
//                 d /= 8, ans++;
//             while (d % 4 == 0)
//                 d /= 4, ans++;
//             while (d % 2 == 0)
//                 d /= 2, ans++;
//             if (d == 1)
//                 cout << ans << endl;
//             else
//                 cout << -1 << endl;
//         }
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
//     ll t, a, b;
//     cin >> t;
//     while (t--)
//     {
//         ll int x, n, oddcount = 0;
//         cin >> n >> x;

//         f(i, 0, n)
//         {
//             ll a;
//             cin >> a;
//             if (a % 2 != 0)
//                 oddcount++;
//         }

//         if (oddcount >= 1 && !(x == n && oddcount % 2 == 0) && !(oddcount == n && x % 2 == 0))
//             cout << "YES" << endl;
//         else
//             cout << "NO" << endl;
//     }
// }

// ***************************

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int t, a;
//     cin >> t;
//     while (t--)
//     {
//         int x, n, oddcount = 0;
//         cin >> n >> x;

//         for (int i = 0; i < n; i++)
//         {
//             int a;
//             cin >> a;
//             if (a % 2 != 0)
//                 oddcount++;
//         }

//         if (oddcount >= 1)
//         {
//             if (!(x == n && oddcount % 2 == 0))
//             {
//                 if (!(oddcount == n && x % 2 == 0))
//                 {
//                     cout << "YES" << endl;
//                 }
//                 else
//                     cout << "NO" << endl;
//             }
//             else
//                 cout << "NO" << endl;
//         }
//         else
//             cout << "NO" << endl;
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
//     ll t, a, b;
//     cin >> t;
//     while (t--)
//     {
//         ll int a, b, c, d, x, y, x1, y1, x2, y2;
//         cin >> a >> b >> c >> d;
//         cin >> x >> y >> x1 >> y1 >> x2 >> y2;

//         x += -a + b;
//         y += -c + d;

//         if (x >= x1 && x <= x2 && y >= y1 && y <= y2 && (x2 > x1 || a + b == 0) && (y2 > y1 || c + d == 0))
//             cout << "YES" << endl;
//         else
//             cout << "NO" << endl;
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
    ll t, a, b;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;

        int rem = b % a;
        int div = b / a;

        cout << (rem * (div + 1) * (div + 1)) + ((a - rem) * div * div) << endl;
    }
}
