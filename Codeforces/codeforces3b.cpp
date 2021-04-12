#include <bits/stdc++.h>
using namespace std;

int main() {
    int num, n, m, count;
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        scanf("%d", &n);
        scanf("%d", &m);
        count = 0;
        char arr[n][m];

        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> arr[j][k];
            }
        }

        for (int j = 0; j < m - 1; j++) {
            if (arr[n - 1][j] != 'R') {
                count++;
            }
        }

        for (int l = 0; l < n - 1; l++) {
            if (arr[l][m - 1] != 'D') {
                count++;
            }
        }

        printf("%d\n", count);
    }
    return 0;
}