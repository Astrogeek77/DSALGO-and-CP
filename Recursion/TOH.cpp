#include <iostream>
using namespace std;

// void TOH2(int n, int src, int aux, int dest)
// {
//     if (n > 0)
//     {
//         TOH2(n - 1, src, dest, aux);
//         printf("Move %d to %d \n", src, dest);
//         TOH2(n - 1, aux, src, dest);
//     }
// }

void TOH(int n, char src, char aux, char dest)
{
    if (n > 0)
    {
        TOH(n - 1, src, dest, aux);
        printf("Move disk %d from rod %c to rod %c \n", n, src, dest);
        TOH(n - 1, aux, src, dest);
    }
}

int main()
{
    // int n = 3, a = 1, b = 2, c = 3;
    int n = 4;
    char a = 'A', b = 'B', c = 'C';
    printf("Steps to move %d blocks (%c, %c, %c): \n", n, a, b, c);
    TOH(n, a, b, c);
}