// class Solution
// {
// public:
//     int trap(vector<int> &height)
//     {
//         int left = 0;
//         int right = height.size() - 1;
//         int water = 0;
//         int maxRight = 0, maxLeft = 0;

//         while (left < right)
//         {
//             if (height[left] < height[right])
//             {
//                 if (height[left] >= maxLeft)
//                 {
//                     maxLeft = height[left];
//                 }
//                 else
//                 {
//                     water += maxLeft - height[left];
//                 }
//                 left++;
//             }
//             else
//             {
//                 if (height[right] >= maxRight)
//                 {
//                     maxRight = height[right];
//                 }
//                 else
//                 {
//                     water += maxRight - height[right];
//                 }
//                 right--;
//             }
//         }
//         return water;
//     }
// };

int trap(vector<int> &height)
{
    if (height.empty())
        return 0;
    int ans = 0;
    int size = height.size();
    vector<int> left_max(size), right_max(size);
    left_max[0] = height[0];
    for (int i = 1; i < size; i++)
    {
        left_max[i] = max(height[i], left_max[i - 1]);
    }
    right_max[size - 1] = height[size - 1];
    for (int i = size - 2; i >= 0; i--)
    {
        right_max[i] = max(height[i], right_max[i + 1]);
    }
    for (int i = 1; i < size - 1; i++)
    {
        ans += min(left_max[i], right_max[i]) - height[i];
    }
    return ans;
}