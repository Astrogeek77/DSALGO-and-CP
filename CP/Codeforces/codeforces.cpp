#include <string>
#include <iostream>
using namespace std;

int main() {

    int t, len;
    scanf("%d", &t);

    for (int a = 0; a < t; a++) {
        scanf("%d", &len);
        int arr[len];
        for (int b = 0; b < len; b++) {
            scanf("%d", &arr[b]);
        }
        for (int c = 0; c < len; c++) {
            for (int d = c + 1; d < len; d++) {
                int temp;
                if (arr[d] < arr[c]) {
                    temp = arr[c];
                    arr[c] = arr[d];
                    arr[d] = temp;
                }
            }
        }
        int el = arr[0], count = 0;
        for (int e = 1; e < len; e++) {
            if (arr[e] - arr[0] == 1 || arr[e] - el == 0) {
                el = arr[e];
                count++;
            }
        }
        if (count == len - 1) {
            puts("YES");
        }
        else {
            puts("NO");
        }
    }
    return 0;
}