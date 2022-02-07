#include <bits/stdc++.h>
using namespace std;

char printFrequency(string str)
{
    map<char, int> M;
    for (int i = 0; str[i]; i++)
    {

        if (M.find(str[i]) == M.end())
        {
            M.insert(make_pair(str[i], 1));
        }

        else
        {
            M[str[i]]++;
        }
    }

    for (auto &it : M)
    {
        cout << it.first << ' ' << it.second << '\n';
    }
    // return M[0];
}

int main()
{
    string str;
    cin >> str;
    printFrequency(str);
    return 0;
}
