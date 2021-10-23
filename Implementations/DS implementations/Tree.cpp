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
    Tnode *temp;

    while(queue.empty() == false){
        temp = queue.front();
        cout << temp->data << " ";

        if(temp->left != NULL) 
            queue.push(temp->left);
        if(temp->right != NULL) 
            queue.push(temp->right);
        queue.pop();
    }
}

bool printGivenLevel(Tnode* node, int level)
{
    if (node == NULL) {
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

void printLevelOrderTraversal(Tnode* node)
{
    int level = 1;
    while (printGivenLevel(node, level)) {
        level++;
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

int IterativeCalcHeight(Tnode *node){
    if(node == NULL) return 0;

    queue<Tnode *> queue;
    int height = 0;
    int nodeCount = 0;
    Tnode *current;

    queue.push(node);
    while(!queue.empty()){
        int nodeCount = queue.size();
        height++;
        
        while(nodeCount--){
            current = queue.front();
            
            if(current->left != NULL) queue.push(current->left);
            if(current->right != NULL) queue.push(current->right);

            queue.pop();
        }
    }
    return height;    
}

int maxDepth(Tnode *node){
    if(node == NULL) 
        return 0;
    else {
        int leftDepth = maxDepth(node->left);
        int rightDepth = maxDepth(node->right);

        if(leftDepth < rightDepth)
            return (leftDepth + 1);
        else return (rightDepth + 1);

        // cout << leftDepth << rightDepth << endl;
    }
    // return (max(leftDepth, rightDepth) + 1);
}

int main() {
    Tnode* root = new Tnode(7);
    root->left = new Tnode(9);
    root->right = new Tnode(10);
    root->left->left = new Tnode(3);
    root->left->right = new Tnode(4);
    // root->right->left = new Tnode(2);
    // root->right->right = new Tnode(8);

    // Tnode *root = new Tnode(1);
    // root->left = new Tnode(2);
    // root->right = new Tnode(3);
    // root->left->left = new Tnode(4);
    // root->left->right = new Tnode(5);
    
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

    // cout << "\nLevel Order traversal of binary tree is \n";
    // printLevelOrderTraversal(root);

    // cout << "\nIterative Level Order traversal of binary tree is \n";
    // printLevelorder(root);

    cout << "\nIterative Calc Height of the Tree is: ";
    cout << IterativeCalcHeight(root) << endl;

    cout << "\nCalc Depth of the Tree is: ";
    cout << maxDepth(root) << endl;

    return 0;
}