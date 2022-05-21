int kthElement(int arr1[], int arr2[], int n, int m, int k)
{
    int ans = 0, i = 0, j = 0, count = 0, check = -1, last = 0;

    while ((i < n) && (j < m))
    {
        if (arr1[i] <= arr2[j])
        {
            last = arr1[i];
            i++;
            count++;
        }
        else
        {
            last = arr2[j];
            j++;
            count++;
        }
        if (count == k)
            return last;
    }
    if (i == n)
        return arr2[j + k - count - 1];
    else
        return arr1[i + k - count - 1];
}
