#include <iostream>
#include <cstdlib>
#include <limits>
#include <sstream>
#include <vector>
#include <numeric>
#include <ctime>

int main()
{
    int a = 0, b = 0;
    std::cin >> a >> b;
    for (int i = a; i <= b; i++)
    {
        if (i <= 9)
        {
            if (i == 1)
            {
                puts("one");
            }
            else if (i == 2)
            {
                puts("two");
            }
            else if (i == 3)
            {
                puts("three");
            }
            else if (i == 4)
            {
                puts("four");
            }
            else if (i == 5)
            {
                puts("five");
            }
            else if (i == 6)
            {
                puts("six");
            }
            else if (i == 7)
            {
                puts("seven");
            }
            else if (i == 8)
            {
                puts("eight");
            }
            else if (i == 9)
            {
                puts("nine");
            }
        }
    }

    for (int i = 10; i <= b; i++)
    {
        if (i % 2 == 0)
        {
            puts("even");
            continue;
        }
        else if (i % 2 == 1)
        {
            puts("odd");
            continue;
        }
    }
    return 0;
}
