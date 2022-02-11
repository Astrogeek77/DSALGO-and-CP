#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void display(Node *node)
{
    if (node == NULL)
        return;
    Node *curr = node;
    while (curr != NULL)
    {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout << endl;
}

void displayRecursive(Node *node)
{
    if (node == NULL)
    {
        cout << endl;
        return;
    }
    cout << node->data << " -> ";
    displayRecursive(node->next);
}

void fillvalues(Node *head, vector<int> &values)
{
    if (head == NULL)
        return;
    values.push_back(head->data);
    fillvalues(head->next, values);
}

vector<int> values(Node *head)
{
    vector<int> llvalues;
    fillvalues(head, llvalues);
    return llvalues;
}

vector<int> fillValuesIterative(Node *head)
{
    vector<int> llvalues = {};
    if (head == NULL)
        return llvalues;
    Node *curr = head;
    while (curr != NULL)
    {
        llvalues.push_back(curr->data);
        curr = curr->next;
    }
    return llvalues;
}

int sumList(Node *head)
{
    int sum = 0;
    if (head == NULL)
        return 0;
    Node *curr = head;
    while (curr != NULL)
    {
        sum += curr->data;
        curr = curr->next;
    }
    return sum;
}

void calcSum(Node *head, int &sum)
{
    if (head == NULL)
        return;
    sum += head->data;
    calcSum(head->next, sum);
}

int sumRecursive(Node *head)
{
    int sum = 0;
    calcSum(head, sum);
    return sum;
}

bool listIncludes(Node *head, int key)
{
    if (head == NULL)
        return false;
    if (head->data == key)
        return true;
    return listIncludes(head->next, key);
}

bool listIncludesIterative(Node *head, int key)
{
    if (head == NULL)
        return false;
    auto curr = head;
    while (curr != NULL)
    {
        if (curr->data == key)
            return true;
        curr = curr->next;
    }
    return false;
}

auto getListNode(Node *head, int index)
{
    if (head == NULL)
        return NULL;
    if (index == 0)
        return head->data;
    return getListNode(head->next, index - 1);
}

int getCount(Node *head)
{
    if (head == NULL)
        return 0;
    int count = 0;
    auto curr = head;
    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    return count;
}

int getListNodeIterative(Node *head, int index)
{
    int count = 0;
    auto curr = head;
    while (curr != NULL)
    {
        if (count == index)
            return curr->data;
        count++;
        curr = curr->next;
    }
    return -1;
}

Node *reverseList(Node *head)
{
    if (head == NULL)
        return NULL;
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    display(prev);
    return prev;
}

Node *reverseRecursive(Node *head, Node *prev = NULL)
{
    if (head == NULL)
        return prev;
    Node *next = head->next;
    head->next = prev;
    return reverseRecursive(next, head);
}

Node *zipLists(Node *head, Node *head2)
{
    // if (head == NULL)
    //     return head2;
    // if (head2 == NULL)
    //     return head;

    Node *tail = head;
    Node *curr = head->next;
    Node *curr2 = head2;
    int count = 0;

    while (curr != NULL && curr2 != NULL)
    {
        if (count % 2 == 0)
        {
            tail->next = curr2;
            curr2 = curr2->next;
        }
        else
        {
            tail->next = curr;
            curr = curr->next;
        }
        tail = tail->next;
        count++;
    }
    if (curr != NULL)
        tail->next = curr;
    if (curr2 != NULL)
        tail->next = curr2;
    return head;
}

Node* zipListsRecursive(Node *head, Node *head2){
    if(head == NULL && head2 == NULL) return NULL;
    if (head == NULL)
        return head2;
    if (head2 == NULL)
        return head;
    
    Node *next1 = head->next;
    Node *next2 = head2->next;

    head->next = head2;

    head2->next = zipListsRecursive(next1, next2);

    return head;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);

    // 1->2->3->4->5->6->7

    Node *head2 = new Node(8);
    head2->next = new Node(9);
    head2->next->next = new Node(10);

    // 8->9->10

    display(head);
    displayRecursive(head);

    // vector<int> llvalues = values(head);
    // for(auto x: llvalues)
    //     cout << x << " ";
    // cout << endl;
    // vector<int> llvalues1 = fillValuesIterative(head);
    // for(auto x: llvalues1)
    //     cout << x << " ";
    // cout << endl;

    cout << "The Sum of the List is: " << sumList(head) << endl;
    cout << "The Sum (Recursive) of the List is: " << sumRecursive(head) << endl;

    int key = 5;
    // cout << "Enter the key to search: " << endl;
    // cin >> key;
    // listIncludes(head, key) == true ? printf("The List contains %d\n", key) : printf("The List does not contains %d\n", key);
    listIncludesIterative(head, key) == true ? printf("The List contains %d\n", key) : printf("The List does not contains %d\n", key);

    int index = 6;
    // cout << "Enter a Index: " << endl;
    // cin >> index;
    // auto result = getListNode(head, index);
    // printf("Value at index %d is %d ", index, result);
    // cout << endl;
    auto result2 = getListNodeIterative(head, index);
    printf("Value (Iterative) at index %d is %d ", index, result2);
    cout << endl;

    cout << "The Count of Nodes in List is: " << getCount(head) << endl;

    // cout << "Reversed Linked List: " << endl;
    // reverseList(head);
    // display(reverseRecursive(head));

    display(zipListsRecursive(head, head2));
}