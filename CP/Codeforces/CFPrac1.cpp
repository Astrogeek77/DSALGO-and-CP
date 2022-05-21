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
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         int arr[n];

//         f(i, 0, n)
//         {
//             cin >> arr[i];
//         }

//         char s[25] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', '\0'};
//     }
// }

// ****************************

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

// const ll mod = 1e9 + 7;
// const ll mod2 = 1999999973;
// const ll inf = 1e18;
// const int infs = 1e9 + 1000;
// const int N = 100000;
// const long double PI = acos(-1);

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     int t;
//     cin >> t;
//     while (t--)
//     {
//         ll int n;
//         cin >> n;
//         if (n % 2 == 0)
//             cout << n / 2 << endl;
//         else
//             cout << n / 2 + 1 << endl;
//     }
// }

// ****************************

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

// const ll mod = 1e9 + 7;
// const ll mod2 = 1999999973;
// const ll inf = 1e18;
// const int infs = 1e9 + 1000;
// const int N = 100000;
// const long double PI = acos(-1);

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     int t;
//     cin >> t;
//     while (t--)
//     {
//         ll int x, y, n;
//         cin >> x >> y >> n;

//         int m = n - y;
//         int a = m % x;

//         cout << (n - a) << endl;
//     }
// }

// ****************************

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

// const ll mod = 1e9 + 7;
// const ll mod2 = 1999999973;
// const ll inf = 1e18;
// const int infs = 1e9 + 1000;
// const int N = 100000;
// const long double PI = acos(-1);

// int main()
// {
//     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         cout << n / 2 << endl;
//     }
// }

// ****************************

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
// #define endl "\n"

// const ll mod = 1e9 + 7;
// const ll mod2 = 1999999973;
// const ll inf = 1e18;
// const int infs = 1e9 + 1000;
// const int N = 100000;
// const long double PI = acos(-1);

// int main()
// {
//     IOS;
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         string s, result = "";
//         cin >> s;

//         result += s[0];
//         result += s[1];

//         for (int i = 3; i < s.size(); i += 2)
//             result += s[i];

//         cout << result << endl;
//     }
// }

// ****************************

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
// #define endl "\n"

// const ll mod = 1e9 + 7;
// const ll mod2 = 1999999973;
// const ll inf = 1e18;
// const int infs = 1e9 + 1000;
// const int N = 100000;
// const long double PI = acos(-1);

// main()
// {
//     IOS;
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n, x, sum = 0, ans = 0;
//         cin >> n >> x;

//         int a[n + 3];
//         f(i, 1, n) cin >> a[i], sum += a[i];

//         if (sum % x)
//         {
//             cout << n << endl;
//             continue;
//         }

//         f(i, 1, n)
//         {
//             if (a[i] % x)
//             {
//                 ans = max(ans, i - 1);
//                 ans = max(ans, n - i);
//             }
//         }

//         cout << (ans != 0 ? ans : -1) << endl;
//     }
// }

// *************************

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
// #define endl "\n"

// const ll mod = 1e9 + 7;
// const ll mod2 = 1999999973;
// const ll inf = 1e18;
// const int infs = 1e9 + 1000;
// const int N = 100000;
// const long double PI = acos(-1);

// int main()
// {
//     IOS;
//     int t, n, x, a;
//     cin >> t;
//     while (t--)
//     {
//         cin >> n >> x;
//         int sum = 0, result = -1;
//         for (int i = 1; i <= n; i++)
//         {
//             cin >> a;
//             sum = sum + a;
//             if (sum % x > 0)
//                 result = max(result, max(i, n - i));
//         }
//         cout << result << endl;
//     }
// }

// ***************************

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
// #define endl "\n"

// const ll mod = 1e9 + 7;
// const ll mod2 = 1999999973;
// const ll inf = 1e18;
// const int infs = 1e9 + 1000;
// const int N = 100000;
// const long double PI = acos(-1);

// int main()
// {
//     IOS;
//     int t, n, x, a;
//     cin >> t;
//     while (t--)
//     {
//         cin >> n;

//         if (n > 30)
//         {
//             cout << "YES" << endl;
//             if (n == 36 || n == 40 || n == 44)
//                 cout << 10 << " " << 15 << " " << 6 << " " << n - 31 << endl;
//             else
//                 cout << 10 << " " << 14 << " " << 6 << " " << n - 30 << endl;
//         }
//         else
//         {
//             cout << "NO" << endl;
//         }
//     }
// }

// ***************************

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
//     IOS;
//     int t, n, b, a;
//     cin >> t;
//     while (t--)
//     {
//         cin >> a >> b;

//         cout << min(a, min(b, (a + b) / 3)) << endl;
//     }
// }

// ***************************

// #include <iostream>
// int t, a, b;
// main()
// {
//     for (scanf("%d", &t); t--;)
//     {
//         scanf("%d%d", &a, &b);
//         if (a > b)
//             std::swap(a, b);
//         printf("%d\n", b < a * 2 ? (a + b) / 3 : a);
//     }
// }

// ***************************

// #include <iostream>
// using namespace std;
// int N, T, a;
// string S(99, 99);
// main()
// {
//     for (cin >> T; T--;)
//         for (cin >> N; cout << S << '\n', N--; S[a] ^= 1)
//             cin >> a;
// }

// ***************************

// #include <bits/stdc++.h>
// using namespace std;
// int t, n, i, j, k, l;
// int a[1001];
// char s[1001];
// int main()
// {
//     cin >> t;
//     while (t--)
//     {
//         cin >> n;
//         k = 0;
//         for (i = 1; i <= n; i++)
//         {
//             cin >> a[i];
//             k = max(k, a[i]);
//         }
//         l = k + 1;
//         for (i = 0; i < l; i++)
//             s[i] = 'a';
//         s[l] = '\0';
//         printf("%s\n", s);
//         for (i = 1; i <= n; i++)
//         {
//             for (j = l; j > a[i]; j--)
//                 s[j] = s[j - 1];
//             s[a[i]] = (s[a[i]] - 'a' + 1) % 26 + 'a';
//             l++;
//             s[l] = '\0';
//             printf("%s\n", s);
//         }
//     }
//     return 0;
// }

// ***************************

// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int test, n, a[105], i;
//     cin >> test;
//     while (test--)
//     {
//         cin >> n;
//         for (i = 0; i < n; i++)
//         {
//             cin >> a[i];
//         }
//         string x(51, 'a');
//         cout << x << endl;
//         for (i = 0; i < n; i++)
//         {
//             if (x[a[i]] >= 'a' && x[a[i]] < 'z')
//             {
//                 x[a[i]]++;
//                 cout << x << endl;
//             }
//             else
//             {
//                 x[a[i]]--;
//                 cout << x << endl;
//             }
//         }
//     }
// }

// ***************************

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
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;

//     while (t--)
//     {
//         int n;
//         cin >> n;
//         string s(200, 'a');
//         cout << s << '\n';

//         for (int i = 0; i < n; ++i)
//         {
//             int x;
//             cin >> x;
//             s[x] = (s[x] == 'a' ? 'b' : 'a');
//             cout << s << endl;
//         }
//     }

//     return 0;
// }

// ***************************

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
//     IOS;
//     ll int n;
//     cin >> n;

//     if (n % 2 == 0)
//         cout << n / 2 << endl;
//     else
//     {
//         cout << n / 2 - n << endl;
//     }

//     return 0;
// }
