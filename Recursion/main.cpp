#include <bits/stdc++.h>
using namespace std;

int func(int n)
{
    if (n < 1)
        return 0;
    return n + func(n - 1);
}

int fac(int n)
{
    if (n == 0)
        return 1;
    return n * fac(n - 1);
}

void reverseArr(int l, int a[], int r)
{
    if (l <= r)
        return;
    swap(a[l], a[r]);
    reverseArr(l + 1, a, r - 1);
}

void reverseArr2(int l, int a[], int size)
{
    if (l < size / 2)
        return;
    swap(a[l], a[size - l - 1]);
    reverseArr2(l + 1, a, size);
}

bool checkPalindrom(string &s, int i, int n)
{
    if (i > n / 2)
        return true;
    if (s[i] != s[n - i - 1])
        return false;
    checkPalindrom(s, i + 1, n);
}

void printVector(vector<int> v)
{
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}

int vectorSum(vector<int> v)
{
    int sum = 0;
    for (auto x : v)
        sum += x;
    return sum;
}

// rec func to reterun all the subsequences of a array
void printSubsequnce(int i, vector<int> &a, int arr[], int n)
{
    if (i == n)
    {
        printVector(a);
        return;
    }
    a.push_back(arr[i]);
    printSubsequnce(i + 1, a, arr, n);
    a.pop_back();
    printSubsequnce(i + 1, a, arr, n);
}

// rec func to print the pair that have sum equal to k in the array
void printSubsequnce2(int i, vector<int> &a, int arr[], int n, int sum, int k)
{
    if (i == n)
    {
        if (sum == k)
        {
            printVector(a);
        }
        return;
    }
    a.push_back(arr[i]);
    sum += arr[i];
    printSubsequnce2(i + 1, a, arr, n, sum, k);
    a.pop_back();
    sum -= arr[i];
    printSubsequnce2(i + 1, a, arr, n, sum, k);
}

// modification to print only one such pair and stop the process thereafter.
bool printSubsequnce3(int i, vector<int> &a, int arr[], int n, int sum, int k)
{
    if (i == n)
    {
        if (sum == k)
        {
            printVector(a);
            return true;
        }
        return false;
    }
    a.push_back(arr[i]);
    sum += arr[i];
    if (printSubsequnce3(i + 1, a, arr, n, sum, k) == true)
        return true;
    a.pop_back();
    sum -= arr[i];
    if (printSubsequnce3(i + 1, a, arr, n, sum, k) == true)
        return true;
    return false;
}

int printSubsequnce4(int i, vector<int> &a, int arr[], int n, int sum, int k)
{
    if (i == n)
    {
        if (sum == k)
        {
            // printVector(a);
            return 1;
        }
        return 0;
    }
    a.push_back(arr[i]);
    sum += arr[i];
    int l = printSubsequnce4(i + 1, a, arr, n, sum, k);
    a.pop_back();
    sum -= arr[i];
    int r = printSubsequnce4(i + 1, a, arr, n, sum, k);
    return l + r;
}

vector<vector<int>> printSubsequnce5(int i, vector<int> &a, vector<int> &candidates, int target, vector<vector<int>> &ans)
{
    if (i == candidates.size())
    {
        if (target == 0)
        {
            ans.push_back(a);
        }
    }
    if (candidates[i] < target)
    {
        a.push_back(candidates[i]);
        printSubsequnce5(i, a, candidates, target, ans);
        a.pop_back();
    }
    printSubsequnce5(i + 1, a, candidates, target, ans);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> a;
    ans = printSubsequnce5(0, a, candidates, target, ans);
    return ans;
}

int main()
{
    // cout << func(10) << endl;
    // cout << fac(5) << endl;

    // int a[5] = {1, 2, 3, 4, 5};
    // int size = sizeof(a) / sizeof(a[0]);

    // reverseArr(0, a, size);
    // for (int i = 0; i < size; i++)
    // {
    //     cout << a[i] << " ";
    // }

    // reverseArr2(0, a, size);
    // for (int i = 0; i < size; i++)
    // {
    //     cout << a[i] << " ";
    // }

    string s = "madam";
    cout << "isPalindrom: " << checkPalindrom(s, 0, s.size()) << endl;

    int arr[] = {1, 2, 1};
    int n = 3;
    int i = 0;
    int sum = 2;
    vector<int> a;
    // printSubsequnce(i, a, arr, n);
    // printSubsequnce2(i, a, arr, n, 0, sum);
    // printSubsequnce3(i, a, arr, n, 0, sum);
    cout << "Number of Subsequences: " << printSubsequnce4(i, a, arr, n, 0, sum) << endl;

    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> aa = combinationSum(candidates, target);

    for (auto x : aa)
    {
        printVector(x);
    }
}