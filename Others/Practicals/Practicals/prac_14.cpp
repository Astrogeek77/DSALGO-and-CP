#include <bits/stdc++.h>
using namespace std;
int target;
vector<vector<int>> subsets;
void backtrack(vector<int> &vec, vector<int> &soln, int i, int sum)
{
    if (sum == target)
    {
        subsets.push_back(soln);
        return;
    }
    if (i == vec.size())
        return;
    backtrack(vec, soln, i + 1, sum);
    soln.push_back(vec[i]);
    backtrack(vec, soln, i + 1, sum + vec[i]);
    soln.pop_back();
}
int main()
{
    int n;
    cout << "Enter no. of elements:\n";
    cin >> n;
    vector<int> vec(n), soln;
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    cout << "Enter target sum:\n";
    cin >> target;
    backtrack(vec, soln, 0, 0);
    cout << "\nSubsets that add up to the target:\n";
    for (auto &v : subsets)
    {
        for (auto &x : v)
            cout << x << " ";
        cout << "\t";
    }
}
