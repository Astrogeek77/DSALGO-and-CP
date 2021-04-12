#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
    // int n, q;
    // scanf("%d", &n);
    // scanf("%d", &q);
    // int k;
    // vector<vector<int>> myVec;
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> k;
    //     // cout << "k = " << k << "\n";
    //     vector<int> myVec2;
    //     for (int j = 1; j <= k; j++)
    //     {
    //         int el;
    //         cin >> el;
    //         myVec2.push_back(el);
    //     }
    //     myVec.push_back(myVec2);
    // }
    // for (int i = 0; i < q; i++)
    // {
    //     int a = 0, b = 0;
    //     scanf("%d", &a);
    //     scanf("%d", &b);
    //     // cout << "a: " << a << "\n";
    //     // cout << "b: " << b << "\n";
    //     for (int j = 1; j <= myVec[i].size(); j++)
    //     {
    //         // if (i == a && j == b)
    //         // {
    //         //     cout << myVec[a][b] << "\n";

    //         // }
    //         printf("%d\n", myVec[a][b]);
    //         break;
    //     }
    // }
    // return 0;

    int n, q;
    scanf("%d", &n);
    scanf("%d", &q);
    int k;
    int *arr[100];
    int **arr2;
    
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        // cout << "k = " << k << "\n";
        arr2 = new int *[100];
        for (int j = 1; j <= k; j++)
        {
            int el;
            cin >> el;
            arr[n][k] = el;
        }
        // arr2[n].push_back(arr[n]);
    }
    for (int i = 0; i < q; i++)
    {
        int a = 0, b = 0;
        scanf("%d", &a);
        scanf("%d", &b);
        // cout << "a: " << a << "\n";
        // cout << "b: " << b << "\n";
        for (int j = 1; j <= myVec[i].size(); j++)
        {
            // if (i == a && j == b)
            // {
            //     cout << myVec[a][b] << "\n";

            // }
            printf("%d\n", myVec[a][b]);
            break;
        }
    }
    return 0;
}
