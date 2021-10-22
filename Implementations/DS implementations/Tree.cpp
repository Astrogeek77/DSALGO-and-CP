#include <iostream>
using namespace std;

class Tnode {
    public:
        int data;
        Tnode *left;
        Tnode *right;
    Tnode(int data){
        this->data = data;
        left = right =  NULL;
    }
};

void printPreorder(Tnode *node){
    // root left right
    if(node == NULL) return;
    
    cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

void printInorder(Tnode *node){
    // left root right
    if(node == NULL) return;
    
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

void printPostorder(Tnode *node){
    // left right root
    if(node == NULL) return;
    
    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << " ";
}






int main() {
    Tnode* root = new Tnode(7);
    root->left = new Tnode(9);
    root->right = new Tnode(10);
    root->left->left = new Tnode(3);
    root->left->right = new Tnode(4);
    root->right->left = new Tnode(2);
    root->right->right = new Tnode(8);
    
    cout << "\nPreorder traversal of binary tree is \n";
    printPreorder(root);
 
    cout << "\nInorder traversal of binary tree is \n";
    printInorder(root);
 
    cout << "\nPostorder traversal of binary tree is \n";
    printPostorder(root);
    
    return 0;
}