#include <iostream>
using namespace std;

int main()
{
    int age;

    cout << "Enter your age: ";
    cin >> age;

    //person is teenager or not
    if (age >= 13 && age <= 19)
    {
        cout << "Person is Teenager" << endl;
    }
    else
    {
        cout << "Person is not a Teenager" << endl;
    }

    //condition to check voting eligility
    if (age >= 18)
    {
        cout << "Personl is eligible for voting" << endl;
    }
    else
    {
        cout << "Person is not eligible for voating" << endl;
    }

    return 0;
}
