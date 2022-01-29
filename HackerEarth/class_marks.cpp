#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int, multiset<string>> map;
    int T;
    cin >> T;
    while (T--)
    {
        string str;
        int marks;
        cin >> str >> marks;
        map[-marks].insert(str);
    }

    // auto it = --map.end();
    // while (true)
    // {
    //     auto &students = (*it).second;
    //     auto &marks = (*it).first;
    //     for (auto &student : students)
    //     {
    //         cout << student << " " << marks << endl;
    //     }
    //     if (it == map.begin())
    //         break;
    //     it--;
    // }

    for (auto it : map)
    {
        auto &students = (it).second;
        auto &marks = (it).first;
        for (auto &student : students)
        {
            cout << student << " " << -marks << endl;
        }
    }
}