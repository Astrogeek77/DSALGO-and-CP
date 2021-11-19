#include <iostream>
#include <vector>
// #include <algorithm>
using namespace std;

void swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}

void printArray(vector<int> &heapTree)
{
  for (int i = 0; i < heapTree.size(); i++)
    cout << heapTree[i] << " ";
  cout << "\n";
}

void heapify(vector<int> &heapTree, int i)
{
  int largest = i;
  int size = heapTree.size();
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  while (l < size && heapTree[l] > heapTree[largest])
    largest = l;
  while (r < size && heapTree[r] > heapTree[largest])
    largest = r;

  if (largest != i)
  {
    swap(&heapTree[i], &heapTree[largest]);
    heapify(heapTree, largest);
  }

  printArray(heapTree);
}

void insert(vector<int> &heapTree, int num)
{
  int size = heapTree.size();
  if (size == 0)
    heapTree.push_back(num);
  else
  {
    heapTree.push_back(num);
    for (int i = size / 2; i >= 0; i--)
      heapify(heapTree, i);
  }
}

void deleteItem(vector<int> &heapTree, int num)
{
  int size = heapTree.size();
  int i = 0;
  bool notfound = true;

  heapify(heapTree, heapTree[i]);

  for (i = 0; i < size; i++)
  {
    if (num == heapTree[i])
    {
      cout << "Element: " << num << " Found and Successfully Deleted." << endl;
      notfound = false;
      swap(&heapTree[i], &heapTree[size - 1]);
      heapTree.pop_back();
      break;
    }
  }

  if(notfound) cout << "Element Not Found." << endl;

  for (int i = 0; i < size / 2 - 1; i++)
    heapify(heapTree, i);
}

int maxEl(vector<int> heapTree){
    return heapTree[0];
}

int main()
{
  vector<int> heapTree;

  insert(heapTree, 3);
  insert(heapTree, 10);
  insert(heapTree, 1);
  insert(heapTree, 4);
  insert(heapTree, 9);
  insert(heapTree, 12);
  insert(heapTree, 5);
  insert(heapTree, 2);
  insert(heapTree, 11);

  cout << "Max-Heap array: ";
  printArray(heapTree);

//   int max = *max_element(heapTree.begin(), heapTree.end());

//   cout << "Max Element in the Heap: " << max << endl;
  printf("Max Element in the Heap: %d\n", heapTree[0]);

  deleteItem(heapTree, 2);

  cout << "After deleting an element: ";

  printArray(heapTree);
//   system("pause");
  return 0;
}
