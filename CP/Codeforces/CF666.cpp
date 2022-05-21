
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
//         IOS;
//         ll n;
//         cin >> n;

//         string s = "";
//         f(i, 0, n)
//         {
//             string a;
//             scanf("%s", &a);
//             s += a;
//         }

//         ll size = s.length();

//         f(i, 0, size)
//         {
//             ll dis = 0;
//             f(j, i, size)
//             {
//                 if (s[j] != s[i] && s[])
//                 {
//                     dis++;
//                 }
//             }
//         }

//         if (size % n != 0)
//             cout << "NO" << endl;
//         else
//         {
//             int count = 0;

//             f(j, 0, size)
//             {
//                 char check = s[j];
//                 f(i, j, size)
//                 {
//                     if (check == s[i])
//                     {
//                         count++;
//                     }
//                 }

//                 if (count % n == 0)
//                 {
//                     continue;
//                 }
//             }
//         }
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
//     ll t;
//     cin >> t;
//     while (t--)
//     {
//         IOS;
//         ll n;
//         cin >> n;

//         string s = "";
//         string a;
//         ll count = 0;
//         bool result = true;

//         f(i, 0, n) cin >> a, s += a;

//         sort(all(s));
//         ll size = s.length();

//         if (size % n != 0)
//             cout << "NO" << endl;
//         else
//         {
//             ll count = 0;
//             ll m = 0;
//             bool result = true;
//             f(i, 0, size)
//             {
//                 if (s[m] == s[i])
//                     count++;
//                 else
//                 {
//                     m = i;
//                     count = 1;
//                     if (count % n != 0)
//                     {
//                         cout << "NO" << endl;
//                         result = false;
//                         break;
//                     }
//                 }
//             }
//             if (result)
//                 cout << "YES" << endl;
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
// #define show(x) cout << x << endl;
// #define take(x) cin >> x;

// const ll mod = 1e9 + 7;
// const ll mod2 = 1999999973;
// const ll inf = 1e18;
// const int infs = 1e9 + 1000;
// const int N = 100000;
// const long double PI = acos(-1);

// int main()
// {
//     IOS;
//     ll t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;

//         string s = "";
//         string a;

//         f(i, 0, n) cin >> a, s += a;

//         sort(all(s));
//         int size = s.length();

//         if (size % n != 0)
//         {
//             show("NO");
//         }
//         else
//         {
//             int count = 0;
//             bool result = true;
//             int j = 0;
//             f(i, 0, size)
//             {
//                 if (s[j] == s[i])
//                     count++;
//                 else
//                 {
//                     if (count % n != 0)
//                     {
//                         result = false;
//                         show("NO");
//                         break;
//                     }
//                     j = i + 1;
//                     count = 1;
//                 }
//             }
//             if (result)
//                 show("YES");
//         }
//     }
// }

// *****************************

// libraries used
#include <bits/stdc++.h>
// #include <string>
// #include <cmath>
// #include <iostream>
// #include <algorithm>
// #include <conio.h>
using namespace std;

// Definations and macros
#define ll long long
#define ull unsigned long long
#define pb push_back
#define vl vector<ll>
#define vi vector<ll int>
// Loop Definations
#define f(i, n, a) for (int i = 0; i < n; i += a)
#define f(i, a, b, c) for (int i = a; i < b; i += c)
#define fa(i, a, b, c) for (int i = a; i >= b; i -= c)
#define test while(t--)
// Miscellanous definations
#define re return 0
#define all(x) x.begin(), x.end()
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// #define debug(x) cerr << "[" << #x << "]:" << x << endl;
#define show(x) cout << x << endl;
#define take(x) cin >> x;

// variable declarations
ll a, b, c, d, e, f, g, h, x, y, z, p, q, m, n, t, r, w, l, ans = 0, count = 0;
string S, T;
vl A, B;

// Constants
const ll mod = 1e9 + 7;
const ll mod2 = 1999999973;
const ll inf = 1e18;
const int infs = 1e9 + 1000;
const int N = 100000;
const long double PI = acos(-1);

// main solution
int main()
{
    IOS;
    cin >> t;
    test
    {
        cin >> a >> b >> c >> d;

        if (b >= a)
        {
            show(b);
        }
        else if (d >= c)
        {
            show(-1);
        }
        else
        {
            a -= b;
            a = (a - 1) / (c - d) + 1;
            show(b + a * c);
        }
    }
    re;
}
// end solution