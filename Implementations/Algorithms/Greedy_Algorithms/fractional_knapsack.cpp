#include <bits/stdc++.h>
using namespace std;

double fractional_knapsack_greedy(int max, int v[], int wt[], int n)
{
    double ratio[n] = {};
    double x = 0.0;

    for (int i = 0; i < n; i++)
    {
        // Calaculating ratios and typecasting to double
        ratio[i] = (double)v[i] / (double)wt[i];
    }

    // Decreasing order
    sort(ratio, ratio + n, greater<int>());

    int weight = 0;

    for (int i = 1; i < n; i++)
    {
        if(wt[i] + weight <= max){
            x += 1;
            weight += wt[i];
        }
        else {
            x += ratio[i];
            weight = max;
            break;
        }



        // for (int k = 1; k < n; k++)
        // {
        //     if (wt[k] > capacity)
        //         break;

        //     x[k] = 1.0;
        //     capacity = capacity - wt[i];
        // }

        // if (i <= n)
        //     x[i] = capacity / wt[i];
    }
    return x;
}

int main()
{
    int val[] = {6, 10, 12};
    int wt[] = {1, 2, 3};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << "Value: " << fractional_knapsack_greedy(W, wt, val, n);
    return 0;
}