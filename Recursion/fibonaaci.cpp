#include <iostream>
#include <vector>
using namespace std;

vector<int> hashFib(100, -1);

int fib(int n)
{
    if (n <= 1)
    {
        hashFib[n] = n;
        return n;
    }
    if (hashFib[n - 1] == -1)
        hashFib[n - 1] = fib(n - 1);

    if (hashFib[n - 2] == -1)
        hashFib[n - 2] = fib(n - 2);

    hashFib[n] = hashFib[n - 1] + hashFib[n - 2];    

    return hashFib[n - 1] + hashFib[n - 2];
}

int main() {
    printf("The %dth fibonaaci number is: %d\n", 10, fib(10));
    printf("The %dth fibonaaci number is: %d\n", 9, fib(9));
    printf("The %dth fibonaaci number is: %d\n", 11, fib(11));
}