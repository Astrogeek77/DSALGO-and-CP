#include <bits/stdc++.h>
#define I INT_MAX
using namespace std;
int main()
{
    int n = 4, c[n + 1][n + 1] = {
                   {0, 0, 0, 0, 0},
                   {0, 0, 30, I, 70},
                   {0, 80, 0, 20, I},
                   {0, 50, I, 0, 10},
                   {0, 20, I, I, 0}};
    unordered_map<int, string> mp{
        {1, "LDH"},
        {2, "AMT"},
        {3, "PAT"},
        {4, "ROP"}};
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (c[i][k] != I && c[k][j] != I)
                    c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
    cout << "\tLDH\tAMT\tPAT\tROP\n";
    for (int i = 1; i <= n; i++)
    {
        cout << mp[i] << "\t";
        for (int j = 1; j <= n; j++)
            cout << c[i][j] << "\t";
        cout << "\n";
    }
}
