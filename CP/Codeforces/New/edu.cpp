// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int x, y;
//         cin >> x >> y;
//         auto p = pow(x, 2) + pow(y, 2);
//         // cout << "Power: " << p << endl;
//         long double sqt = sqrt(p);
//         // cout << "SQRT: " << sqt << endl;
//         // bool val = *(typeid(sqt).name()) == 'i';
//         // cout << "Integer: " << val << endl;
//         if (x == 0 and y == 0)
//             cout << 0 << endl;
//         else if (x == 0 or y == 0 or (sqt - floor(sqt) == 0))
//             cout << 1 << endl;
//         else
//             cout << 2 << endl;
//     }
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         long long int n, B, x, y;
//         cin >> n >> B >> x >> y;
//         long long int sum = 0;
//         long long int result = 0;
//         while (n != 0)
//         {
//             if (sum + x <= B)
//             {
//                 sum = sum + x;
//             }
//             else {
//                 sum = sum - y;
//             }
//             n--;
//             // cout << "SUM: " << sum << endl;
//             result = result + sum;
//             // cout << "RESULT: " << result << endl;
//         }
//         cout << result << endl;
//     }
// }

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        if ((a == 0 and b == 0) or (a == 0 and b >= 1))
            cout << 1 << endl;
        else if (a >= 1 and b == 0)
        {
            cout << a + 1 << endl;
        }
        else
        {
            cout << (a + 2 * b) + 1 << endl;
        }
    }
}