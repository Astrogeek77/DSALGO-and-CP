#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Tnode
{
public:
    int data;
    Tnode *left;
    Tnode *right;
    Tnode(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void printPreorder(Tnode *node)
{
    // root left right
    if (node == NULL)
        return;

    cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

void printInorder(Tnode *node)
{
    // left root right
    if (node == NULL)
        return;

    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

void printPostorder(Tnode *node)
{
    // left right root
    if (node == NULL)
        return;

    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << " ";
}

void printLevelorder(Tnode *node)
{
    // level by level
    // Breadth First Search
    if (node == NULL)
        return;

    queue<Tnode *> queue;
    queue.push(node);
    Tnode *temp;

    while (queue.empty() == false)
    {
        temp = queue.front();
        cout << temp->data << " ";

        if (temp->left != NULL)
            queue.push(temp->left);
        if (temp->right != NULL)
            queue.push(temp->right);
        queue.pop();
    }
}

bool printGivenLevel(Tnode *node, int level)
{
    if (node == NULL)
    {
        return false;
    }

    if (level == 1)
    {
        cout << node->data << " ";
        return true;
    }

    bool left = printGivenLevel(node->left, level - 1);
    bool right = printGivenLevel(node->right, level - 1);

    return left || right;
}

void printLevelOrderTraversal(Tnode *node)
{
    int level = 1;
    while (printGivenLevel(node, level))
    {
        level++;
    }
}

void iterativePreorder(Tnode *node)
{
    // root left right

    // we traverse through and simultaneously print the node we push to stack, 
    // we push right before left so that left comes out first

    if (node == NULL)
        return;

    stack<Tnode *> stack;
    stack.push(node);

    while (stack.empty() == false)
    {
        Tnode *temp = stack.top();
        cout << temp->data << ", ";
        stack.pop();

        // right is pushed first so that left is processed first
        if (temp->right)
            stack.push(temp->right);
        if (temp->left)
            stack.push(temp->left);
    }
}

void iterativeInorder(Tnode *node)
{
    // left root right

    // we traverse through left until node->left becomes null and then print the last node,
    //  its parent and move to its right

    if (node == NULL)
        return;

    stack<Tnode *> stack;
    Tnode *current = node;

    while (current != NULL || stack.empty() == false)
    {
        while (current != NULL)
        {
            stack.push(current);
            current = current->left;
        }

        current = stack.top();
        cout << current->data << " ";
        stack.pop();

        current = current->right;
    }
}

void IterativePostorder(Tnode *node)
{
    // left right root

    // we traverse using two stacks here we push the root to stack1 and then its left and right children and 
    // pop the stack1 top and push it to stack 2, continuing this process we get a post order traversal when pop 
    // elements in LIFO fashion from stack2

    if (node == NULL)
        return;

    stack<Tnode *> stack1;
    stack<Tnode *> stack2;

    Tnode *temp;

    stack1.push(node);

    while (!stack1.empty())
    {
        temp = stack1.top();
        stack1.pop();
        stack2.push(temp);

        if (temp->left != NULL)
            stack1.push(temp->left);
        if (temp->right != NULL)
            stack1.push(temp->right);
    }

    while (!stack2.empty())
    {
        temp = stack2.top();
        stack2.pop();
        cout << temp->data << " ";
    }
}

void IterativePostorder2(Tnode *node){
    // left right root
    // using 1 stack only

    // we traverse throught the nodes and go as left as posible then look for right child
    // next we reapeat the above step on the right child
    // once right child of a node is null we print node and check if its parents and print them
    // continuing these steps we get the post order traversal

    if(node == NULL) return;

    stack<Tnode *> st;
    st.push(node);

    Tnode *current = node;

    while(!st.empty() && current != NULL){
        while(current != NULL){
            st.push(current);
            current = current->left;
        }

        Tnode *temp = st.top()->right;
        if(temp == NULL){
            temp = st.top();
            st.pop();
            cout << temp->data << ", ";
            while(!st.empty() && temp == st.top()->right){
                temp = st.top();
                st.pop();
                cout << temp->data << ", ";
            }
        }
        else current = temp;
    }
}

int IterativeCalcHeight(Tnode *node)
{
    if (node == NULL)
        return 0;

    queue<Tnode *> queue;
    int height = 0;
    int nodeCount = 0;
    Tnode *current;

    queue.push(node);
    while (!queue.empty())
    {
        int nodeCount = queue.size();
        height++;

        while (nodeCount--)
        {
            current = queue.front();

            if (current->left != NULL)
                queue.push(current->left);
            if (current->right != NULL)
                queue.push(current->right);

            queue.pop();
        }
    }
    return height;
}

int maxDepth(Tnode *node)
{
    if (node == NULL)
        return 0;
    else
    {
        int leftDepth = maxDepth(node->left);
        int rightDepth = maxDepth(node->right);

        if (leftDepth < rightDepth)
            return (leftDepth + 1);
        else
            return (rightDepth + 1);

        // cout << leftDepth << rightDepth << endl;
    }
    // return (max(leftDepth, rightDepth) + 1);
}

int main()
{
    Tnode *root = new Tnode(7);
    root->left = new Tnode(9);
    root->right = new Tnode(10);
    root->left->left = new Tnode(3);
    root->left->right = new Tnode(4);
    root->right->left = new Tnode(2);
    root->right->right = new Tnode(8);

    // Traversals

    // cout << "\nPreorder traversal of binary tree is \n";
    // printPreorder(root);

    // cout << "\nInorder traversal of binary tree is \n";
    // printInorder(root);

    // cout << "\nPostorder traversal of binary tree is \n";
    // printPostorder(root);

    // cout << "\nIterative Preorder traversal of binary tree is \n";
    // iterativePreorder(root);

    // cout << "\nIterative Inorder traversal of binary tree is \n";
    // iterativeInorder(root);

    cout << "\nIterative Postorder traversal (using 2 stacks) of binary tree is \n";
    IterativePostorder(root);

    cout << "\nIterative Postorder traversal (using 1 stack) of binary tree is \n";
    IterativePostorder(root);

    // cout << "\nLevel Order traversal of binary tree is \n";
    // printLevelOrderTraversal(root);

    // cout << "\nIterative Level Order traversal of binary tree is \n";
    // printLevelorder(root);

    // Operations

    // cout << "\nIterative Calc Height of the Tree is: ";
    // cout << IterativeCalcHeight(root) << endl;

    // cout << "\nCalc Depth of the Tree is: ";
    // cout << maxDepth(root) << endl;

    return 0;
}