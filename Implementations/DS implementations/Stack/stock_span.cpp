#include <bits/stdc++.h>
using namespace std;

void calculateSpan(int price[], int n, int S[])
{
    S[0] = 1;

    for (int i = 1; i < n; i++)
    {
        S[i] = 1;
        for (int j = i - 1; (j >= 0) && (price[i] >= price[j]); j--)
            S[i]++;
    }
}

void calcSpanUsingStack(int price[], int n, int S[])
{
    stack<int> stack;
    stack.push(0);

    S[0] = 1;

    for (int i = 1; i < n; i++)
    {
        while (!stack.empty() && price[stack.top()] < price[i])
            stack.pop();

        S[i] = (stack.empty()) ? (i + 1) : (i - stack.top());

        stack.push(i);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int price[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(price) / sizeof(price[0]);
    int S[n];

    // calculateSpan(price, n, S);
    calcSpanUsingStack(price, n, S);
    printArray(S, n);

    return 0;
}

// Time Complexity: O(n). It seems more than O(n) at first look. If we take a closer look, we can observe that every element of the array is added and removed from the stack at most once. So there are total 2n operations at most. Assuming that a stack operation takes O(1) time, we can say that the time complexity is O(n).
// Auxiliary Space: O(n) in worst case when all elements are sorted in decreasing order.