#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        string s;
        cin >> s;
        s += '0';
        int x[s.size()];
        int m = 0, z = 0;

        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] != '1')
            {
                x[z] = m;
                z++;
                m = 0;
            }
            else
            {
                m++;
            }
        }
        long int num = 0;
        sort(x, x + z);

        for (int i = z - 1; i > -1; i -= 2)
        {
            num += x[i];
        }
        cout << num << endl;
    }
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {

//         string s;
//         cin >> s;
//         s += '0';
//         int x[s.size()];
//         int count = 0;
//         int k = 0;
//         for (int i = 0; i < s.size(); i++)
//         {
//             if (s[i] != '1')
//             {
//                 x[k] = count;
//                 k++;
//                 count = 0;
//             }
//             else
//             {
//                 count++;
//             }
//         }
//         long int s1 = 0;
//         sort(x, x + k);

//         for (int i = k - 1; i > -1; i -= 2)
//         {
//             s1 += x[i];
//         }
//         cout << s1 << endl;
//     }

//     return 0;
// }
