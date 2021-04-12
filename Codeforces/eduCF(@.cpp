
// #include <bits/stdc++.h>
// #include <string>
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

// const ll mod = 1e9 + 7;
// const ll mod2 = 1999999973;
// const ll inf = 1e18;
// const int infs = 1e9 + 1000;
// const int N = 100000;
// const long double PI = acos(-1);

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n, z = 0;
//         cin >> n;
//         string s;
//         cin >> s;

//         f(i, 1, n)
//         {
//             cout << s[(n - 1) + i];
//         }
//         cout << endl;
//     }
// }

// ***************************

// #include <bits/stdc++.h>
// #include <string>
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

// const ll mod = 1e9 + 7;
// const ll mod2 = 1999999973;
// const ll inf = 1e18;
// const int infs = 1e9 + 1000;
// const int N = 100000;
// const long double PI = acos(-1);

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int p, f, s, w, numS, numW;
//         int count = 0;
//         cin >> p >> f;
//         cin >> numS >> numW;
//         cin >> s >> w;

//         int wt = (numS * s) + (numW * w);
//         int st = p + f;
//         int ut = numS + numW;

//         while (st > 0)
//         {
//             if (wt < st)
//             {
//                 cout << ut << endl;
//                 break;
//             }
//             else if (s * numS < w * numW && st > 0)
//             {
//                 if (s < w)
//                 {
//                     count += numS;
//                     numS = 0;
//                     st = st - (s * numS);
//                 }
//                 else
//                 {
//                     count += numW;
//                     numW = 0;
//                     st = st - (w * numW);
//                 }
//             }
//             else if (w * numW < s * numS)
//             {
//                 if (w < s)
//                 {
//                     count += numW;
//                     numW = 0;
//                     st = st - (w * numW);
//                 }
//                 else
//                 {
//                     count += numS;
//                     numS = 0;
//                     st = st - (s * numS);
//                 }
//             }
//         }
//         cout << count << endl;
//     }
// }

// ****************************

// #include <bits/stdc++.h>
// using namespace std;

// int t, n;
// char s[102];

// int main()
// {
//     cin >> t;
//     while (t--)
//     {
//         scanf("%d%s", &n, s + 1);
//         for (int i = 1; i <= n; i++)
//             putchar(s[n]);
//         putchar('\n');
//     }
//     return 0;
// }

// ****************************

// #include <bits\stdc++.h>
// using namespace std;
// int main()
// {
//     int j;
//     cin >> j;
//     while (j--)
//     {
//         int n, count = 0;
//         cin >> n;
//         string s;
//         cin >> s;
//         for (int i = 0; i < n; i++)
//         {
//             cout << s[2 * i];
//         }
//         cout << "\n";
//     }
// }