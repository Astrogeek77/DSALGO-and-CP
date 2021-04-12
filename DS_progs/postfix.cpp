#include <iostream>
#include <string>
#include <bits/stdc++.h>
#define MAX 20
using namespace std;

char stk[20];
int top = -1;

// function to insert value in stack and increment stack top by 1
void push(char oper)
{
    if (top == MAX - 1)
        cout << "stackOverflow!!";
    else
    {
        top++;
        stk[top] = oper;
    }
}

// Function to remove an item from stack. It decreases top by 1
char pop()
{
    char ch;
    if (top == -1)
        cout << "stackUnderflow!!!!";
    else
    {
        ch = stk[top];
        stk[top] = '\0';
        top--;
        return (ch);
    }
    return 0;
}

// set priority to a operation to distinguish
int priority(char alpha)
{
    if (alpha == '+' || alpha == '-')
        return (1);

    if (alpha == '*' || alpha == '/')
        return (2);

    if (alpha == '^')
        return (3);
    return 0;
}

// function to covert infix to postfix using insert and pop
string convert(string infix)
{
    int i = 0;
    // target string
    string postfix = "";
    while (infix[i] != '\0')
    {
        // Check for alphabets
        if (infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z')
        {
            postfix.insert(postfix.end(), infix[i]);
            i++;
        }
        // check for opening brackets
        else if (infix[i] == '(' || infix[i] == '{' || infix[i] == '[')
        {
            push(infix[i]);
            i++;
        }
        // check for closing brackets
        else if (infix[i] == ')' || infix[i] == '}' || infix[i] == ']')
        {
            if (infix[i] == ')')
            {
                while (stk[top] != '(')
                    postfix.insert(postfix.end(), pop());
                pop();
                i++;
            }
            if (infix[i] == ']')
            {
                while (stk[top] != '[')
                    postfix.insert(postfix.end(), pop());
                pop();
                i++;
            }
            if (infix[i] == '}')
            {
                while (stk[top] != '{')
                    postfix.insert(postfix.end(), pop());
                pop();
                i++;
            }
        }
        else
        {
            if (top == -1)
            {
                push(infix[i]);
                i++;
            }

            // less priority is poped
            else if (priority(infix[i]) <= priority(stk[top]))
            {
                postfix.insert(postfix.end(), pop());

                while (priority(stk[top]) == priority(infix[i]))
                {
                    postfix.insert(postfix.end(), pop());
                    if (top < 0)
                        break;
                }
                push(infix[i]);
                i++;
            }
            // greator priority is pushed
            else if (priority(infix[i]) > priority(stk[top]))
            {
                push(infix[i]);
                i++;
            }
        }
    }

    while (top != -1)
        postfix.insert(postfix.end(), pop());
    // END expression
    cout << "The converted postfix string is : " << postfix;
    return postfix;
}

// DRIVER function
int main()
{
    int cont;
    string infix, postfix;
    cout << "\nEnter the infix expression : ";
    cin >> infix;
    postfix = convert(infix);
    return 0;
}