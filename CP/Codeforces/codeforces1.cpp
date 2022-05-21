#include <iostream>
#include <cstdlib>
#include <limits>
#include <sstream>
#include <vector>
#include <numeric>
#include <ctime>

bool isPrime(int num);
std::vector<int> Range(int begin, int max, int increment);

int main()
{
    int num;
    std::vector<int> factors;
    std::cout << "Enter a Number: ";

    std::cin >> num;
    NearlyPrime(num);


}

bool isPrime(int num)
{
    for (auto n : Range(2, num - 1, 1))
    {
        if ((num % n) == 0)
            return false;
    }
    return true;
}

std::vector<int> Range(int begin, int max, int increment)
{
    std::vector<int> range;
    int i = begin;

    while (i < max)
    {
        range.push_back(i);
        i += increment;
    }

    return range;
}

int NearlyPrime(int num)
{
    int num = num;
    std::vector<int> factors = FactorGenerator(num);
    
}

std::vector<int> FactorGenerator(int num)
{
    std::vector<int> factors;
    int a, c, d;
    a = num;
    int n = 2;

    while (n < a)
    {
        if (a % n == 0)
        {
            factors.push_back(n);
        }

        n++;
    }

    for (int i = 0; i < factors.size(); i++)
    {
        if (isPrime(factors[i]))
        {
            printf("%d \t", factors[i]);
        }
    }

    return factors;
}


