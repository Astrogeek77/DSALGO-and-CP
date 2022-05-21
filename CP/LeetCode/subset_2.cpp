// class Solution
// {
// public:
//     void func(int freq[], vector<int> &a, vector<int> &nums, vector<vector<int>> &ans)
//     {
//         if (a.size() == nums.size())
//         {
//             ans.push_back(a);
//             return;
//         }
//         for (int i = 0; i < nums.size(); i++)
//         {
//             if (!freq[i])
//             {
//                 freq[i] = 1;
//                 a.push_back(nums[i]);
//                 func(freq, a, nums, ans);
//                 freq[i] = 0;
//                 a.pop_back();
//             }
//         }
//     }

//     vector<vector<int>> permute(vector<int> &nums)
//     {
//         vector<vector<int>> ans;
//         vector<int> a;
//         int freq[nums.size()];
//         for (int i = 0; i < nums.size(); i++)
//             freq[i] = 0;
//         func(freq, a, nums, ans);
//         return ans;
//     }
// };

class Solution
{
public:
    void func(int i, vector<int> &nums, vector<vector<int>> &ans)
    {
        if (i == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for (int j = i; j < nums.size(); j++)
        {
            swap(nums[i], nums[j]);
            func(j + 1, a, nums, ans);
            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> a;
        func(0, nums, ans);
        return ans;
    }
};