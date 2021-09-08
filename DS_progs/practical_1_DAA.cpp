 // Write a program to find out a roll number from college database using binary search algorithm and bubble sort

#include <bits/stdc++.h>
using namespace std;

class ClgDatabase {
	int n;
	int arr1[];
    
    public: 
	void getvalues(int arr1[], int n){
		cout << "Enter the array values: " << endl;
		for(int i = 0; i < n; i++){
			cin >> arr1[i];
		}
	}
	
	void swap(int *xp, int *yp) 
	{ 
	    int temp = *xp; 
	    *xp = *yp; 
	    *yp = temp; 
	}

	void bubbleSort(int arr1[], int n) 
	{ 
	    int i, j; 
	    for (i = 0; i < n-1; i++)  {
	      for (j = 0; j < n-i-1; j++) {
	      	 if (arr1[j] > arr1[j+1]) 
		       swap(&arr1[j], &arr1[j+1]);
	      }	   
	    } 
	    printArray(arr1, n);	     
	} 

	void printArray(int arr[], int size) 
	{ 
	    int i; 
	    cout << "sorted array =>" << endl;
	    for (i = 0; i < size; i++) 
	        cout << arr[i] << " "; 
	    cout << endl; 
	} 

	int binarySearch(int arr[], int l, int r, int x) {
	    if (r >= l) {
	        int mid = l + (r - l) / 2;
	  
	        if (arr[mid] == x)
	            return mid;
	  
	        if (arr[mid] > x)
	            return binarySearch(arr, l, mid - 1, x);

	        return binarySearch(arr, mid + 1, r, x);
	    }
	  
	    return -1;
	}
};

int main() 
{ 
	 
	int n, arr[n];
	cout << "Enter Size of array: ";
	cin >> n;

    ClgDatabase clgDB;
    
    clgDB.getvalues(arr, n);
    clgDB.bubbleSort(arr, n); 

    int key;
    cout << "Element to search: " << endl;
    cin >> key;
    if(clgDB.binarySearch(arr, 0, n - 1, key) == -1) {
    	cout << "no such element in array" << endl;
    } else {
    	cout << "Element present at index: " << clgDB.binarySearch(arr, 0, n - 1, key) << endl;
    }  
    return 0; 
} 