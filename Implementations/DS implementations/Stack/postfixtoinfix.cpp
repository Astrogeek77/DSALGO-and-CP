#include <bits/stdc++.h>
using namespace std;

bool isOperand(char x)
{
    // to distinguish between operator and operand
   return (x >= 'a' && x <= 'z') ||
          (x >= 'A' && x <= 'Z');
}

string getInfix(string str)
{
    stack<string> stack;
 
    for (int i=0; str[i]!='\0'; i++)
    {
        if (isOperand(str[i]))
        {
           string s(1, str[i]); // getting and pushing operand to stack
        //    cout << op << endl;
           stack.push(s);
        }
        else // assuming that given string is a valid postfix
        {
            string s1 = stack.top();
            stack.pop();
            string s2 = stack.top();
            stack.pop();
            stack.push("(" + s2 + str[i] +
                   s1 + ")");
        }
    }
    // cout << stack.top();
    return stack.top();
}

int main()
{
    string exp = "abcdefgh+*-/-*+";
    cout << getInfix(exp);
    return 0;
}

