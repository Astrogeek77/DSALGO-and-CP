#include <iostream>

using namespace std;

class QNode {
    public:
        int data;
        QNode *next;
        
        QNode(int data){
            data = data;
            next = NULL;
        }
};

class Queue {
    public:
        QNode *front, *rear;
        Queue(){
            front = rear = NULL;
        }

    void enqueue(int data){
        QNode *temp = new QNode(data);
        
        if(rear == NULL){
           front = rear = temp;
           cout << "Empty Queue" << endl;
           exit(0);
        }
        
        rear->next = temp;
        rear = temp;
    }
    
    void dequeue(){
        if (front == NULL) exit(-1);
        
        QNode* temp = front;
        front = front->next;
 
        if (front == NULL)
            rear = NULL;
 
        delete (temp);
    }
};


int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.dequeue();
    q.dequeue();
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.dequeue();
    
    cout << "Queue Front : " << (q.front)->data << endl;
    cout << "Queue Rear : " << (q.rear)->data << endl;
    return 0;
}