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

    BST *insert(BST *root, int data)
    {
        if (!root)
            return new BST(data);
        else if (root->data < data)
            root->right =  insert(root->right, data);
        else
            root->left = insert(root->left, data);
        return root;
    }

    BST *search(BST *root, int key)
    {
        if (root == NULL || root->data == key)
            return root;
        else if (root->data < key)
            return search(root->right, key);
        else
            return search(root->left, key);
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

    BST* minValueNode(BST *node){
        BST *curr = node;

        while(curr->left != NULL)
            curr = curr->left;
        
        return curr;
    }
};

int main(){
    BST b, *root = NULL;
    root = b.insert(root, 50);
    b.insert(root, 30);
    b.insert(root, 20);
    b.insert(root, 40);
    b.insert(root, 70);
    b.insert(root, 60);
    b.insert(root, 80);
    b.insert(root, 10);

    b.inorder(root);

    b.search(root, 60);

    cout << "\nminValueNode: " << (b.minValueNode(root))->data << endl;

    return 0;
}
