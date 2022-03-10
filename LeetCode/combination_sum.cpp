class Solution
{
public:
    void printSubsequnce5(int i, vector<int> &a, vector<int> &candidates, int target, vector<vector<int>> &ans)
    {
        if (i == candidates.size())
        {
            if (target == 0)
            {
                ans.push_back(a);
            }
            return;
        }
        if (candidates[i] <= target)
        {
            a.push_back(candidates[i]);
            printSubsequnce5(i, a, candidates, target - candidates[i], ans);
            a.pop_back();
        }
        printSubsequnce5(i + 1, a, candidates, target, ans);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> a;
        printSubsequnce5(0, a, candidates, target, ans);
        return ans;
    }
};

class Solution
{
public:
    void printSubsequnce5(int i, vector<int> &a, vector<int> &candidates, int target, vector<vector<int>> &ans)
    {
        if (target == 0)
        {
            ans.push_back(a);
            return;
        }

        for (int j = i; j < candidates.size(); j++)
        {
            if (j > i && candidates[j] == candidates[j - 1])
                continue;
            if (candidates[j] > target)
                break;
            a.push_back(candidates[j]);
            printSubsequnce5(j + 1, a, candidates, target - candidates[j], ans);
            a.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> a;
        printSubsequnce5(0, a, candidates, target, ans);
        return ans;
    }
};