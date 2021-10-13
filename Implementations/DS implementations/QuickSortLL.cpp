#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node *prev;
        Node *next;
};

void swap(int* a, int* b){ 
    int t = *a; 
    *a = *b; 
    *b = t; 
}

Node *lastNode(Node *temp){
    while(temp && temp->next)
        temp = temp->next;
    return temp;
}

Node* partiton(Node *low, Node *high){
    int pivot = high->data;
    Node *i = low->prev;
    
    for(Node *j = low; j != high; j = j->next){
        if(j->data <= pivot){
            i = (i == NULL)? low : i->next;
            swap(&(i->data), &(j->data));
        }
    }
    i = (i == NULL)? low : i->next;
    swap(&(i->data), &(high->data));
    
    return i;
}

void quicksort(Node *low, Node *high){
    if(high != NULL && low != high && low != high->next){
        Node *pi = partiton(low, high);
        // cout << "PI: " <<  pi << endl;
        
        quicksort(low, pi->prev);
        quicksort(pi->next, high);
    }
}

void quickSort(Node *head)
{
    Node *high = lastNode(head);
    quicksort(head, high);
}
 
// A utility function to print contents of arr
void printList(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
 
void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node; 
    new_node->data = new_data;

    new_node->prev = NULL;
    new_node->next = (*head_ref);
 
    if ((*head_ref) != NULL) (*head_ref)->prev = new_node ;
    (*head_ref) = new_node;
}
 
int main()
{
    Node *a = NULL;
    push(&a, 10);
    push(&a, 23);
    push(&a, 45);
    push(&a, 3);
    push(&a, 90);
 
    cout << "Linked List before sorting \n";
    printList(a);
 
    quickSort(a);
 
    cout << "Linked List after sorting \n";
    printList(a);
 
    return 0;
}