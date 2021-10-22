#include <bits/stdc++.h>
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

void printLevelorder(Tnode *node){
    // level by level
    if(node == NULL) return;

    queue<Tnode *> queue;
    queue.push(node);

    while(queue.empty() == false){
        Tnode *temp = queue.front();
        cout << temp->data << " ";
        queue.pop();

        if(node->left != NULL) 
            queue.push(node->left);
        if(node->right != NULL) 
            queue.push(node->right);
    }
}

void iterativePreorder(Tnode *node){
    // root left right
    if(node == NULL) return;

    stack<Tnode*> stack;
    stack.push(node);

    while(stack.empty() == false){
        Tnode* temp = stack.top();
        cout << temp->data << " ";
        stack.pop();
        
        // right is pushed first so that left is processed first
        if(temp->right) stack.push(temp->right);
        if(temp->left) stack.push(temp->left);
        
    } 
}

void iterativeInorder(Tnode *node){
    // left root right
    if(node == NULL) return;

    stack<Tnode *> stack;
    Tnode *current = node;

    while(current != NULL || stack.empty() == false) 
    {
        while(current != NULL){
            stack.push(current);
            current = current->left;
        }

        current = stack.top();
        cout << current->data << " ";
        stack.pop();

        current = current->right;
    }
}





int main() {
    Tnode* root = new Tnode(7);
    root->left = new Tnode(9);
    root->right = new Tnode(10);
    root->left->left = new Tnode(3);
    root->left->right = new Tnode(4);
    root->right->left = new Tnode(2);
    root->right->right = new Tnode(8);
    
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

    // cout << "\nIterative Postorder traversal of binary tree is \n";
    // printPostorder(root);

    cout << "\nLevel Order traversal of binary tree is \n";
    printLevelorder(root);

    return 0;
}