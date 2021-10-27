#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

void showpq(priority_queue<int> pq){
    priority_queue<int> g = pq;
    while(!g.empty()){
         cout << '\t' << g.top();
         g.pop();
    }
    cout << endl;
}

int main() {
    priority_queue<int> priority_queue;
    priority_queue.push(1);
    priority_queue.push(2);
    priority_queue.push(3);
    priority_queue.push(4);
    priority_queue.push(5);

    cout << "\npriority_queue :";
    showpq(priority_queue);

    cout << "\npriority_queue.size() : " << priority_queue.size();
    cout << "\npriority_queue.top()  : " << priority_queue.top();
    cout << "\npriority_queue.pop()  :";
    priority_queue.pop();

    showpq(priority_queue);
    return 0;
}
