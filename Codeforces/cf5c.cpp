#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        int x[n];
        int count = 0;
        int k = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for (int i = 0; i < n; i++)
        {
            if (arr[i + 1] < arr[i])
            {
                x[k] = arr[i];
                k++;
            }
        }

        for (int i = 0; i < k; i++)
        {
            if (x[i + 1] < x[i])
            {
                x[i + 1]++;
            }
            else
            {
                x[i]++;
                x[i + 1]++;
            }
        }
        printf("%d\n", count);
    }
}

#define IOS                          
    {                                
        ios::sync_with_stdio(false); 
        cin.tie(0);                  
        cout.tie(0);                 
    }
#define ll long long

int main()
{
    IOS;
    ll T;
    cin >> T;
    while (T--)
    {
        ll n;
        cin >> n;
        ll a[n];
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        ll ans = 0;
        for (ll i = 0; i < n - 1; i++)
            ans += max(a[i] - a[i + 1], 0ll);
        cout << ans << "\n";
    }
}