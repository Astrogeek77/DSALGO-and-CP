#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int t;
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        int arr[t];

        for (int j = 0; j < t; j++) {
            arr[j] = t - j;
        }
        for (int k = 0; k < t; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
    return 0;
}
