#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        long int k;
        cin >> n;
        cin >> k;
        int arr[n];
        int arr2[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            arr2[i] = arr[i];
        }

        int a = sizeof(arr) / sizeof(arr[0]);

        while (k >= 1)
        {
            sort(arr2, arr2 + a);

            for (int i = 0; i < a; i++)
            {
                arr[i] = arr2[a - 1] - arr[i];
                arr2[i] = arr2[a - 1] - arr2[i];
            }
            k--;
        }

        for (int i = 0; i < a; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

