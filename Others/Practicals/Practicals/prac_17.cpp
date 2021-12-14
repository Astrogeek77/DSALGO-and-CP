#include <bits/stdc++.h>
#define ll long long
using namespace std;

void bruteForce(string &txt, string &pat)
{
    int m = pat.size(), n = txt.size();
    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
            if (txt[i + j] != pat[j])
                break;
        if (j == m)
            cout << "Pattern matches at " << i << "\n";
    }
}
void rabinKarp(string &txt, string &pat)
{
    ll i, m = pat.size(), n = txt.size(), p = 0, t = 0;
    for (i = 0; i < m; i++)
    {
        p = 10 * p + (pat[i] - 'A' + 1);
        t = 10 * t + (txt[i] - 'A' + 1);
    }
    for (i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            ll j;
            for (j = 0; j < m; j++)
                if (txt[i + j] != pat[j])
                    break;
            if (j == m)
                cout << "Pattern matches at " << i << "\n";
        }
        if (i < n - m)
            t = (t - pow(10, m - 1) * (txt[i] - 'A' + 1)) * 10 +
                (txt[i + m] - 'A' + 1);
    }
}
void computeLPS(string &pat, int m, vector<int> &lps)
{
    int len = 0, i = 1;
    lps[0] = 0;
    while (i < m)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
                len = lps[len - 1];
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
void KMP(string &txt, string &pat)
{
    int m = pat.size(), n = txt.size();
    vector<int> lps(m);
    computeLPS(pat, m, lps);
    int i = 0, j = 0;
    while (i < n)
    {
        if (txt[i] == pat[j])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            cout << "Pattern matches at " << i - j << "\n";
            j = lps[j - 1];
        }
        else if (i < n && txt[i] != pat[j])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}
void boyerMoore(string &txt, string &pat)
{
    unordered_map<char, int> mp;
    int m = pat.size(), n = txt.size();
    for (int i = 0; i < m; i++)
        mp[pat[i]] = max(1, m - i - 1);
    int i = 0, j, skips;
    while (i <= n - m)
    {
        skips = 0;
        j = m - 1;
        while (j >= 0)
        {
            if (txt[i + j] == pat[j])
                j--;
            else
            {
                if (mp[txt[i + j]])
                    skips = mp[txt[i + j]];
                else
                    skips = m;
                break;
            }
        }
        if (skips == 0)
        {
            cout << "Pattern matches at " << i << "\n";
            i += m;
        }
        else
            i += skips;
    }
}
void capitalize(string &txt, string &pat)
{
    for (char &c : txt)
        c &= '_';
    for (char &c : pat)
        c &= '_';
}
int main()
{
    string txt, pat;
    cout << "Enter Text:\n";
    getline(cin, txt);
    cout << "Enter Pattern:\n";
    getline(cin, pat);
    capitalize(txt, pat);
    while (true)
    {
cout<<"Enter 1 for Brute-Force, 2 for Rabin-Karp, 3 for KMP, 4 for Boyer-Moore and 5 to Exit:\n";

int c;
cin >> c;
switch (c)
{
case 1:
    bruteForce(txt, pat);
    break;
case 2:
    rabinKarp(txt, pat);
    break;
case 3:
    KMP(txt, pat);
    break;
case 4:
    boyerMoore(txt, pat);
    break;
case 5:
    return 0;
default:
    cout << "INVALID INPUT: Try again.";
}
    }
}
