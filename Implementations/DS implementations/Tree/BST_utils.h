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

void printVector(vector<int> v)
{
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}

// To insert a node in the BST

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

// to search a node in the BST

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

// Inorder traversal of the node

void inorder(BST *node, vector<int> &in)
{
    // left root right
    if (node == NULL)
        return;

    inorder(node->left, in);
    in.push_back(node->data);
    inorder(node->right, in);
}

void inorderTraversal(BST *node)
{
    vector<int> in;
    inorder(node, in);
    printVector(in);
}

void preorder(BST *node, vector<int> &pre)
{
    if (node == NULL)
        return;

    pre.push_back(node->data);
    preorder(node->left, pre);
    preorder(node->right, pre);
}

void preorderTraversal(BST *node)
{
    vector<int> pre;
    preorder(node, pre);
    printVector(pre);
}

// count the total nodes of a BST

int countNodes(BST *node)
{
    if (node == NULL)
        return 0;
    return 1 + countNodes(node->left) + countNodes(node->right);
}

// return node with minimum value in BST

BST *minValueNode(BST *node)
{
    BST *curr = node;

    while (curr->left != NULL)
        curr = curr->left;

    return curr;
}

// Delete a node in BST, using recursion

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

// Generate a BST from a given Preorder

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

// Validate a given BST

// bool checkBST2(BST *root, int min, int max)
// {
//     int d = root->data;
//     if (root == NULL)
//         return true;

//     if (root->data <= max || root->data >= min)
//         return false;

//     return checkBST(root->left, min, d - 1) && checkBST(root->right, d + 1, max);
// }

bool checkBST(BST *root, int min, int max)
{
    if (root == NULL)
        return true;

    if (root->data <= max || root->data >= min)
        return false;

    return checkBST(root->left, min, root->data) && checkBST(root->right, root->data, max);
}

// find the last right for a node

BST *findLastRight(BST *root)
{
    if (root->right == NULL)
    {
        return root;
    }
    return findLastRight(root->right);
}

// helper func for deleteing a node iteratively

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

// deleteing a node in BST iteratively

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

// get ceil of a node in BST

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

// get Floor of a node in BST

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

// Kth smallest element in BST

int KthSmallest(BST *node, int k)
{
    if (node == NULL)
        return 0;
    if (k < 0 or k > countNodes(node))
        return -1;

    int count = 0;
    int ans = -1;

    // Morris Inorder
    BST *curr = node;
    while (curr)
    {
        if (!curr->left)
        {
            count++;
            if (count == k)
                ans = curr->data;
            curr = curr->right;
        }
        else
        {
            BST *prev = curr->left;
            while (prev->right && prev->right != curr)
            {
                prev = prev->right;
            }

            if (prev->right == NULL)
            {
                prev->right = curr;
                curr = curr->left;
            }
            else
            {
                prev->right = NULL;
                count++;
                if (count == k)
                    ans = curr->data;
                curr = curr->right;
            }
        }
    }
    return ans;
}

// Kth largest element in BST

int KthLargest(BST *node, int k)
{
    if (node == NULL)
        return 0;
    if (k < 0 or k > countNodes(node))
        return -1;

    int count = 0;
    int ans = -1;

    int maxi = countNodes(node) + 1;

    // Morris Inorder
    BST *curr = node;
    while (curr)
    {
        if (!curr->left)
        {
            count++;
            if (count == (maxi - k))
                ans = curr->data;
            curr = curr->right;
        }
        else
        {
            BST *prev = curr->left;
            while (prev->right && prev->right != curr)
            {
                prev = prev->right;
            }

            if (prev->right == NULL)
            {
                prev->right = curr;
                curr = curr->left;
            }
            else
            {
                prev->right = NULL;
                count++;
                if (count == (maxi - k))
                    ans = curr->data;
                curr = curr->right;
            }
        }
    }
    return ans;
}
BST *getLCA(BST *node, int val1, int val2)
{
    if (node == NULL || node->data == val1 || node->data == val2)
        return node;

    if (node->data > val1 and node->data > val2)
        return getLCA(node->left, val1, val2);

    if (node->data < val1 and node->data < val2)
        return getLCA(node->right, val1, val2);

    return node;
}

BST *buildTree1(vector<int> preorder, int preStart, int preEnd, vector<int> inorder, int inStart, int inEnd, map<int, int> map)
{
    if (preStart > preEnd or inStart > inEnd)
    {
        return NULL;
    }

    BST *root = new BST(preorder[preStart]);
    int inRoot = map[root->data];
    int numsLeft = inRoot - inStart;

    root->left = buildTree1(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, map);
    root->right = buildTree1(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, map);
    return root;
}

BST *constructTree1(vector<int> preorder)
{
    if (preorder.size() == 0)
        return NULL;
    vector<int> inorder = preorder;
    sort(inorder.begin(), inorder.end());
    map<int, int> map;

    for (int i = 0; i < inorder.size(); i++)
        map[inorder[i]] = i;

    BST *root = buildTree1(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, map);
    return root;
}

BST *constructTree2(vector<int> &preorder, int &i, int Bound)
{
    if (i == preorder.size() or preorder[i] > Bound)
        return NULL;
    BST *root = new BST(preorder[i++]);
    root->left = constructTree2(preorder, i, root->data);
    root->right = constructTree2(preorder, i, Bound);
    return root;
}

