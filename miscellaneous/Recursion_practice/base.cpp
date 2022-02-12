#include <iostream>
using namespace std;

int getBinary(int decimal)
{
    if (decimal == 0)
        return 0;

    return decimal % 2 + 10 * getBinary(decimal / 2);
}

int main()
{
    int num;
    cout << "Enter the number: ";
    cin >> num;
    int result = getBinary(num);
    cout << "Binary String is: " << result << endl;
}