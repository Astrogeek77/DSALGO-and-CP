// #include<bit/stdc++.h>
#include<iostream>
#include<math.h>
#include<time.h>
using namespace std;

// Treap Node
class node 
{
    public:
    int key, priority;
    node *left, *right;
};

/* 
T1, T2 and T3 are subtrees of the tree rooted with y
  (on left side) or x (on right side)
                y                               x
               / \     Right Rotation          /  \
              x   T3   – – – – – – – >        T1   y
             / \       < - - - - - - -            / \
            T1  T2     Left Rotation            T2  T3 
*/


// utility function to left rotate or right rotate the tree
node *rightRotate(node *y)
{
    node *x = y->left;
    node *T2 = x->right;

    y->left = T2;
    x->right = y;

    return x;
}

node *leftRotate(node *x)
{
    node *y = x->right;
    node *T2 = y->left;

    y->left = x;
    x->right = T2;

    return y;
}

// utility function to create a new treap node

node *newnode(int key)
{
    node *curr = new node;
    curr->key = key;
    curr->priority = rand() % 100;
    curr->left = nullptr;
    curr->right = nullptr;
    return curr;
}

// Utility function to search a given key.
node *search(node *root, int key)
{
    // simple BST Implementation, priority has no role in search.

    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
        return root;

    // Key is greater than root's key
    if (root->key < key)
        return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}

/*
    Insert
    1) Create new node with key equals to x and value equals to a random value.
    2) Perform standard BST insert.
    3) A newly inserted node gets a random priority, so Max-Heap property may be violated.. 
       Use rotations to make sure that inserted node’s priority follows max heap property.
       During insertion, we recursively traverse all ancestors of the inserted node.

    a) If new node is inserted in left subtree and root of left subtree has higher priority, perform right rotation.
    b) If new node is inserted in right subtree and root of right subtree has higher priority, perform left rotation.
*/

/* Recursive implementation of insertion in Treap */
node *insert(node *root, int key)
{
    if (!root) return newnode(key);

    if (key <= root->key)
    {
        root->left = insert(root->left, key);

        // Fix Heap property if it is violated
        if (root->left->priority > root->priority)
            root = rightRotate(root);
    }
    else
    {
        root->right = insert(root->right, key);

        // Fix Heap property if it is violated
        if (root->right->priority > root->priority)
            root = leftRotate(root);
    }
    return root;
}

/*
    Delete:
    1) If node is a leaf, delete it.
    2) If node has one child NULL and other as non-NULL, replace node with the non-empty child.
    3) If node has both children as non-NULL, find max of left and right children.
       a) If priority of right child is greater, perform left rotation at node
       b) If priority of left child is greater, perform right rotation at node.
    The idea of step 3 is to move the node to down so that we end up with either case 1 or case 2.
*/

/* Recursive implementation of Delete() */
node *deleteNode(node *root, int key)
{
    if (root == NULL) return root;

    if (key < root->key) root->left = deleteNode(root->left, key);
    else if (key > root->key) root->right = deleteNode(root->right, key);


    else if (root->left == NULL)
    {
        node *temp = root->right;
        delete (root);
        root = temp; // Make right child as root
    }

    else if (root->right == NULL)
    {
        node *temp = root->left;
        delete (root);
        root = temp; // Make left child as root
    }

    else if (root->left->priority < root->right->priority)
    {
        root = leftRotate(root);
        root->left = deleteNode(root->left, key);
    }
    else
    {
        root = rightRotate(root);
        root->right = deleteNode(root->right, key);
    }
    return root;
}

// A utility function to print tree inorder
void inorder(node *root)
{
    if (root)
    {
        inorder(root->left);
        cout << "key: " << root->key << " | priority: "
             << root->priority;
        if (root->left)
            cout << " | left child: " << root->left->key;
        if (root->right)
            cout << " | right child: " << root->right->key;
        cout << endl;
        inorder(root->right);
    }
}

// A utility function to print tree preorder
void preorder(node *root)
{
    if (root)
    {
        cout << "key: " << root->key << " | priority: "
             << root->priority;
        if (root->left)
            cout << " | left child: " << root->left->key;
        if (root->right)
            cout << " | right child: " << root->right->key;
        cout << endl;
        preorder(root->left);
        preorder(root->right);
    }
}

// A utility function to print tree postorder
void postorder(node *root)
{
    if (root)
    {
        postorder(root->left);
        postorder(root->right);
        cout << "key: " << root->key << " | priority: "
             << root->priority;
        if (root->left)
            cout << " | left child: " << root->left->key;
        if (root->right)
            cout << " | right child: " << root->right->key;
        cout << endl;
    }
}