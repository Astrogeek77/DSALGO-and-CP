#include <iostream>
using namespace std;
 
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++) {  
     
    for (j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1])
            swap(&arr[j], &arr[j+1]);
    
    for(int k = 0; k < n; k++) printf("Arr[%d] = %d\t", k, arr[k]);
        cout << endl;
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
    int arr[] = {60, 50, 40, 30, 20, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    bubbleSort(arr, n);
    printArray(arr, n);
    return 0;
}
 