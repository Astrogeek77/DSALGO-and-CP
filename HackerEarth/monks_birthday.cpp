#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        set<string> list;
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            string str;
            cin >> str;
            list.insert(str);
        }

        for (auto &value : list)
        {
            cout << value << endl;
        }
    }
}