#include <bits/stdc++.h>

using namespace std;

// string isBalanced(string s)
// {
//     stack<char> st;

//     for (auto c : s)
//     {
//         switch (c)
//         {
//         case '{':
//         case '(':
//         case '[':
//             st.push(c);
//             break;
//         case '}':
//             if (st.empty() || (st.top() != '{'))
//             {
//                 return "NO";
//             }
//             st.pop();
//             break;
//         case ')':
//             if (st.empty() || (st.top() != '('))
//             {
//                 return "NO";
//             }
//             st.pop();
//             break;
//         case ']':
//             if (st.empty() || (st.top() != '['))
//             {
//                 return "NO";
//             }
//             st.pop();
//             break;
//         }
//     }

//     return st.empty() ? "YES" : "NO";
// }
unordered_map<char, int> m = {{'(', -1}, {'[', -2}, {'{', -3}, {')', 1}, {']', 2}, {'}', 3}};
string isBalanced(string s)
{
    stack<char> st;
    for (auto &bracket : s)
    {
        if (m[bracket] < 0)
        {
            st.push(bracket);
        }
        else
        {
            if (st.empty())
                return "NO";
            char top = st.top();
            st.pop();
            if (m[bracket] + m[top] != 0)
                return "NO";
        }
    }
    if (st.empty())
        return "YES";
    else
        return "NO";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << isBalanced(s) << endl;
    }
}