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

cout << "--------------------------------" << endl;

// #include <bits/stdc++.h>
// using namespace std;

// bool cmp(pair<int, string> a, pair<int, string> b)
// {
//     if (a.first != b.first)
//         return a > b;
//     return a.second < b.second;
// }

// int main()
// {
//     vector<pair<int, string>> v_p;
//     int T;
//     cin >> T;
//     while (T--)
//     {
//         string str;
//         int marks;
//         cin >> str >> marks;
//         v_p.push_back({marks, str});
//     }

//     sort(v_p.begin(), v_p.end(), cmp);

//     for (auto v : v_p)
//         cout << v.second << " " << v.first << endl;
// }