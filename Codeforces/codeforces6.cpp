#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int arr[n];
        vector<int> myVec;
        int a = 0;
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        for (int j = 0; j < n; j++)
        {
            for (int k = j + 1; k < n - i; k++)
            {
                if (arr[k] != arr[k + 1])
                {
                    myVec[a + 1] = arr[k] + arr[k + 1];
                    a++;
                }
                else
                {
                    myVec[a + 1] = arr[k];
                }
            }
        }
    }
    return 0;
}

#include <cstdio>
#include <iostream>
using namespace std;
int t, n, a[200001];
int main()
{
    scanf("%d", &t);
    while ((t--) > 0)
    {
        scanf("%d", &n);
        bool flag = false;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        for (int i = 2; i <= n; i++)
        {
            if (a[i] != a[1])
            {
                flag = true;
                break;
            }
        }
        printf("%d\n", flag ? 1 : n);
    }
    return 0;
}
