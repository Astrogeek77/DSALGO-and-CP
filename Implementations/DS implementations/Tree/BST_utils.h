

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class BST
{
public:
    int data;
    BST *left;
    BST *right;
    BST(int data)
    {
        this->data = data;
        left = right = NULL;
    }

    BST()
    {
        this->data = 0;
        left = right = NULL;
    }
};

BST *insert(BST *root, int data)
{
    if (!root)
        return new BST(data);
    else if (root->data < data)
        root->right = insert(root->right, data);
    else
        root->left = insert(root->left, data);
    return root;
}

int search(BST *root, int key)
{
    int depth = 0;
    BST *temp = new BST;
    temp = root;
    while (temp != NULL)
    {
        depth++;
        if (temp->data == key)
            return depth;
        else if (temp->data > key)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return -1;
}

void inorder(BST *node)
{
    // left root right
    if (node == NULL)
        return;

    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

BST *minValueNode(BST *node)
{
    BST *curr = node;

    while (curr->left != NULL)
        curr = curr->left;

    return curr;
}

BST *deleteNode(BST *node, int key)
{
    if (node == NULL)
        return node;

    if (key < node->data)
        node->left = deleteNode(node->left, key);
    else if (key > node->data)
        node->right = deleteNode(node->right, key);
    else
    {
        if (node->left == NULL && node->right == NULL)
        {
            return NULL;
        }
        else if (node->left == NULL)
        {
            BST *temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL)
        {
            BST *temp = node->left;
            free(node);
            return temp;
        }

        BST *temp = minValueNode(node->right);
        node->data = temp->data;

        node->right = deleteNode(node->right, temp->data);
    }
    return node;
}

BST *BSTfromPreorder(vector<int> preorder)
{
    int size = preorder.size();

    if (size == 0)
        return NULL;
    BST *root = NULL;

    for (auto x : preorder)
    {
        root = insert(root, x);
    }
    return root;
}

bool checkBST(BST *root, int min, int max)
{
    int d = root->data;
    if (root == NULL)
        return true;

    if (root->data < max || root->data > min)
    {
        return false;
    }

    return checkBST(root->left, min, d - 1) && checkBST(root->right, d + 1, max);
}

BST *findLastRight(BST *root)
{
    if (root->right == NULL)
    {
        return root;
    }
    return findLastRight(root->right);
}

BST *helper(BST *root)
{
    if (root->left == NULL)
    {
        return root->right;
    }
    if (root->right == NULL)
    {
        return root->left;
    }
    BST *rightChild = root->right;
    BST *lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
}

BST *deleteNodeIterative(BST *root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->data == key)
        return helper(root);
    BST *temp = root;

    while (root != NULL)
    {
        if (root->data > key)
        {
            if (root->left != NULL and root->left->data == key)
            {
                root->left = helper(root->left);
                break;
            }
            else
            {
                root = root->left;
            }
        }
        else
        {
            if (root->right != NULL and root->right->data == key)
            {
                root->right = helper(root->right);
                break;
            }
            else
            {
                root = root->right;
            }
        }
    }
    return temp;
}

int getCeil(BST *node, int key)
{
    // Minimum Value greator than or equal to target
    if (node == NULL)
        return 0;
    int ceil = -1;
    while (node)
    {

        if (node->data == key)
        {
            ceil = node->data;
            return ceil;
        }
        else if (node->data < key)
            node = node->right;
        else
        {
            ceil = node->data;
            node = node->left;
        }
    }
    return ceil;
}

int getFloor(BST *node, int key)
{
    // Maximum Value smaller than or equal to target
    if (node == NULL)
        return 0;
    int floor = -1;
    while (node)
    {
        if (node->data == key)
        {
            floor = node->data;
            return floor;
        }
        else if (node->data < key)
        {
            floor = node->data;
            node = node->right;
        }
        else
        {
            node = node->left;
        }
    }
    return floor;
}
