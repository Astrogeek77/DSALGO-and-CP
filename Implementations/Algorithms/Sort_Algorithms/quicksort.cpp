#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int getRandomIdx(int low, int high)
{
    int randomIdx = low + (rand() % (high - low + 1));
    cout << "Random Idx: " << randomIdx << endl;

    return randomIdx;
    // return low;
}

int partition(int arr[], int low, int high)
{
    int pvtIdx = getRandomIdx(low, high);
    // int pvtIdx = low;
    int pivot = arr[pvtIdx];

    for (int i = low; i <= high; i++)
    {
        if(i == pvtIdx)
            continue;

        if (arr[i] < pivot)
        {
            pvtIdx++;
            swap(&arr[i], &arr[pvtIdx]);
        }
    }
    swap(&arr[low], &arr[pvtIdx]);
    return pvtIdx; // i + 1 is the partition index
}

void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1); // excluding the pivot in both
        quicksort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}