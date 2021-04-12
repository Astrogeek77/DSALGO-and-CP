#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

#define ffor(i, a, b) for (int i = a; i < b; i++)
#define bfor(i, a, b) for (int i = a; i > b; i--)
#define sh short
#define us unsigned
#define ll long long
#define ld long double

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T, n, num1, num2, x;
    char z;
    bool checker;
    string s1, s2 = "", s3 = "hello";
    cin >> T;
    while (T--)
    {
        cin >> n;
        num1 = 0;
        s2 = "";
        ffor(i, 0, n)
        {
            cin >> s1;
            s2 += s1;
        }
        sort(s2.begin(), s2.end());

        num1 = s2.length();

        if (num1 % n != 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            x = 0;
            num2 = 0;
            checker = true;
            ffor(i, 0, num1)
            {
                if (s2[x] == s2[i])
                {
                    num2++;
                }
                else
                {
                    if (num2 % n != 0)
                    {
                        cout << "NO" << endl;
                        checker = false;
                        break;
                    }
                    x = i;
                    num2 = 1;
                }
            }
            if (checker)
            {
                cout << "YES" << endl;
            }
        }
    }
    return 0;
}