// Contruct BST from postorder and inorder
TreeNode* build(vector<int> &inorder, vector<int> &postorder, int &index, int inOrderStart, int inOrderEnd, int n, map< int, int> &nodeToIndex)
{
    //base case;
    if (index < 0 || inOrderStart > inOrderEnd) return NULL;

    int element = postorder[index--];
    TreeNode *root = new TreeNode(element);
    int position = nodeToIndex[element];

    root->right = build(inorder, postorder, index, position + 1, inOrderEnd, n, nodeToIndex);
    root->left = build(inorder, postorder, index, inOrderStart, position - 1, n, nodeToIndex);
    
    return root;
}

TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder)
{
    int n = inorder.size();
    int postOrderIndex = n - 1;

    map<int, int> nodeToIndex;
    for (int i = 0; i < n; i++)
    {
        nodeToIndex[inorder[i]] = i;
    }

    TreeNode *ans = build(inorder, postorder, postOrderIndex, 0, n - 1, n, nodeToIndex);
    return ans;
}

BST *inorderSuccessor1(BST *node, int val)
{
    if (node == NULL)
        return NULL;
    BST *curr = node;

    while (curr)
    {
        if (!curr->left)
        {
            if (curr->data > val)
                return curr;
            curr = curr->right;
        }
        else
        {
            BST *prev = curr->left;
            while (prev->right && prev->right != curr)
            {
                prev = prev->right;
            }

            if (prev->right == NULL)
            {
                prev->right = curr;
                curr = curr->left;
            }
            else
            {
                prev->right = NULL;
                if (curr->data > val)
                    return curr;
                curr = curr->right;
            }
        }
    }
    return NULL;
}

BST *inorderSuccessor2(BST *node, int val)
{
    if (node == NULL)
        return NULL;

    BST *suc = NULL;
    while (node != NULL)
    {
        if (node->data > val)
        {
            suc = node;
            node = node->left;
        }
        else
        {
            node = node->right;
        }
    }
    return suc;
}

BST *inorderPredecessor(BST *node, int val)
{
    if (node == NULL)
        return NULL;

    BST *pre = NULL;
    while (node != NULL)
    {
        if (node->data >= val)
        {
            node = node->left;
        }
        else
        {
            pre = node;
            node = node->right;
        }
    }
    return pre;
}

class BSTiterator
{
private:
    stack<BST *> stack2;
    stack<BST *> stack;

public:
    BSTiterator(BST *root)
    {
        pushAll(root);
        pushAll2(root);
    }

    bool hasNext() const { return (!stack.empty()); }
    bool hasBack() const { return (!stack2.empty()); }

    int next()
    {
        auto temp = stack.top();
        stack.pop();
        pushAll(temp->right);
        return temp->data;
    }

    int back()
    {
        auto temp = stack2.top();
        stack2.pop();
        pushAll2(temp->left);
        return temp->data;
    }

    void pushAll(BST *node)
    {
        while (node)
        {
            stack.push(node);
            node = node->left;
        }
    }

    void pushAll2(BST *node)
    {
        while (node)
        {
            stack2.push(node);
            node = node->right;
        }
    }
};

class BSTiterator2
{
private:
    bool isReverse = false;
    stack<BST *> stack;

public:
    BSTiterator2(BST *root, bool reverse = false)
    {
        isReverse = reverse;
        pushAll(root);
    }

    bool hasNext() const { return (!stack.empty()); }

    int next()
    {
        auto temp = stack.top();
        stack.pop();
        if (!isReverse)
            pushAll(temp->right);
        return temp->data;
    }

    void pushAll(BST *node)
    {
        while (node)
        {
            stack.push(node);
            if (!isReverse)
                node = node->left;
            else
                node = node->right;
        }
    }
};

pair<bool, pair<int, int>> twoSumBST(BST *node, int target)
{
    if (node == NULL)
        return {false, {-1, -1}};

    BSTiterator2 l(node);
    BSTiterator2 r(node, true);

    int i = l.next();
    int j = r.next();

    while (i < j)
    {
        if (i + j == target)
            return {true, {i, j}};
        else if (i + j < target)
            i = l.next();
        else
            j = r.next();
    }
    return {false, {-1, -1}};
}

// class Solution
// {
// private:
//     TreeNode *first;
//     TreeNode *prev;
//     TreeNode *middle;
//     TreeNode *last;

// private:
//     void inorder(TreeNode *root)
//     {
//         if (root == NULL)
//             return;

//         inorder(root->left);

//         if (prev != NULL && (root->val < prev->val))
//         {

//             // If this is first violation, mark these two nodes as
//             // 'first' and 'middle'
//             if (first == NULL)
//             {
//                 first = prev;
//                 middle = root;
//             }

//             // If this is second violation, mark this node as last
//             else
//                 last = root;
//         }

//         // Mark this node as previous
//         prev = root;
//         inorder(root->right);
//     }

// public:
//     void recoverTree(TreeNode *root)
//     {
//         first = middle = last = NULL;
//         prev = new TreeNode(INT_MIN);
//         inorder(root);
//         if (first && last)
//             swap(first->val, last->val);
//         else if (first && middle)
//             swap(first->val, middle->val);
//     }
// };


BST *largestBST(BST *node){

}