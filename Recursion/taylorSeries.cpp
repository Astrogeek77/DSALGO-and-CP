#include<iostream>
using namespace std;

/* definiing taylor series for calaculation value of e for any value of m and n;
*/

double taylorSeries2(int x, int n)
{
    static double p = 1, f = 1; // remains same accross all func calls.
    double r;

    if (n == 0)
        return 1;
    r = taylorSeries2(x, n - 1);
    p = p * x;
    f = f * n;
    return r + p / f;
}

double taylorSeries(int x, int n)
{
    // using homers rule to reduce mutliplication step by half
    static double s;
    if (n == 0)
        return s;
    s = 1 + x * s / n;
    return taylorSeries(x, n - 1);
}

int main(){
    printf("The value of e for x = %d and n = %d is %f\n", 1, 10, taylorSeries(1, 10));
    printf("The value of e for x = %d and n = %d is %f\n", 1, 20, taylorSeries(1, 10));
    printf("The value of e for x = %d and n = %d is %f\n", 4, 20, taylorSeries(4, 20));
}