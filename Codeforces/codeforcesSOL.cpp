#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int r, g, b, w;
        cin >> r >> g >> b >> w;
        if (r % 2 + g % 2 + b % 2 + w % 2 < 2 || r > 0 && g > 0 && b > 0 && ((r + 1) % 2 + (g + 1) % 2 + (b + 1) % 2 + (w + 1) % 2 < 2))
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
}
