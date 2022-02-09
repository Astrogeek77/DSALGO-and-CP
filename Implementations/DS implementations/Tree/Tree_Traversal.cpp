#include <bits/stdc++.h>
#include <iostream>
#define MAX = 100;
using namespace std;

vector<int> result;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void DFT(Node *root)
{
    // root left right
    // Preorder Traversal

    if (root == NULL)
        return;

    stack<Node *> stack;
    stack.push(root);

    while (stack.empty() == false)
    {
        Node *current = stack.top();
        // result.push_back(current->data);
        cout << current->data << ", ";
        stack.pop();

        if (current->right)
            stack.push(current->right);
        if (current->left)
            stack.push(current->left);
    }
}

void DFTRecursive(Node *root)
{
    // root left right
    if (root == NULL)
        return;

    cout << root->data << ", ";
    DFTRecursive(root->left);
    DFTRecursive(root->right);
}

void BFT(Node *root){
    // level by level
    if (root == NULL) return;

    queue<Node *> queue;
    queue.push(root);

    while(!queue.empty()){
        Node *current = queue.front();
        cout << current->data << ", ";

        if(current->left) queue.push(current->left);
        if(current->right) queue.push(current->right);

        queue.pop();
    }
}

int main()
{
    Node *root = new Node(1); // root
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    // int e = new Node(5);
    /*
         1
        / \
       2   3
      / \ / \
     4  5 6  7
    */

    cout << "\nDepth First traversal of binary tree is \n";
    DFT(root);
    cout << "\nDepth First traversal (Recursive) of binary tree is \n";
    DFTRecursive(root);
    cout << "\nBreadth First traversal of binary tree is \n";
    BFT(root);
}