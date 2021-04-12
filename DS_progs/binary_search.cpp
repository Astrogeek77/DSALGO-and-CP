#include <iostream>
using namespace std;

int binary_search(int A[], int x)
{
    int l = 0, h = sizeof(A) - 1;
    int mid = (l + h2);
    while (l <= h)
    {
        if (x == A[mid])
            return mid;
        else if (x > A[mid])
            l = mid + 1;
        else
            h = mid – 1;
    }
    return -1;
}

int main(void)
{
    int arr[] = {32, 21, 65, 35, 69, 75, 9, 84};
    int x = 32;
    int index = binary_search(arr, x);
    if (index == -1)
        cout << x << " is not present in the array";
    else
        cout << x << " is present at index " << index << " in the array";
    return 0;
}