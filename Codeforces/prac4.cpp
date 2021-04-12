#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll i, j, test, n, m, x, a, b, c, d, t, k, y, ans, ele;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll t;
    cin >> t;
    while(t--){
        ll x,y;
        cin >> x >> y;

        if(x <= y)
            cout << x + y << endl;
        else if(x > y)
            cout << 2 * x - y << endl;
        else if( x == 0 )
    }
}
