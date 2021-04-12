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
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n, k;
//         cin >> n >> k;

//         if (k == 0 && n == 1 || n == 0 && k == 0 || n == 1 && k == 1)
//         {
//             printf("%d \n", n);
//         }
//         else if (k == 0)
//         {
//             if (n % 2 == 0)
//             {
//                 printf("%d \n", 0);
//             }
//             else
//             {
//                 printf("%d \n", 1);
//             }
//         }
//         else if (n == 0)
//         {
//             printf("%d \n", k);
//         }
//         else
//         {
//             if (k < n)
//             {
//                 printf("%d \n", n - k);
//             }
//             else
//                 printf("%d \n", k - n);
//         }
//     }
// }

// ****************************

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int x1, y1, z1, x2, y2, z2;
//         cin >> x1 >> y1 >> z1;
//         cin >> x2 >> y2 >> z2;

//         int size = x1 + y1 + z1;
//         int arr1[size], arr2[size], arr3[size];

//         f(i, 0, size)
//         {
//             int a = 0;
//             f(j, 0, z1)
//             {
//                 arr1[j] = 2;
//                 if (y2 > 0)
//                 {
//                     arr2[j] = 1;
//                     y2--;
//                 }
//                 else
//                 {
//                     arr2[j] = 2;
//                     z2--;
//                 }
//                 a++;
//             }
//             f(k, a, y1)
//             {
//                 arr1[k] = 1;
//                 if (y2 > 0)
//                 {
//                     arr2[k] = 1;
//                     y2--;
//                 }
//                 else
//                 {
//                     arr2[k] = 0;
//                     x2--;
//                 }
//                 a++;
//             }
//             f(k, a, x1)
//             {
//                 arr1[k] = 0;
//                 if (z2 > 0)
//                 {
//                     arr2[k] = 2;
//                     z2--;
//                 }
//                 else
//                 {
//                     arr2[k] = 0;
//                     x2--;
//                 }
//             }
//         }
//         f(i, 0, size)
//         {
//             if (arr1[i] < arr2[i])
//             {
//                 arr3[i] = -(arr1[i] * arr2[i]);
//             }
//             else if (arr1[i] > arr2[i])
//             {
//                 arr3[i] = (arr1[i] * arr2[i]);
//             }
//             else
//                 arr3[i] = 0;
//         }
//         int sum = 0;

//         f(i, 0, size)
//         {
//             printf("arr3[%d] : %d \n", i, arr3[i]);
//             sum += arr3[i];
//             printf("%d \n", sum);
//         }
//     }
// }

// ****************************

// #include <bits/stdc++.h>
// using namespace std;
// int n, k;
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         scanf("%d%d", &n, &k);
//         printf("%d\n", k > n ? k - n : (n + k) % 2);
//     }
// }

// ****************************

// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int x1, x2, y1, y2, z1, z2;
//         cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
//         cout << 2 * min(z1, y2) - 2 * max(z2 - z1 + min(z1, y2) - x1, 0) << endl;
//     }
// }