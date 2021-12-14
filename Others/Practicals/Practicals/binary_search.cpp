#include <iostream>
using namespace std;

int binary_search(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binary_search(arr, l, mid - 1, x);
        return binary_search(arr, mid + 1, r, x);
    }

    return -1;
}

int main(void)
{
    int arr[] = {1915332, 1915321, 1915365, 1915335, 1915369, 1915375, 1915309, 1915384};
    int x = 1915321;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binary_search(arr, 0, n - 1, x);
    if (result == -1)
        cout << x << " is not present in the array";
    else
        cout << x << " is present at index " << result << " in the array";
    return 0;
}
