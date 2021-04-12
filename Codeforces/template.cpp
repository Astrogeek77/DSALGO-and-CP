
#include <bits/stdc++.h>

#define gc getchar //_unlocked
#define pc putchar //_unlocked
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppl pair<ll, ll>
#define bigint boost::multiprecision::cpp_int
#define finp                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define bc __builtin_popcountll
#define afor(i, a, b) for (int i = a; i <= b; ++i)
#define bfor(i, a, b) for (int i = a; i >= b; --i)
#define vi vector<int>
#define vpp vector<pp>
#define vll vector<ll>
#define fr first
#define se second

using namespace std;

const ll mod = 1e9 + 7;
const ll mod2 = 1999999973;
const ll inf = 1e18;
const int infs = 1e9 + 1000;
const int N = 100000;
const long double PI = acos(-1);

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        long int k;
        cin >> n;
        cin >> k;
        int arr[n];
        int arr2[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            arr2[i] = arr[i];
        }

        int a = sizeof(arr) / sizeof(arr[0]);

        if (k % 2 == 1)
        {
            sort(arr2, arr2 + a);

            for (int i = 0; i < a; i++)
            {
                arr[i] = arr2[a - 1] - arr[i];
                arr2[i] = arr2[a - 1] - arr2[i];
            }
            k--;
        }

        for (int i = 0; i < a; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}