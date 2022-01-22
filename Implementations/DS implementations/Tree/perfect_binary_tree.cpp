// Perfect Binary Tree Theorems
// A perfect binary tree of height h has 2h + 1 – 1 node.
// A perfect binary tree with n nodes has height log(n + 1) – 1 = Θ(ln(n)).
// A perfect binary tree of height h has 2h leaf nodes.
// The average depth of a node in a perfect binary tree is Θ(ln(n)).

#include <iostream>
using namespace std;

// Node structure to define each node of the tree and its children.
struct Node
{
    int key;
    struct Node *left, *right;
};

// Function to extract depth of the tree and use later.
int depth(Node *node)
{
    int d = 0;
    while (node != NULL)
    {
        d++;
        node = node->left;
    }
    return d;
}

// Check Whether the given tree is a Perfect Binary Tree.
bool isPerfectR(struct Node *root, int d, int level = 0)
{
    if (root == NULL) // a single nope is also a perfect binary tree of height 0;
        return true;

    if (root->left == NULL && root->right == NULL)
        return (d == level + 1); 

    if (root->left == NULL || root->right == NULL)
        return false; // one of left or right node means not a perfect binary tree.

    return isPerfectR(root->left, d, level + 1) &&
           isPerfectR(root->right, d, level + 1);
}

bool isPerfect(Node *root)
{
    int d = depth(root);
    return isPerfectR(root, d);
}

struct Node *newNode(int k)
{
    struct Node *node = new Node;
    node->key = k;
    node->right = node->left = NULL;
    return node;
}

int main()
{
    struct Node *root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    if (isPerfect(root))
        cout << "The tree is a perfect binary tree\n";
    else
        cout << "The tree is not a perfect binary tree\n";
}