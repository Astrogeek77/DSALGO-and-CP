#include <iostream>
using namespace std;

int H[100];
int sizeHeap = -1;

void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

int parent(int i) { return (i - 1) / 2; }
int leftChild(int i) { return (2 * i) + 1; }
int rightChild(int i) { return (2 * i) + 2; }
int getMax() { return H[0]; }

void heapifyUp(int i)
{
    while (i > 0 && H[i] > H[parent(i)])
    {
        swap(&H[i], &H[parent(i)]);
        i = parent(i);
    }
}

void heapifyDown(int i)
{
    int largest = i;

    int l = leftChild(i);
    if (l <= sizeHeap && H[l] > H[largest])
        largest = l;

    int r = rightChild(i);
    if (r <= sizeHeap && H[r] > H[largest])
        largest = r;

    if (i != largest)
    {
        swap(&H[i], &H[largest]);
        heapifyDown(largest);
    }
}

void insert(int value)
{
    sizeHeap++;
    H[sizeHeap] = value;

    heapifyUp(sizeHeap);
}

int MaxEl()
{
    int result = H[0];

    H[0] = H[sizeHeap];
    sizeHeap--;

    heapifyDown(0);
    return result;
}

void changePriority(int i, int p)
{
    int oldp = H[i];
    H[i] = p;

    if (p > oldp) heapifyUp(i);
    else heapifyDown(i);

}



void remove(int i)
{
    H[i] = getMax() + 1;

    heapifyUp(i);
    MaxEl();
}

int main()
{
    insert(45);
    insert(20);
    insert(14);
    insert(12);
    insert(31);
    insert(7);
    insert(11);
    insert(13);
    insert(7);
 
    int i = 0;
 
    // Priority queue before extracting max
    cout << "Priority Queue : ";
    while (i <= sizeHeap) {
        cout << H[i] << " ";
        i++;
    }
 
    cout << "\n";
 
    // Node with maximum priority
    cout << "Node with maximum priority : "
         << MaxEl() << "\n";
 
    // Priority queue after extracting max
    cout << "Priority queue after "
         << "extracting maximum : ";
    int j = 0;
    while (j <= sizeHeap) {
        cout << H[j] << " ";
        j++;
    }
 
    cout << "\n";
 
    // Change the priority of element
    // present at index 2 to 49
    changePriority(2, 49);
    cout << "Priority queue after "
         << "priority change : ";
    int k = 0;
    while (k <= sizeHeap) {
        cout << H[k] << " ";
        k++;
    }
 
    cout << "\n";
 
    // Remove element at index 3
    remove(3);
    cout << "Priority queue after "
         << "removing the element : ";
    int l = 0;
    while (l <= sizeHeap) {
        cout << H[l] << " ";
        l++;
    }
    return 0;
}