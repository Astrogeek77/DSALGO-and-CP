#include <iostream>

using namespace std;

void merge(int arr[], int l, int m, int r){
    
    int n1 = l - m + 1;
    int n2 = r - m ;
    
    cout << "n1: " << n1 << endl;
    cout << "n2: " << n2 << endl;
    
    int arr1[n1], arr2[n2];
    
    for(int i = 0; i < n1; i++){
        arr1[i] = arr[l + i]; 
        printf("arr[%d]: %d \n", i, arr[i]);
    }
    for(int j = 0; j < n2; j++){
        arr1[j] = arr[r + j + 1]; 
        printf("arr[%d]: %d \n", j, arr[j]);
    }
    
    int i, j, k;
    i = 0;
    j = 0;
    k = l;
    
    cout << "i: " << i << endl;
    cout << "j: " << j << endl;
    cout << "k: " << k << endl;
    
    while(i < n1 && j < n2){
        if(arr1[i] <= arr2[j]){
            arr[k] = arr1[i];
            i++;
        } else {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }
    
     while (i < n1) {
        arr[k] = arr1[i];
        k++;
        i++;
      }
    
      while (j < n2) {
        arr[k] = arr2[j];
        k++;
        j++;
      }

}

void mergeSort(int arr[], int l, int r){
    if(l < r) {
        int mid = l + (r - l) / 2;
        
        cout << "mid: " << mid << endl;
    
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        
        merge(arr, l, mid, r);
    } 
    // printf("xjsskk");
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}


int main() {
     int arr[] = {6, 5, 12, 10, 9, 1};
     int size = sizeof(arr) / sizeof(arr[0]);
    
     mergeSort(arr, 0, 6);
    
     cout << "Sorted array: \n";
     printArray(arr, 6);

    return 0;
}