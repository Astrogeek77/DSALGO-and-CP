#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

// Priority Queue by default gives max heap in cpp

void showpq(priority_queue<int> pq)
{
    priority_queue<int> g = pq;
    while (!g.empty())
    {
        cout << '\t' << g.top();
        g.pop();
    }
    cout << " ";
}

void showMinHeap(
    priority_queue<int, vector<int>, greater<int> > gq)
{
    priority_queue<int, vector<int>, greater<int> > g = gq;
    while (!g.empty()) {
        cout << '\t' << g.top();
        g.pop();
    }
    cout << ' ';
}

void MinfromMax(){
    // negating the values twice helps us get a min heap from the default max heap of PQ.
    int arr[] = { 25, 7, 9, 15, 20, 36, 50 };
   
    priority_queue<int> pq;
    int n = sizeof(arr) / sizeof(arr[0]);
 
    for (int i = 0; i < n; i++) {
        pq.push((-1) * arr[i]);
    }
    while (!pq.empty()) {
        cout << "\t" <<  (pq.top()) * (-1) << " ";
        pq.pop();
    }
    cout << " ";
}

int main()
{
    // Max Heap
    priority_queue<int> my_priority_queue;
    my_priority_queue.push(1);
    my_priority_queue.push(2);
    my_priority_queue.push(3);
    my_priority_queue.push(5);
    my_priority_queue.push(4);


    // Min Heap
    priority_queue<int, vector<int>, greater<int> > priority_queue2;
    priority_queue2.push(10);
    priority_queue2.push(30);
    priority_queue2.push(20);
    priority_queue2.push(5);
    priority_queue2.push(1); 

    cout << "\nMax-Heap priority_queue  :";
    showpq(my_priority_queue);

    cout << "\nMin-Heap priority_queue2 :";
    showMinHeap(priority_queue2);

    cout << "\nMin-Heap from Max-Heap   :";
    MinfromMax();

    cout << "\nmy_priority_queue.size() :\t" << my_priority_queue.size();
    cout << "\nmy_priority_queue.top()  :\t" << my_priority_queue.top();
    cout << "\nmy_priority_queue.pop()  :";
    my_priority_queue.pop();
    showpq(my_priority_queue);

    my_priority_queue.push(6);
    cout << "\nmy_priority_queue.push(6) :";
    showpq(my_priority_queue);

    return 0;
}
