// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         vector<int> chars(128);
//         int start = 0, end = 0;
//         int n = s.length();
//         int result = 0;

//         while(end < n){
//             char c = s[end];
//             chars[c]++;

//             while(chars[c] > 1){
//                 char c2 = s[start];
//                 chars[c2]--;
//                 start++;
//             }

//             result = max(result, end - start + 1);
//             end++;
//         }

//         return result;
//     }
// };

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> chars(128, -1);
        int start = 0, end = 0;
        int n = s.length();
        int result = 0;

        while (end < n)
        {
            char c = s[end];

            int index = chars[c];

            if (index != -1 && index >= start && index < end)
            {
                start = index + 1;
            }

            result = max(result, end - start + 1);
            chars[c] = end;
            end++;
        }

        return result;
    }
};