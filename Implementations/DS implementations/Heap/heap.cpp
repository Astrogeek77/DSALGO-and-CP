#include <iostream>
#include <vector>
using namespace std;

// #MAX 100

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

class MinHeap
{
public:
    vector<int> heap;
    MinHeap(vector<int> arr)
    {
        for (int i = arr.size(); i > 0; i++)
        {
            heap[i] = arr[arr.size() - 1];
            siftDown(i);
        }
        return heap;
    }

    void siftUp(int i)
    {
        int parent = (i - 1) / 2;
        while (i != 0 && heap[parent] > heap[i])
        {
            swap(heap[parent], heap[i]);
            i = parent;
            parent = (i - 1) / 2;
        }
    }

    void siftDown(int i)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        while ((left < (int)heap.size() && heap[left] < heap[i]) || (right < (int)heap.size() && heap[right] < heap[i]))
        {
            int smallest;
            if (right >= heap.size() || heap[left] < heap[right])
                smallest = left;
            else
                smallest = right;
            swap(heap[smallest], heap[i]);
            i = smallest;
            left = 2 * i + 1;
            right = 2 * i + 2;
        }
    }

    void insert(int element)
    {
        heap.push_back(element);
        siftDown(heap.size() - 1);
    }

    int getMin()
    {
        if (heap.size() > 0)
            return heap[0];
        else
            return 0;
    }

    int extractMin()
    {
        if (heap.size() == 0)
            return 0;
        int minVal = heap[0];
        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        siftDown(0);
        return minVal;
    }

    void updatebyindex(int i, int newValue)
    {
        int old = heap[i];
        heap[i] = newValue;
        if (old < newValue)
            siftDown(i);
        else
            siftUp(i);
    }

    void updatebyvalue(int old, int newValue)
    {
        int index;
        for (int i = 0; i < heap.size(); i++)
        {
            if (heap[i] == old)
            {
                index = i;
                break;
            }
            updatebyindex(index, newValue);
        }
    }
};

vector<int> heapSort(vector<int> arr)
{
    vector<int> result;

    for (int i = 0; i < arr.size(); i++)
    {
        result.push_back(MinHeap(arr).extractMin());
    }
    return result;
}

int main()
{
    vector<int> arr = {23, 3, 435, 4, 45, 3, 32, 1, 0};
    vector<int> result = heapSort(arr);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
}
