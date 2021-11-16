#include <iostream>
#include <vector>
using namespace std;

void swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}

void heapify(vector<int> &ht, int i){
    int largest = i;
    int size = ht.size();
    int l = 2 * i - 1;
    int r = 2 * i + 1;
    
    while(l < size && ht[l] > ht[largest])
        largest = l;
    while(r < size && ht[r] > ht[largest])
        largest = r;
        
    if(largest != i){
        swap(&ht[i], &ht[largest]);
        heapify(ht, largest);
    }
}

void insert(vector<int> &hT, int num)
{
  int size = hT.size();
  if (size == 0)
  {
    hT.push_back(num);
  }
  else
  {
    hT.push_back(num);
    for (int i = size / 2 - 1; i >= 0; i--)
    {
      heapify(hT, i);
    }
  }
}

void printArray(vector<int> &hT)
{
  for (int i = 0; i < hT.size(); ++i)
    cout << hT[i] << " ";
  cout << "\n";
}

int main()
{
  vector<int> heapTree;

  insert(heapTree, 3);
  insert(heapTree, 4);
  insert(heapTree, 9);
  insert(heapTree, 5);
  insert(heapTree, 2);

  cout << "Max-Heap array: ";
  printArray(heapTree);

//   deleteNode(heapTree, 4);

//   cout << "After deleting an element: ";

//   printArray(heapTree);
  system("pause");
  return 0;
}


