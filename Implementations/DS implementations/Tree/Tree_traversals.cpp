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
    // using 2 stacks

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

void IterativePostorder2(Tnode *node)
{
    // left right root
    // using 1 stack only

    // we traverse throught the nodes and go as left as posible then look for right child
    // next we reapeat the above step on the right child
    // once right child of a node is null we print node and check if its parents and print them
    // continuing these steps we get the post order traversal

    if (node == NULL)
        return;

    stack<Tnode *> st;
    // st.push(node);

    Tnode *current = node;

    while (!st.empty() || current != NULL)
    {
        if (current != NULL)
        {
            st.push(current);
            current = current->left;
        }
        else
        {
            Tnode *temp = st.top()->right;
            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                cout << temp->data << " ";
                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    cout << temp->data << " ";
                }
            }
            else
                current = temp;
        }
    }
}

void printVector(vector<int> v)
{
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}

void allTraversals(Tnode *node)
{
    // three vectors storing the respective pre post and in order traversals
    vector<int> pre, in, post;

    // base case
    if (node == NULL)
        return;

    // we push to stack node along with a number which signifies which vector to push into
    stack<pair<Tnode *, int>> st;
    st.push({node, 1});

    // while stack is not empty do this
    while (!st.empty())
    {
        auto it = st.top();
        st.pop();
        // case 1 : num == 1 := push to preorder, increment the num and insert left child if exists
        if (it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->left != NULL)
                st.push({it.first->left, 1});
        }
        // case 2: num == 2 := push to inorder, increment the num and insert right child if exists
        else if (it.second == 2)
        {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->right != NULL)
                st.push({it.first->right, 1});
        }
        //  case 3: num == 3 := just push to postorder only
        else
        {
            post.push_back(it.first->data);
        }
    }
    // printing the three vectors
    cout << "Preorder Traversal" << endl;
    printVector(pre);
    cout << "Inorder Traversal" << endl;
    printVector(in);
    cout << "Postorder Traversal" << endl;
    printVector(post);
}

int IterativeCalcHeight(Tnode *node)
{
    if (node == NULL)
        return 0;

    queue<Tnode *> queue;
    int height = 0;
    int nodeCount;
    Tnode *current;

    queue.push(node);
    while (!queue.empty())
    {
        nodeCount = queue.size();
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

int calcHeight(Tnode *node)
{
    if (node == NULL)
        return 0;
    int lh = calcHeight(node->left);
    if (lh == -1)
        return -1;
    int rh = calcHeight(node->right);
    if (rh == -1)
        return -1;

    if (abs(lh - rh) > 1)
        return -1;
    return max(lh, rh) + 1;
}

bool isBalanced(Tnode *node)
{
    return (calcHeight(node) != -1);
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

int maxDiameter(Tnode *node, int &d)
{
    if (node == NULL)
        return 0;
    int lh = maxDiameter(node->left, d);
    int rh = maxDiameter(node->right, d);
    d = max(d, lh + rh);
    return (1 + max(lh, rh));
}

int maxPathSum(Tnode *node, int &maxi)
{
    if (node == NULL)
        return 0;
    int lh = max(0, maxPathSum(node->left, maxi));
    int rh = max(0, maxPathSum(node->right, maxi));
    maxi = max(maxi, lh + rh + node->data);
    return max(lh, rh) + node->data;
}

bool isSameTree(Tnode *node1, Tnode *node2)
{
    if (!node1)
        return !node2;
    if (!node2)
        return !node1;
    return (node1->data == node2->data) && (isSameTree(node1->left, node2->left)) && (isSameTree(node1->right, node2->right));
}

void zigzagTraversal(Tnode *node)
{
    // check base cases
    if (node == NULL)
        return;

    // use a queue for traversing the tree(basically level order)
    deque<Tnode *> queue;
    // push root to queue
    queue.push_back(node);

    // vector to store the traversal
    vector<int> v;

    v.push_back(node->data);

    Tnode *current;
    int l = 1;

    // until queue is not empty do this
    while (!queue.empty())
    {
        // tells how many elements are there in a level
        int size = queue.size();
        // cout << "Size :" << size << endl;

        for (int i = 0; i < size; i++) // runs for all elements in the level
        {
            // logic to reverse the order after every level
            if (l % 2 == 0)
            {
                current = queue.back();
                queue.pop_back();
            }
            else
            {
                current = queue.front();
                queue.pop_front();
            }

            if (l % 2 != 0)
            {
                if (current->right)
                {
                    queue.push_back(current->right);
                    v.push_back(current->right->data);
                }
                if (current->left)
                {
                    queue.push_back(current->left);
                    v.push_back(current->left->data);
                }
            }
            else
            {
                if (current->left)
                {
                    queue.push_front(current->left);
                    v.push_back(current->left->data);
                }
                if (current->right)
                {
                    queue.push_front(current->right);
                    v.push_back(current->right->data);
                }
            }
        }
        l++;
    }

    cout << "Zig Zag Traversal:" << endl;
    printVector(v);
}

int main()
{
    Tnode *root = new Tnode(7);
    root->left = new Tnode(9);
    root->right = new Tnode(10);
    root->left->left = new Tnode(3);
    // root->left->right = new Tnode(6);
    root->left->left->left = new Tnode(4);
    root->right->left = new Tnode(2);
    root->right->right = new Tnode(8);

    //          7
    //        /   \
    //       9     10
    //      / \    / \
    //     3   6  2   8
    //    /
    //   4

    Tnode *root2 = new Tnode(7);
    root2->left = new Tnode(9);
    root2->right = new Tnode(10);
    root2->left->left = new Tnode(3);
    root2->left->right = new Tnode(6);
    // root2->left->left->left = new Tnode(4);
    root2->right->left = new Tnode(2);
    root2->right->right = new Tnode(8);

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

    // cout << "\nIterative Postorder traversal (using 2 stacks) of binary tree is \n";
    // IterativePostorder(root);

    // cout << "\nIterative Postorder traversal (using 1 stack) of binary tree is \n";
    // IterativePostorder2(root);

    // cout << "\nLevel Order traversal of binary tree is \n";
    // printLevelOrderTraversal(root);

    // cout << "\nIterative Level Order traversal of binary tree is \n";
    // printLevelorder(root);

    // Operations

    // cout << "\nIterative Calc Height of the Tree is: ";
    // cout << IterativeCalcHeight(root) << endl;

    // cout << "\nCalc Depth of the Tree is: ";
    // cout << maxDepth(root) << endl;

    // allTraversals(root);

    cout << "Tree is Balanced: " << isBalanced(root) << endl;

    int d = 0;
    maxDiameter(root, d);
    cout << "Tree Diameter: " << d << endl;

    int maxi = 0;
    maxPathSum(root, maxi);
    cout << "Tree Max Path Sum: " << maxi << endl;

    cout << "is Tree same : " << isSameTree(root, root2) << endl;

    zigzagTraversal(root);

    return 0;
}