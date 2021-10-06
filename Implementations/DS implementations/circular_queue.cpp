#include <iostream>
#include <string>
#include <bits/stdc++.h>
#define MAX 5
using namespace std;

int cqueue_arr[MAX];
int front = -1;
int rear = -1;

// Function to insert value to the cirqu
void insertEl(int item)
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        cout << "Queue Overflow" << endl;
        return;
    }

    if (front == -1) /*If queue is empty */
    {
        front = 0;
        rear = 0;
    }
    else
    {
        if (rear == MAX - 1) /*rear is at last position of queue */
            rear = 0;
        else
            rear = rear + 1;
    }

    cqueue_arr[rear] = item;
}

void delEl()
{
    if (front == -1)
    {
        cout << "Queue Underflow" << endl;
        return;
    }

    cout << "Element deleted from queue is : " + cqueue_arr[front] << endl;

    if (front == rear) /* queue has only one element */
    {
        front = -1;
        rear = -1;
    }
    else
    {
        if (front == MAX - 1)
            front = 0;
        else
            front = front + 1;
    }
}

void display()
{
    int front_pos = front, rear_pos = rear;

    if (front == -1)
        cout << "Queue is empty!" << endl;
    else
    {
        cout << "Queue elements :" << endl;

        if (front_pos <= rear_pos)
            while (front_pos <= rear_pos)
            {
                cout << cqueue_arr[front_pos] << " ";
                front_pos++;
            }
        else
        {
            while (front_pos <= MAX - 1)
            {
                cout << cqueue_arr[front_pos] << " ";
                front_pos++;
            }
            front_pos = 0;

            while (front_pos <= rear_pos)
            {
                cout << cqueue_arr[front_pos] << " ";
                front_pos++;
            }
        }
    }
    cout << endl;
}

int main()
{
    int choice, item;
    while(1)
    {

        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter your choice"
             << " ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {

        case 1:

            cout << "Input the element for insertion in queue: ";
            cin >> item;
            insertEl(item);

            break;

        case 2:
            delEl();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);
            break;

        default:
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}