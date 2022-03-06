#include "BST_utils.h"

// The properties that separate a binary search tree from a regular binary tree is

// All nodes of left subtree are less than the root node
// All nodes of right subtree are more than the root node
// Both subtrees of each node are also BSTs i.e. they have the above two properties

// Binary Search Tree Complexities
// Time Complexity
// Operation	Best Case Complexity	Average Case Complexity	  Worst Case Complexity
// Search	            O(log n)	            O(log n)	            O(n)
// Insertion	        O(log n)	            O(log n)	            O(n)
// Deletion	            O(log n)	            O(log n)	            O(n)
// Here, n is the number of nodes in the tree.

// Space Complexity
// The space complexity for all the operations is O(n).

// AVL Tree ⊆ BST ⊆ Binary Tree but not vice-versa

int main()
{
    BST *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    insert(root, 10);
    insert(root, 5);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    // int key = 40;
    // if (b.search(root, key) == -1)
    //     cout << "Element Not Found." << endl;
    // else
    //     cout << "Element " << key << " Found at Depth: " << b.search(root, key) << endl;

    // cout << "minValueNode: " << (b.minValueNode(root))->data << endl;

    // int key2 = 30;
    // cout << "delete " << key2 << endl;
    // root = deleteNode(root, key2);
    // cout << "Inorder Traversal: ";
    // inorder(root);
    // cout << endl;

    // int key3 = 5;
    // cout << "delete " << key3 << endl;
    // root = deleteNodeIterative(root, key3);
    // cout << "Inorder Traversal: ";
    // inorder(root);
    // cout << endl;

    // BST from Preorder

    // vector<int> preorder{10, 5, 1, 7, 40, 50 };

    // BST* root2 = BSTfromPreorder(preorder);

    // inorder(root2);

    bool isBST = checkBST(root, INT_MIN, INT_MAX);
    cout << ((isBST == true) ? "YES" : "NO") << endl;

    int key = 8;
    cout << "Ceil of " << key << " is: " << getCeil(root, key) << endl;
    cout << "Floor of " << key << " is: " << getFloor(root, key) << endl;

    return 0;
}
