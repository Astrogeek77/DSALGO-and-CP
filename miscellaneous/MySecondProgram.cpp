#include <iostream>
using namespace std;

void compare(int x, int y, int z)
{

    if (x == y && y == z)
    {

        cout << "marks of all students are same";
    }
    else if (x == y || x == z || y == z)
    {

        if (x == y)
        {

            if (x < z)
            {

                cout << "student 3 has highest marks\nstudent 1 and 2 have equal mark";
            }
            else
            {

                cout << "student 1 and 2 have equal and highest marks";
            }
        }
        else if (x == z)
        {

            if (x < y)
            {

                cout << "student 2 has highest marks\nstudent 1 and 3 have equal marks";
            }
            else
            {

                cout << "student 1 and 3 have equal and highest marks";
            }
        }
        else
        {

            if (x < y)
            {

                cout << "student 2 and 3 have equal and highest marks";
            }
            else
            {

                cout << "student 1 has highest marks\nstudent 2 and 3 have equal marks";
            }
        }
    }
    else
    {

        if (x < y || x < z)
        {

            if (y < z)
            {

                cout << "student 3 have highest marks";
            }
            else
            {

                cout << "student 2 have highest marks";
            }
        }
        else
        {

            cout << "student 1 have highest marks";
        }
    }
}

int main()
{

    int a, b, c;

    cout << "Enter marks of student 1 -> ";

    cin >> a;

    cout << "Enter marks of student 2 -> ";

    cin >> b;

    cout << "Enter marks of student 3 -> ";

    cin >> c;

    compare(a, b, c);
}
