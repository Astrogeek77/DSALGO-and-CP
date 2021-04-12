// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {

//     int t, len;
//     scanf("%d", &t);

//     for (int a = 0; a < t; a++)
//     {
//         scanf("%d", &len);
//         int arr[len];
//         for (int b = 0; b < len; b++)
//         {
//             scanf("%d", &arr[b]);
//         }
//         for (int c = 0; c < len; c++)
//         {
//             for (int d = c + 1; d < len; d++)
//             {
//                 int temp;
//                 if (arr[d] < arr[c])
//                 {
//                     temp = arr[c];
//                     arr[c] = arr[d];
//                     arr[d] = temp;
//                 }
//             }
//         }
//         int el = arr[0], count = 0;
//         for (int e = 1; e < len; e++)
//         {
//             if (el - arr[e] == 0 || arr[e] - el == 1)
//             {
//                 el = arr[e];
//                 count++;
//             }
//         }
//         if (count == len - 1)
//         {
//             puts("YES");
//         }
//         else
//         {
//             puts("NO");
//         }
//     }
//     return 0;
// }

// *************************************

// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long
// #define pb push_back
// #define vll vector<pair<ll, ll>>
// #define vl vector<ll>
// #define f(i, a, b) for (int i = a; i < b; i++)
// #define re return 0

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
//         ll int n, minA, minB, count = 0;
//         cin >> n;
//         int a[n], b[n];
//         f(i, 0, n)
//                 cin >>
//             a[i];
//         f(i, 0, n)
//                 cin >>
//             b[i];

//         minA = *min_element(a, a + n);
//         minB = *min_element(b, b + n);

//         f(i, 0, n)
//             a[i] -= minA;
//         f(i, 0, n)
//             b[i] -= minB;

//         f(i, 0, n)
//             count += max(a[i], b[i]);
//         cout << count << endl;
//     }
// }

// **********************************

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int t, n, count;
//     cin >> t;
//     while (t--)
//     {
//         cin >> n;
//         count = 0;
//         if (n % 2 != 0)
//         {
//             cout << 7;
//             n -= 3;
//         }
//         count = n / 2;
//         for (int i = 0; i < count; i++)
//         {
//             cout << 1;
//         }
//         cout << endl;
//     }
//     return 0;
// }

// *************************************

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         unsigned long long int l, r;
//         cin >> l >> r;

//         if (2 * l > r)
//             cout << "-1 -1" << endl;

//         else
//             cout << l << " " << 2 * l << endl;
//     }
// }

// ******************************************

// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long
// #define ull unsigned long long
// #define pb push_back
// #define vll vector<pair<ll, ll>>
// #define vl vector<ll>
// #define f(i, a, b) for (int i = a; i < b; i++)
// #define re return 0

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
//         ull int n, k;
//         cin >> n >> k;
//         if (k * k > n)
//             cout << "NO" << endl;
//         else if (k % 2 == 0)
//             if (n % 2 == 0)
//                 cout << "YES" << endl;
//             else
//                 cout << "NO" << endl;
//         else
//         {
//             if (n % 2 == 0)
//                 cout << "NO" << endl;
//             else
//                 cout << "YES" << endl;
//         }
//     }
// }

// *************************************

// #include <bits/stdc++.h>
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
//         string s;
//         cin >> s;
//         int size = s.size();
//         int count = 0, a = 0, b = 0;
//         f(i, 0, size)
//         {
//             if (s[i] == '1')
//             {
//                 a = i;
//                 break;
//             }
//         }

//         fa(i, size - 1, 0)
//         {
//             if (s[i] == '1')
//             {
//                 b = i;
//                 break;
//             }
//         }

//         f(i, a, b)
//         {
//             if (s[i] == '0')
//                 count++;
//         }

//         cout << count << "\n";
//     }
// }

// *********************************

// #include <bits/stdc++.h>
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

//     string s;
//     int a = 0, b = 0;
//     int d1 = 0, d2 = 0;
//     cin >> s;
//     int size = s.length();

//     f(i, 0, size)
//     {
//         if (s[i] == '0')
//         {
//             a++;
//             if (a >= 7)
//             {
//                 d1 = a;
//                 break;
//             }
//         }
//         else
//             a = 0;

//         if (s[i] == '1')
//         {
//             b++;
//             if (b >= 7)
//             {
//                 d2 = b;
//                 break;
//             }
//         }
//         else
//             b = 0;
//     }

//     if (d1 >= 7 || d2 >= 7)
//         puts("YES");
//     else
//         puts("NO");
// }

// *****************************

// #include <bits/stdc++.h>
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
//         int arr[2 * n], arr1[n];
//         bool game = false;

//         for (int i = 0; i < 2 * n; i++)
//         {
//             cin >> arr[i];
//         }

//         arr1[0] = arr[0];
//         z = 1;

//         for (int i = 0; i < 2 * n; i++)
//         {
//             for (int j = 0; j < i; j++)
//             {
//                 if (arr[i] != arr[j])
//                 {
//                     game = true;
//                 }
//                 else
//                 {
//                     game = false;
//                     break;
//                 }
//             }
//             if (game)
//             {
//                 arr1[z] = arr[i];
//                 z++;
//             }
//         }

//         for (int i = 0; i < n; i++)
//         {
//             printf("%d ", arr1[i]);
//         }
//         printf("\n");
//     }
// }

// ************************************************

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int t, n;
//     cin >> t;
//     while (t--)
//     {
//         for (cin >> n; n--)
//             cout << "1 ";
//         cout << endl;
//     }
// }

// *************************

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int a[n];
        bool game = false;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int x = 0;
        for (int i = 2; i <= n - 1; i++)
        {
            if (a[i - 1] < a[i] && a[i] > a[i + 1])
            {
                cout << "YES\n"
                     << i - 1 << " " << i << " " << i + 1 << endl;
                game = true;
                break;
            }
        }
        if (!game)
        {
            cout << "NO" << endl;
        }
    }
}
