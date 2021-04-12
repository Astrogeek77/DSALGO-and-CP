// // libraries used

// // #include <bits/stdc++.h>
// // using namespace std;

// // #define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// // #define ll long long
// // #define show(x) cout << x << endl;

// // // main solution
// // int main()
// // {
// //     IOS;
// //     ll t;
// //     cin >> t;
// //     while (t--)
// //     {
// //         ll a, b;
// //         cin >> a >> b;

// //         if (a == b)
// //         {
// //             show(0);
// //             continue;
// //         }

// //         if ((max(a, b) - min(a, b)) % 10 == 0)
// //         {
// //             cout << ((max(a, b) - min(a, b)) / 10) << endl;
// //         }
// //         else
// //             cout << ((max(a, b) - min(a, b)) / 10) + 1 << endl;
// //     }
// // }
// // end solution

// // ************************
// // #include <bits/stdc++.h>
// // using namespace std;

// // #define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// // #define ll long long
// // #define show(x) cout << x << endl;

// // // main solution
// // int main()
// // {
// //     IOS;
// //     ll t;
// //     cin >> t;
// //     while (t--)
// //     {
// //         ll a, b, x, y, n;
// //         cin >> a >> b >> x >> y >> n;
// //         if (max(x, a - n) < max(y, b - n))
// //         {
// //             if (a - n < x)
// //             {
// //                 cout << x * max(y, (b - (n - (a - x)))) << endl;
// //             }
// //             else
// //             {
// //                 cout << (a - n) * b << endl;
// //             }
// //         }
// //         else
// //         {
// //             if (b - n < y)
// //             {
// //                 //cout << y << "  " << a - (b-y) << endl;
// //                 cout << y * max(x, (a - (n - (b - y)))) << endl;
// //             }
// //             else
// //             {
// //                 cout << (b - n) * a << endl;
// //             }
// //         }
// //     }
// // }

// // #include <bits/stdc++.h>
// // using namespace std;

// // #define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// // #define ll long long
// // #define show(x) cout << x << endl;

// // // main solution
// // int main()
// // {
// //     IOS;
// //     ll t;
// //     cin >> t;
// //     while (t--)
// //     {
// //         ll n;
// //         cin >> n;
// //         ll arr[n];

// //         for (int i = 0; i < n; i++)
// //             cin >> arr[i];

// //         for (int i = 1; i <= n; i++)
// //             cout << arr[n - i] << " ";
// //         cout << endl;
// //     }
// // }

// // #include <vector>
// // #include <bits/stdc++.h>

// // using namespace std;
// // using ll = long long;

// // #define f(i, n) for (ll i = 0; i < n; i++)
// // #define r(i, n) for (ll i = n; i >= 0; i--)

// // int main()
// // {
// //     ios::sync_with_stdio(false);
// //     cin.tie(0);

// //     int T;
// //     cin >> T;
// //     while (T--)
// //     {
// //         int n;
// //         cin >> n;
// //         int arr[n];
// //         int z = 0, o = 0;
// //         for (int i = 0; i < n; i++)
// //         {
// //             cin >> arr[i];
// //             if (arr[i] == 0)
// //                 z++;
// //             else
// //                 o++;
// //         }

// //         if (z * 2 >= n)
// //         {
// //             cout << n / 2 << endl;
// //             for (int i = 0; i < n / 2; i++)
// //                 cout << 0 << ' ';
// //             cout << endl;
// //         }
// //         else
// //         {
// //             int x = n / 2;
// //             if (x % 2 == 1)
// //                 x++;
// //             cout << x << endl;
// //             for (int i = 0; i < x; i++)
// //                 cout << 1 << ' ';
// //             cout << endl;
// //         }
// //     }
// // }

// #include <iostream>
// using namespace std;

// class Check
// {
// private:
//     int i;

// public:
//     Check() : i(0) {}
//     void operator++()
//     {
//         ++i;
//     }
//     void Display()
//     {
//         cout << "i=" << i << endl;
//     }
// };

// int main()
// {
//     Check obj;

//     obj.Display();

//     ++obj;

//     obj.Display();

//     return 0;
// }

// #include <iostream>
// using namespace std;

// class Complex
// {
// private:
//     float real;
//     float imag;

// public:
//     Complex() : real(0), imag(0) {}
//     void input()
//     {
//         cout << "Enter real and imaginary parts respectively: ";
//         cin >> real;
//         cin >> imag;
//     }

//     Complex operator-(Complex c2)
//     {
//         Complex temp;
//         temp.real = real + c2.real;
//         temp.imag = imag + c2.imag;

//         return temp;
//     }

//     void output()
//     {
//         if (imag < 0)
//             cout << "Output Complex number: " << real << imag << "i";
//         else
//             cout << "Output Complex number: " << real << "+" << imag << "i";
//     }
// };

// int main()
// {
//     Complex c1, c2, result;

//     cout << "Enter first complex number:\n";
//     c1.input();

//     cout << "Enter second complex number:\n";
//     c2.input();

//     result = c1 - c2;
//     result.output();

//     return 0;
// }

// Program to compute absolute value
// Works for both int and float

// #include <iostream>
// using namespace std;
// class cm
// {
//     int v;

// public:
//     cm() {}
//     cm(int n) { v = n; }
//     void show() { cout << "Equvalent cm: " << v; }
// };

// class m
// {
//     float v;

// public:
//     void in()
//     {
//         cout << "input value in meter : ";
//         cin >> v;
//     }
//     /*Conversion function : for converting one class to another class [here cm to m class] */
//     operator cm() { return cm(v * 100); }
// };
// int main()
// {
//     m mo;
//     mo.in();
//     cm co;
//     co = mo;
//     co.show();
//     return 0;
// }

#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    char text[200];

    fstream file;
    file.open("file1.txt", ios::out | ios::in);

    cout << "Write text to be written on file." << endl;
    cin.getline(text, sizeof(text));

    // Writing on file
    file << text << endl;

    // Reding from file
    file >> text;
    cout << text << endl;

    //closing the file
    file.close();
    return 0;
}
