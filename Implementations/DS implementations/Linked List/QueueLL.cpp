#include <iostream>

using namespace std;

class QNode {
    public:
        int data;
        QNode *next;
        
        QNode(int d){
            data = d;
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
        //   cout << "Empty Queue" << endl;
           return;
        }
        
        rear->next = temp;
        rear = temp;
    }
    
    void dequeue(){
        if (front == NULL) return;
        
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
    q.dequeue();
    q.enqueue(20);
    q.dequeue();
    q.dequeue();
    q.enqueue(30);
    q.dequeue();
    q.enqueue(40);
    q.dequeue();
    q.enqueue(50);
    q.enqueue(100);
    q.dequeue();
    q.enqueue(101);
    
    cout << "Queue Front : " << (q.front)->data << endl;
    cout << "Queue Rear : " << (q.rear)->data << endl;
    return 0;
}