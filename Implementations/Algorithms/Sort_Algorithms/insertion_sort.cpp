#include <iostream>

using namespace std;

void insertionSort(int arr[], int n){
    int j, swaps = 0, comps = 0;
     for(j = 1; j < n; j++){
        int i = j - 1; 
        int key = arr[j];
        
        while(i >= 0 && arr[i] > key){
            swaps++;
            arr[i + 1] = arr[i];
            i--;
        }
        comps++;
        arr[i + 1] = key;
        
        for(int k = 0; k < n; k++) printf("Arr[%d] = %d\t", k, arr[k]);
        cout << endl;
    }
    printf("\nComparisons Made: %d\n", comps);
    printf("Element moves Made: %d\n", swaps);
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    // int arr[] = { 4, 3, 2, 10, 12, 1, 5, 6 };
    // int arr[] = { 10, 20, 30, 40, 50, 60 };
    int arr[] = { 60, 50, 40, 30, 20, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    insertionSort(arr, n);
    printArray(arr, n);
    return 0;
}