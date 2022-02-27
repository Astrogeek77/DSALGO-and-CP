#include "Tnode.h"
#include "Tree_Traversals.h"
#include "Tree_Utils.h"

int main()
{
  // ++++++++++++++++++++++++++++++++++++++++++
  // Tree - 1
  // ++++++++++++++++++++++++++++++++++++++++++

  Tnode *root3 = new Tnode(1); // root
  root3->left = new Tnode(2);
  root3->right = new Tnode(3);
  root3->left->left = new Tnode(4);
  root3->left->right = new Tnode(5);
  root3->right->left = new Tnode(6);
  root3->right->right = new Tnode(7);
  /*
       1
      / \
     2   3
    / \ / \
   4  5 6  7
  */

  // ++++++++++++++++++++++++++++++++++++++++++
  // Tree - 2
  // ++++++++++++++++++++++++++++++++++++++++++

  /* Construct the following tree
             1
           /   \
          /     \
         2       3
        / \     / \
       /   \   /   \
     4    5     6     7
     /\   /\    /\    /\
    /  \ /  \  /  \  /  \
    8  9 10 11 12 13 14 15
   */

  Tnode *root = new Tnode(1);  
  root->left = new Tnode(2); 
  root->right = new Tnode(3);
  root->left->left = new Tnode(4);
  root->left->right = new Tnode(5);
  root->right->left = new Tnode(6);
  root->right->right = new Tnode(7);
  root->left->left->left = new Tnode(8);
  root->left->left->right = new Tnode(9);
  root->left->right->left = new Tnode(10);
  root->left->right->right = new Tnode(11);
  root->right->left->left = new Tnode(12);
  root->right->left->right = new Tnode(13);
  root->right->right->left = new Tnode(14);
  root->right->right->right = new Tnode(15);

  // ++++++++++++++++++++++++++++++++++++++++++
  // Tree - 3
  // ++++++++++++++++++++++++++++++++++++++++++

  // Tnode *root = new Tnode(7);
  // root->left = new Tnode(9);
  // root->right = new Tnode(10);
  // root->left->left = new Tnode(3);
  // // root->left->right = new Tnode(6);
  // root->left->left->left = new Tnode(4);
  // root->right->left = new Tnode(2);
  // root->right->right = new Tnode(8);

  // ++++++++++++++++++++++++++++++++++++++++++
  // Tree - 4
  // ++++++++++++++++++++++++++++++++++++++++++

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
  root2->left->left->left = new Tnode(4);
  root2->right->left = new Tnode(2);
  root2->right->right = new Tnode(8);

  // ++++++++++++++++++++++++++++++++++++++++++
  // Traversals
  // ++++++++++++++++++++++++++++++++++++++++++

  // cout << "\nDepth First traversal of binary tree is \n";
  // DFT(root);

  // cout << "\nDepth First traversal (Recursive) of binary tree is \n";
  // DFTRecursive(root);

  // cout << "\nBreadth First traversal of binary tree is \n";
  // BFT(root);

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
  // cout << endl;

  // cout << "\nIterative Level Order traversal of binary tree is \n";
  // printLevelorder(root);
  // cout << endl;

  // allTraversals(root);

  // zigzagTraversal(root);

  // cout << "Boundary Traversal" << endl;
  // boundaryTraversal(root);

  // cout << "Vertical Traversal" << endl;
  // verticalTraversal(root3);

  // ++++++++++++++++++++++++++++++++++++++++++
  // Operations
  // ++++++++++++++++++++++++++++++++++++++++++

  // int key = 5;
  // cout << "\nEnter Element to Search: " << endl;
  // cin >> key;
  // cout << endl;
  // treeIncludes(root, key) == true ? printf("Tree Contains %d", key) : printf("Tree Does not contain %d", key);
  // cout << endl;
  // treeIncludesRecursive(root, key) == true ? printf("Tree Contains %d", key) : printf("Tree Does not contain %d", key);
  // cout << endl;

  // int sum = 0;
  // sum = treeSumRecursive(root, sum);
  // sum = treeSum(root, sum);
  // cout << "The Tree Sum is: " << sum << endl;

  // cout << "The Smallest value in the tree is: " << findMin(root) << endl;
  // cout << "The Smallest value in the tree is: " << findMinRecursive(root) << endl;
  // cout << "The Largest value in the tree is: " << findMaxRecursive(root) << endl;

  // cout << "The Max Root to Leaf Sum is: " << maxRoottoLeafSum(root) << endl;
  // cout << "The Min Root to Leaf Sum is: " << minRoottoLeafSum(root) << endl;

  // cout << "\nIterative Calc Height of the Tree is: ";
  // cout << IterativeCalcHeight(root) << endl;

  // cout << "\nCalc Depth of the Tree is: ";
  // cout << maxDepth(root) << endl;

  // cout << "Tree is Balanced: " << isBalanced(root) << endl;

  // int d = 0;
  // maxDiameter(root, d);
  // cout << "Tree Diameter: " << d << endl;

  // int maxi = 0;
  // maxPathSum(root, maxi);
  // cout << "Tree Max Path Sum: " << maxi << endl;

  // cout << "is Tree same : " << isSameTree(root, root2) << endl;

  // topView(root);
  // bottomView(root);
  // leftView(root);
  // rightView(root);

  printPath(root, 12);
}