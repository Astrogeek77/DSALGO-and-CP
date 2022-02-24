#include <bits/stdc++.h>
#include <iostream>
// #define MAX = 1e7+10;
using namespace std;

int MIN = INT_MIN;
int MAX = INT_MAX;

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

void BFT(Node *root)
{
    // level by level
    if (root == NULL)
        return;

    queue<Node *> queue;
    queue.push(root);

    while (!queue.empty())
    {
        Node *current = queue.front();
        cout << current->data << ", ";

        if (current->left)
            queue.push(current->left);
        if (current->right)
            queue.push(current->right);

        queue.pop();
    }
}

bool treeIncludes(Node *root, int key)
{
    if (root == NULL)
        return false;
    if (root->data == key)
        return true;

    queue<Node *> queue;
    queue.push(root);

    while (!queue.empty())
    {
        Node *current = queue.front();
        if (current->data == key)
            return true;

        if (current->left)
            queue.push(current->left);
        if (current->right)
            queue.push(current->right);

        queue.pop();
    }
    return false;
}

bool treeIncludesRecursive(Node *root, int key)
{
    if (root == NULL)
        return false;
    if (root->data == key)
        return true;

    return treeIncludes(root->left, key) || treeIncludes(root->right, key);
}

int treeSumRecursive(Node *root, int sum)
{
    if (root == NULL)
        return 0;
    sum += root->data + treeSumRecursive(root->left, sum) + treeSumRecursive(root->right, sum);
    return sum;
}

int treeSum(Node *root, int sum)
{
    // Breadth First Traversal
    if (root == NULL)
        return 0;

    queue<Node *> queue;
    queue.push(root);

    while (!queue.empty())
    {
        Node *current = queue.front();
        sum += current->data;

        if (current->left)
            queue.push(current->left);
        if (current->right)
            queue.push(current->right);

        queue.pop();
    }

    return sum;
}

int findMinRecursive(Node *root)
{
    if (root == NULL)
        return MAX;

    return min(findMinRecursive(root->left), min(findMinRecursive(root->right), root->data));
}

int findMaxRecursive(Node *root)
{
    if (root == NULL)
        return MIN;

    return max(findMaxRecursive(root->left), max(findMaxRecursive(root->right), root->data));
}

int findMin(Node *root)
{
    if (root == NULL)
        return MAX;

    queue<Node *> queue;
    int minvalue = root->data;
    queue.push(root);

    while (!queue.empty())
    {
        Node *current = queue.front();
        if (minvalue > current->data)
            minvalue = current->data;

        if (current->left)
            queue.push(current->left);
        if (current->right)
            queue.push(current->right);

        queue.pop();
    }
    return minvalue;
}

int maxRoottoLeafSum(Node *root)
{
    if (root == NULL)
        return MIN + 1000;
    if (root->left == NULL && root->right == NULL)
        return root->data;

    return max(maxRoottoLeafSum(root->left) + root->data, maxRoottoLeafSum(root->right) + root->data);
}

int minRoottoLeafSum(Node *root)
{
    if (root == NULL)
        return MAX - 1000;
    if (root->left == NULL && root->right == NULL)
        return root->data;

    return min(minRoottoLeafSum(root->left) + root->data, minRoottoLeafSum(root->right) + root->data);
}

int maxRoottoLeaf(Node *root)
{
    if (root == NULL)
        return MAX - 1000;
    if (root->left == NULL && root->right == NULL)
        return root->data;
    
    stack<Node *> stack;
    stack.push(root);

    while(!stack.empty()){
        
    }
}

int main()
{
    // Node *root = new Node(1); // root
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->right->left = new Node(6);
    // root->right->right = new Node(7);
    // int e = new Node(5);
    /*
         1
        / \
       2   3
      / \ / \
     4  5 6  7
    */

    /* Construct the following tree
               1
             /   \
            /     \
           2       3
          / \     / \
         8   4   5   6
            /   / \   \
          10   7   9   5
     */

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(8);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->left->right->left = new Node(10);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(9);
    root->right->right->right = new Node(5);

    cout << "\nDepth First traversal of binary tree is \n";
    DFT(root);

    cout << "\nDepth First traversal (Recursive) of binary tree is \n";
    DFTRecursive(root);

    cout << "\nBreadth First traversal of binary tree is \n";
    BFT(root);

    int key = 5;
    // cout << "\nEnter Element to Search: " << endl;
    // cin >> key;
    cout << endl;
    // treeIncludes(root, key) == true ? printf("Tree Contains %d", key) : printf("Tree Does not contain %d", key);
    treeIncludesRecursive(root, key) == true ? printf("Tree Contains %d", key) : printf("Tree Does not contain %d", key);
    cout << endl;

    int sum = 0;
    // sum = treeSumRecursive(root, sum);
    sum = treeSum(root, sum);
    cout << "The Tree Sum is: " << sum << endl;

    // cout << "The Smallest value in the tree is: " << findMin(root) << endl;
    cout << "The Smallest value in the tree is: " << findMinRecursive(root) << endl;
    cout << "The Largest value in the tree is: " << findMaxRecursive(root) << endl;

    cout << "The Max Root to Leaf Sum is: " << maxRoottoLeafSum(root) << endl;
    cout << "The Min Root to Leaf Sum is: " << minRoottoLeafSum(root) << endl;
}