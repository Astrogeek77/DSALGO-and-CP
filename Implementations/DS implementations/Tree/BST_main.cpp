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
    // BST *root2 = NULL;
    // root2 = insert(root2, 50);
    // insert(root2, 30);
    // insert(root2, 20);
    // insert(root2, 40);
    // insert(root2, 70);
    // insert(root2, 60);
    // insert(root2, 80);
    // insert(root2, 10);
    // insert(root2, 5);

    BST *root = new BST(1);
    insert(root, 2);
    insert(root, 4);
    insert(root, 3);
    insert(root, 10);
    insert(root, 5);
    insert(root, 7);
    insert(root, 6);
    insert(root, 9);
    insert(root, 8);

    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;
    cout << "Preorder Traversal: ";
    preorderTraversal(root);
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
    // inorderTraversal(root);
    // cout << endl;

    // int key3 = 5;
    // cout << "delete " << key3 << endl;
    // root = deleteNodeIterative(root, key3);
    // cout << "Inorder Traversal: ";
    // inorderTraversal(root);
    // cout << endl;

    // BST from Preorder

    // vector<int> preorder{10, 5, 1, 7, 40, 50 };

    // BST* root2 = BSTfromPreorder(preorder);

    // inorder(root2);

    // bool isBST = checkBST(root, INT_MIN, INT_MAX);
    // cout << ((isBST == true) ? "YES" : "NO") << endl;

    // int key = 8;
    // cout << "Ceil of " << key << " is: " << getCeil(root, key) << endl;
    // cout << "Floor of " << key << " is: " << getFloor(root, key) << endl;

    cout << "Total Nodes: " << countNodes(root) << endl;

    // int k = 5;
    // printf("%dth smallest element in BST: %d\n", k, KthSmallest(root, k));
    // printf("%dth largest element in BST: %d\n", k, KthLargest(root, k));

    vector<int> preorder = {1, 2, 4, 5, 3};
    // BST *root3 = constructTree1(preorder);
    // inorderTraversal(root3);
    // int i = 0;
    // BST *root4 = constructTree2(preorder, i, INT_MAX);
    // inorderTraversal(root4);
    // preorderTraversal(root4);

    int val = 8;
    // cout << "Inorder successor of " << val << " is: " << inorderSuccessor1(root, val)->data << endl;
    cout << "Inorder successor of " << val << " is: " << inorderSuccessor2(root, val)->data << endl;
    cout << "Inorder predecessor of " << val << " is: " << inorderPredecessor(root, val)->data << endl;

    // BSTiterator it = BSTiterator(root);
    // while (it.hasNext())
    // {
    //     cout << it.next() << " ";
    // }
    // cout << endl;
    // while (it.hasBack())
    // {
    //     cout << it.back() << " ";
    // }
    // cout << endl;

    // auto itExists = twoSumBST(root, 25);
    // // cout << twoSumBST(root, 3).first << endl;

    // if (itExists.first)
    //     cout << "Pair: " << itExists.second.first << ", " << itExists.second.second << endl;
    // else
    //     cout << "No such pair exists.";
    // return 0;

    cout << isBalanced(root) << endl;
}
