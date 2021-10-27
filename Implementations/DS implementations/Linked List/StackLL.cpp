#include <iostream>

using namespace std;

class Node {
    public:
        Node *link;
        int data;
};

Node *Top = NULL;

void push(int data){
    
    Node *temp = new Node;
    
    if(!temp){
        cout << "Stack Overflow" << endl;
        exit(-1);
    }
    
    temp->data = data;
    temp->link = Top;
    
    Top = temp;
}

void display(){
    Node *temp = new Node;
    
    if(Top == NULL){
        cout << "Stack Underflow" << endl;
        exit(0);
    }
    
    temp = Top;
    
    while(temp != NULL){
        cout << temp->data << " -> ";
        temp = temp->link;
    }
}

int peek(){
    if(Top == NULL){
        cout << "Stack Underflow" << endl;
        exit(0);
    }
    
    // cout << Top->data << endl;
    return Top->data;
}

int isEmpty()
{
    return Top == NULL;
}

void pop(){
    Node *temp;
    
    if(Top == NULL){
        cout << "Stack Underflow" << endl;
        exit(0);
    }
    
    temp = Top;
    
    Top = Top->link;
    temp->link = NULL;
    
    free(temp);
}

int main(){
    cout << "isEmpty: " << isEmpty() << endl;
    
    push(-1);
    push(2);
    push(5);
    push(10);
    
    cout << "\nFirst Element is: " << peek() << endl;
    
    cout << "\nStack: ";
    display();
    
    cout << "\nisEmpty: " << isEmpty() << endl;
    
    pop();
    
    cout << "\nFirst Element is: " << peek() << endl;
    
    cout << "\nStack: ";
    display();

    return 0;
}