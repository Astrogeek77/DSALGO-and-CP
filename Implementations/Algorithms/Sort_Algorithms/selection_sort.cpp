#include <bits/stdc++.h>
using namespace std;
 
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n){
    int i, j, min, comps = 0, swaps = 0;
    for(i = 0; i < n - 1; i++){
        min = i;
      
        for(j = i + 1; j < n; j++){
            comps++;
            if(arr[j] < arr[min]){
                min = j;
                swaps++;
            }
            swap(&arr[min], &arr[i]);
        }
        for(int k = 0; k < n; k++) printf("Arr[%d] = %d\t", k, arr[k]);
        cout << endl;
    }
    
    printf("\nComparisons Made: %d\n", comps);
    printf("Element moves Made: %d\n", swaps);
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
 
int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    // int arr[] = { 60, 50, 40, 30, 20, 10};
    // int arr[] = { 10, 20, 30, 40, 50, 60 };
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    
    printArray(arr, n);

    system("PAUSE");
    return 0;
}