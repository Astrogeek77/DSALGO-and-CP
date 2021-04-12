#include <iostream>
#include <cstdlib>
#include <limits>
#include <sstream>
#include <vector>
#include <numeric>
#include <ctime>

const double PI = 3.14159;
// std::vector<int> Range(int begin, int max, int increment);
// std::string TrimWhitespaces(std::string MyString);
// std::vector<std::string> StringtoVector(std::string MyString, char seperator);
// std::string VectortoString(std::vector<std::string> &MyVec, char seperator);

int main()
{
    // Exploring the datatypes =>

    // unsigned short int unshint = 23;
    // short int shint = 0;
    // unsigned int unint = -4342542;
    // long int loint = 2535453354546;
    // signed int siint = 456;
    // int num = 12;

    // std::cout << "unsigned Min: " << std::numeric_limits<unsigned int>::min() << std::endl;

    // std::cout << "signed Min: " << std::numeric_limits<signed int>::min() << std::endl;

    // std::cout << "unsigned Max: " << std::numeric_limits<unsigned int>::max() << std::endl;

    // std::cout << "signed Max: " << std::numeric_limits<signed int>::max() << std::endl;

    // std::cout << "int Min: " << std::numeric_limits<int>::min() << std::endl;

    // std::cout << "int Max: " << std::numeric_limits<int>::max() << std::endl;

    // std::cout << "unsigned Min: " << std::sizeof(unsigned int) << std::endl;

    // Working With Strings =>

    // std::string ques("Enter No of miles: \n");
    // std::string sNum1;
    // std::cout << ques;
    // getline(std::cin, sNum1);

    // double nNum1 = stod(sNum1);
    // double nNum2 = nNum1 * 1.60934;

    // printf("%.4f miles are %.4f kilometers", nNum1, nNum2);

    // Conditional Statements =>

    // std::string userAge("Enter Your Age: \n");
    // std::string sAge;
    // std::cout << userAge;
    // getline(std::cin, sAge);

    // int nAge = std::stoi(sAge);
    // if (nAge < 5)
    // {
    //     std::cout << "Too Young for School!";
    // }
    // else if (nAge >= 5 && nAge <= 8)
    // {
    //     std::cout << "Go to Low School!";
    // }
    // else if (nAge >= 9 && nAge <= 15)
    // {
    //     std::cout << "Go to Medium School!";
    // }
    // else if (nAge >= 16 && nAge <= 18)
    // {
    //     std::cout << "Go to High School";
    // }
    // else if (nAge >= 19 && nAge <= 23)
    // {
    //     std::cout << "Go to College";
    // }
    // else
    // {
    //     std::cout << "Not Appropriate Age for Schooling!";
    // }

    // Calculator
    // double a = 0, c = 0, result;
    // std::string ques("Enter Calculation (eg 10 - 6): ");
    // std::cout << ques;
    // std::vector<std::string> senWords;
    // std::string sSentence = "";
    // getline(std::cin, sSentence);

    // std::stringstream ss(sSentence);
    // std::string indivStr;
    // char cSpace = ' ';

    // while (getline(ss, indivStr, cSpace))
    // {
    //     senWords.push_back(indivStr);
    // }

    // // for(int i = 0; i < senWords.size(); i++){
    // //     std::cout << senWords[i];
    // // }

    // a = std::stoi(senWords[0]);
    // std::string b = senWords[1];
    // c = std::stoi(senWords[2]);

    // if (b == "+")
    // {
    //     printf("%.3f + %.3f = %.3f", a, c, a + c);
    // }
    // else if (b == "-")
    // {
    //     printf("%.3f - %.3f = %.3f", a, c, a - c);
    // }
    // else if (b == "*")
    // {
    //     printf("%.3f * %.3f = %.3f", a, c, a * c);
    // }
    // else if (b == "/")
    // {
    //     printf("%.3f / %.3f = %.3f", a, c, a / c);
    // }
    // // else if (b == "%")
    // // {
    // //     printf("%.3f %% %.3f = %.3f", a, c, a % c);
    // // }
    // else
    // {
    //     std::cout << "Please Enter Valid Opertions!";
    // }

    // return 0;

    // vector
    // std::vector<int> myVec(10);
    // std::iota(std::begin(myVec), std::end(myVec), 0);

    // for (int i = 0; i < myVec.size(); i++)
    // {
    //     std::cout << myVec[i] << "\n";
    // }

    // return 0;

    // std::vector<int> myVec(10);
    // std::iota(std::begin(myVec), std::end(myVec), 1);

    // for (int i = 0; i < myVec.size(); i++)
    // {
    //     if (myVec[i] % 2 == 0)
    //     {
    //         std::cout << myVec[i] << " is even \n";
    //     }
    // }

    // int begin, max, increment;
    // std::cout << "Enter Starting: ";
    // std::cin >> begin;
    // std::cout << "Enter max value: ";
    // std::cin >> max;
    // std::cout << "Enter increment step: ";
    // std::cin >> increment;
    // std::vector<int> range = Range(begin, max, increment);

    // for (int i = 0; i < range.size(); i++)
    // {
    //     std::cout << range[i] << "\n";
    // }

    // std::cout << "The Height of the Tree: ";
    // int treeheight = 0, space = 0, stumpSpace = 0, hashes = 2;
    // std::cin >> treeheight;
    // stumpSpace = treeheight - 1;
    // space = treeheight - 1;

    // while (treeheight != 0)
    // {
    //     for (auto y : Range(1, space, 1))
    //         std::cout << " ";
    //     for (auto y : Range(1, hashes, 1))
    //         std::cout << "#";

    //     std::cout << "\n";
    //     space--;
    //     hashes += 2;
    //     treeheight--;
    // }

    // for (auto y : Range(1, stumpSpace, 1))
    //     std::cout << " ";
    // std::cout << "#";

    // Exception handling....

    // double num1 = 0, num2 = 0;
    // std::cout << "Enter Numerator: ";
    // std::cin >> num1;
    // std::cout << "Enter Denominator: ";
    // std::cin >> num2;

    // try
    // {
    //     if (num2 == 0)
    //     {
    //         throw("Cannot Divide by Zero! \nProgram Terminated!");
    //     }
    //     else
    //     {
    //         printf("%.1f / %.1f = %.2f", num1, num2, (num1 / num2));
    //     }
    // }

    // catch (const char *exp)
    // {
    //     std::cout << "Error: " << exp;
    // }

    // srand(time(NULL));
    // int SecretNum = std::rand() % 100;

    // int guess = 0, count = 0;

    // do
    // {
    //     std::cout << "Enter a Guess: ";
    //     std::cin >> guess;
    //     if (guess < SecretNum)
    //         std::cout << "Too Small!\n";
    //     if (guess > SecretNum)
    //         std::cout << "Too Big!\n";
    //     count++;
    // } while (guess != SecretNum);

    // std::cout << "You Guessed it Right!\n";
    // std::cout << "You made "
    //           << count << " Guesses!";

    // a - z = 97 - 122
    // A - Z = 65 - 90

    // std::cout << "Enter a String(in Uppercase): ";
    // std::string MyString, SecString = "";
    // std::cin >> MyString;

    // for (char c : MyString)
    // {
    //     SecString += std::to_string((int)c - 23);
    // }

    // std::cout << "SecString: " << SecString << "\n";

    // MyString = "";

    // for (int i = 0; i < SecString.length(); i += 2)
    // {
    //     std::string sCharCode = "";
    //     sCharCode += SecString[i];
    //     sCharCode += SecString[i + 1];

    //     int nCharCode = std::stoi(sCharCode);
    //     char chCharCode = nCharCode + 23;
    //     MyString += chCharCode;
    // }

    // std::cout << "Normal String: " << MyString << "\n";

    // std::vector<std::string> vecWords = StringtoVector("Hello World! I'm Gautam", ' ');

    // for (int i = 0; i < vecWords.size(); i++)
    // {
    //     std::cout << vecWords[i] << "\n";
    // }

    // std::vector<std::string> VecToConvert(3);
    // VecToConvert[0] = "John";
    // VecToConvert[1] = "Suzy";
    // VecToConvert[2] = "Ben";

    // std::string MyString = VectortoString(VecToConvert, ' ');
    // std::cout << MyString << "\n";

    std::string astr = "    hey, how are you    ";
    astr = TrimWhitespaces(astr);
    std::cout << "*" << astr << "*";
}

// std::vector<int> Range(int begin, int max, int increment)
// {
//     std::vector<int> range;
//     int i = begin;

//     while (i < max)
//     {
//         range.push_back(i);
//         i += increment;
//     }

//     return range;
// }

// std::vector<std::string> StringtoVector(std::string MyString, char seperator)
// {
//     std::vector<std::string> myVec;
//     std::stringstream ss(MyString);
//     std::string indivStr;

//     while (getline(ss, indivStr, seperator))
//     {
//         myVec.push_back(indivStr);
//     }
//     return myVec;
// }

// std::string VectortoString(std::vector<std::string> &MyVec, char seperator)
// {
//     std::string MyString = "";

//     for (auto a : MyVec)
//     {
//         MyString += a + seperator;
//     }
//     return MyString;
// }

// std::string TrimWhitespaces(std::string MyString)
// {
//     std::string whitespaces(" \t\f\n\r");
//     MyString.erase(MyString.find_last_not_of(whitespaces) + 1);
//     MyString.erase(MyString.find_first_not_of(whitespaces));
//     return MyString;
// }