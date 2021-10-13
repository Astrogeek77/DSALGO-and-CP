#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *prev;
        Node *next;
    
};

void addNodeAtBegin(int data, Node **Head){
        Node *new_Node = new Node;
        
        new_Node->data = data;
        new_Node->prev = NULL;
        new_Node->next = (*Head);
        
        if((*Head) != NULL) (*Head)->prev = new_Node;
        
        (*Head) = new_Node;
        // Node *prev = NULL;
        // Node *temp = Node *Head->next;
        // node *next = *temp;
    }
    
     void addNodeAtEnd(int data, Node **Head){
        Node *new_Node = new Node;
        
        Node *last = (*Head);
        new_Node->data = data;
         
        new_Node->next = NULL;
        
        if((*Head) == NULL){
            new_Node->prev = NULL;
            (*Head) = new_Node; 
            return;
        }
        
        while(last->next != NULL){
            last = last->next;
        }
        
        last->next = new_Node;
        
        new_Node->prev = last;
    }
    
    void addNodeAfter(int data, Node *prev){
        if (prev == NULL)
        {
            cout<<"the given previous node cannot be NULL";
            return;
        }
        
        Node *new_Node = new Node;
        
        new_Node->data = data;
        
        new_Node->prev = prev;
        
        new_Node->next = (prev)->next;
        (prev)->next = new_Node;
        
        if(new_Node->next != NULL){
            new_Node->next->prev = new_Node;
        }
    }
    
    void printList(Node* node)
    {
        Node* last;
        cout<<"\nTraversal in forward direction \n";
        while (node != NULL)
        {
            cout<<" "<<node->data<<" ";
            last = node;
            node = node->next;
        }
     
        // cout<<"\nTraversal in reverse direction \n";
        // while (last != NULL)
        // {
        //     cout<<" "<<last->data<<" ";
        //     last = last->prev;
        // }
    }
    
    void deleteNode(Node **Head, Node *del){
        
        if(del == NULL || *Head == NULL) return;
        
        if (*Head == del) *Head = del->next;
        
        if(del->next != NULL) del->next->prev = del->prev;
        
        if(del->prev != NULL) del->prev->next = del->next;
        
        free(del);
    }
    
    void ReverseList(Node **Head){
        // while((*Head)->next != NULL){
        //     *Head->next = *Head;
        // }
        
        Node *temp = NULL;
        Node *current = *Head;
        
        while(current != NULL){
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        
        if(temp != NULL) *Head = temp->prev;
        
    }
    
    int findSize(Node *node)
    {
       int count = 0;
       while (node != NULL)
       {
           count++;
           node = node->next;
       }
       return count;
    //   cout << '\n' << "Size of Linked List: " << count << endl;
    }
    
    void swapKthNode(Node **Head, int k){
        int n = findSize(*Head);
         cout << '\n' << "Size of Linked List: " << n << endl;
         
         if(k < 0 || k > n) return;
         
         if(k == (n - k + 1)) {
             printList(*Head);
             return;
         }
         
        //  find kth element from begining
        Node *x1 = *Head;
        Node *x1_prev = NULL;
        
        for(int i = 1; i < k; i++){
            x1_prev = x1;
            x1 = x1->next;
        }
        
        //  find kth element from last
        Node *x2 = *Head;
        Node *x2_prev = NULL;
        
        for(int i = 1; i < n - k + 1; i++){
            x2_prev = x2;
            x2 = x2->next;
        }
        
        if(x1_prev) x1_prev->next = x2;
        
        if(x2_prev) x2_prev->next = x1;
        
        // swap next pointers
        Node *temp = x1->next;
        x1->next = x2->next;
        x2->next = temp;
        
        if(k == 1) *Head = x2;
        
        if(k == n) *Head = x1;
        
        cout << "Linked List after swapping nodes: " << endl;
        printList(*Head);
    }
    
    int count(Node* head, int key)
    {
        Node* current = head;
        int count = 0;
        while (current != NULL) {
            if (current->data == key)
                count++;
            current = current->next;
        }
        return count;
    }

    void push(Node** head, int data)
    {
        Node* new_node = new Node();
        new_node->data = data;
     
        new_node->next = (*head);
        (*head) = new_node;
    }
    
    // One based indexing used
    int getNthNode(Node* head, int index)
    {
        Node* current = head;
     
        int count = 0;
        while (current != NULL) {
            if (count == (index - 1))
                return (current->data);
            count++;
            current = current->next;
        }
        cout << "\nInvalid Index Value Passed" << endl;
    }
    
    void printMiddle(class Node *Head){
        int n = findSize(Head);
        int mid, mid1, mid2;
        
        if (n %2 != 0){
           mid = n/2 + 1; 
           cout << "\nThe middle element is: " << getNthNode(Head, mid) << endl;
        } 
        else {
            mid1 = n/2;
            mid2 = n/2 + 1;
            cout << "\nThe middle elements are: " << getNthNode(Head, mid1) << 
            ", " << getNthNode(Head, mid2) << endl;
        }
    //     Node* slow_ptr = head;
    //     Node* fast_ptr = head;
  
    //     if (head!=NULL)
    //     {
    //         cout << "Naruto" << endl;
    //         while (fast_ptr != NULL && fast_ptr->next != NULL)
    //         {
    //             fast_ptr = fast_ptr->next->next;
    //             slow_ptr = slow_ptr->next;
    //         }
    //         cout << "The middle element is [" << slow_ptr->data << "]" << endl;
    //     }
    }
    
    void pairWiseSwap(Node* head)
    {
        Node* temp = head;
    
        while (temp != NULL && temp->next != NULL) {
            Node* temp2;
            temp2 = temp;
            temp = temp->next;
            temp->next = temp2;
            // swap(temp->data,
            //      temp->next->data);
            temp = temp->next->next;
        }
    }
    
    void moveToFront(Node **head) 
    { 
        if (*head == NULL || (*head)->next == NULL) 
            exit(-1);
      
        Node *secLast = NULL; 
        Node *last = *head; 
      
        while (last->next != NULL) 
        { 
            secLast = last; 
            last = last->next; 
        } 
      
        secLast->next = NULL; 
        last->next = *head; 
        *head = last; 
    } 
    


int main() {
    
    Node *head = NULL;
    
    // addNodeAtEnd(9, &head);
    addNodeAtBegin(3, &head);
    
    
    // addNodeAtBegin(5, &head);
    // addNodeAtEnd(2, &head);
    // addNodeAtEnd(9, &head);
    // addNodeAtEnd(4, &head);
    push(&head, 5);
    push(&head, 3);
    push(&head, 6);
    push(&head, 8);
    push(&head, 9);
    push(&head, 7);
    // addNodeAtEnd(1, &head);
    // addNodeAtEnd(10, &head);
    
    
    // addNodeAfter(8, head->next);
    printList(head);
    
    // deleteNode(&head, head);
    // deleteNode(&head, head->next);
    // deleteNode(&head, head->next);
    // printList(head);
    
    ReverseList(&head);
    // pairWiseSwap(head);
    printList(head);
    moveToFront(&head);
    printList(head);
    // pairWiseSwap(head);
    printList(head);
    
    cout << '\n' << "Size of Linked List: " << findSize(head) << endl;
    printMiddle(head);
    cout << "\nElement at Given index is " << getNthNode(head, 3);
    // swapKthNode(&head, 3);
    
    cout << "\nThe Number of occurances: " << count(head, 2) << endl;
    
    return 0;
}

