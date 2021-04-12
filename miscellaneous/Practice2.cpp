#include <iostream>
#include <cstdlib>
#include <limits>
#include <sstream>
#include <vector>
#include <numeric>
#include <ctime>
#include <algorithm>

// std::vector<int> StringMatches(std::string myStr, std::string substr);
// std::vector<std::string> StringReplace(std::string myStr,
//                                        std::string toReplace,
//                                        std::string Replacer);
// std::string CeaserCipher(std::string myString, int key, bool encrypt);
// std::vector<int> Range(int begin, int max, int increment);
// bool isPrime(int num);
// std::vector<int> GeneratePrimes(int maxNum);
// void BubbleSort(std::vector<int> &TheVec);
std::vector<int> randomVecGenerator(int digits, int start, int end);
// int fib(int index);

int main()
{
    // std::string myStr = "to be or not to be be";
    // std::vector<int> matches = StringMatches(myStr, "be");

    // for (int i = 0; i < matches.size(); ++i)
    // {
    //     std::cout << matches[i] << "\t";
    // }

    // std::cout << StringReplace("all you knew, rest is knew",
    //                            "knew",
    //                            "know")
    //           << "\n";

    // std::string message = "I'm a Secret. Keep me safe!";
    // std::string encryptedMsg = CeaserCipher(message, 5, true);
    // std::string decryptedMsg = CeaserCipher(encryptedMsg, 5, false);

    // std::cout << encryptedMsg << "\n";
    // std::cout << decryptedMsg << "\n";

    // int num = 0;
    // std::cout << "Enter a number to check: ";
    // std::cin >> num;

    // std::cout.setf(std::ios::boolalpha);
    // std::cout << "is Prime? : " << isPrime(num) << "\n";

    // int numMax = 0;
    // std::cout << "Enter the Maximum Number: ";
    // std::cin >> numMax;
    // std::vector<int> PrimeVec = GeneratePrimes(numMax);
    // for (auto a : PrimeVec)
    //     std::cout << a << "\n";

    std::vector<int> randomVec = randomVecGenerator(10, 5, 100);
    // std::cout << "Before Sorting: "
    //           << "\n";
    // for (auto n : randomVec)
    // {
    //     std::cout << n << "\n";
    // }
    // std::cout << "\n \n";

    // std::vector<int> oddVecVals;

    // std::copy_if(randomVec.begin(), randomVec.end(), std::back_inserter(oddVecVals), [](int x) { return x % 2 == 1; });
    // for (auto n : oddVecVals)
    // {
    //     std::cout << n << "\n";
    // }

    // std::vector<int> VecVals2;

    // std::cout << "Enter Divisor: ";
    // int divisor;
    // std::cin >> divisor;

    // std::copy_if(randomVec.begin(), randomVec.end(), std::back_inserter(VecVals2), [divisor](int x) { return x % divisor == 0; });
    // for (auto n : VecVals2)
    // {
    //     std::cout << n << "\n";
    // }

    // BubbleSort(randomVec);

    // std::cout << "After Sorting: "
    //           << "\n";
    // for (auto n : randomVec)
    // {
    //     std::cout << n << "\n";
    // }
    // int index;

    // std::cout << "Enter a Index: ";
    // std::cin >> index;
    // printf("fib(%d) = %d", index, fib(index));



}

// std::vector<int> StringMatches(std::string myStr, std::string substr)
// {
//     std::vector<int> nVec;
//     int index = myStr.find(substr, 0);
//     while (index != std::string::npos)
//     {
//         nVec.push_back(index);
//         index = myStr.find(substr, index + 1);
//     }
//     return nVec;
// }

// std::vector<std::string> StringReplace(std::string myStr,
//                                        std::string toReplace,
//                                        std::string Replacer)
// {
//     std::string NewString;
//     std::string word = myStr.replace(0, 4, Replacer);
// }

// std::string CeaserCipher(std::string myString, int key, bool encrypt)
// {
//     std::string myNewString = "";
//     char letter;
//     int charCode = 0;
//     if (encrypt)
//         key *= -1;
//     for (char &c : myString)
//     {
//         if (isalpha(c))
//         {
//             charCode = (int)c;
//             charCode += key;

//             if (isupper(c))
//             {
//                 if (charCode > (int)'Z')
//                 {
//                     charCode -= 26;
//                 }
//                 else if (charCode < (int)'A')
//                 {
//                     charCode += 26;
//                 }
//             }
//             else if (islower(c))
//             {
//                 if (charCode > (int)'z')
//                 {
//                     charCode -= 26;
//                 }
//                 else if (charCode < (int)'a')
//                 {
//                     charCode += 26;
//                 }
//             }
//             letter = charCode;
//             myNewString += letter;
//         }
//         else
//         {
//             letter = c;
//             myNewString += c;
//         }
//     }
// //     return myNewString;
// }

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

// bool isPrime(int num)
// {
//     int count = 0;
//     for (int i = 1; i < num / 2; i++)
//     {
//         if (num % i == 0)
//         {
//             count++;
//         }
//     }
//     if (count > 1)
//     {
//         return false;
//     }
//     else
//     {
//         return true;
//     }

//     for (auto n : Range(2, num - 1, 1))
//         if ((num % n) == 0)
//         {
//             return false;
//         }
//     return true;
// }

// std::vector<int> GeneratePrimes(int maxNum)
// {
//     std::vector<int> PrimeVec;
//     for (auto n : Range(2, maxNum, 1))
//     {
//         if (isPrime(n))
//         {
//             PrimeVec.push_back(n);
//         }
//     }
//     for (auto n : PrimeVec)
//     {
//         std::cout << n << "\n";
//     }
// }

std::vector<int> randomVecGenerator(int digits, int start, int end)
{
    std::vector<int> MyVec;
    srand(time(NULL));
    int i = 0, randdomVal;
    while (i < digits)
    {
        randdomVal = start + std::rand() % ((end + 1) - start);
        MyVec.push_back(randdomVal);

        i++;
    }
    return MyVec;
}

// void BubbleSort(std::vector<int> &TheVec)
// {
//     int i = TheVec.size() - 1;
//     while (i >= 1)
//     {
//         int j = 0;
//         while (j < i)
//         {
//             printf("is %d > %d\n", TheVec[j], TheVec[j + 1]);

//             if (TheVec[j] >= TheVec[j + 1])
//             {
//                 std::cout << "Switch Numbers->"
//                           << "\n";
//                 int temp = TheVec[j];
//                 TheVec[j] = TheVec[j + 1];
//                 TheVec[j + 1] = temp;
//             }
//             else
//             {
//                 std::cout << "Don't Switch!"
//                           << "\n";
//             }

//             j++;

//             for (auto k : TheVec)
//             {
//                 std::cout << k << ", ";
//             }
//         }
//         std::cout << "\n End of Round"
//                   << "\n";
//         i--;
//     }
// }

// int fib(int index)
// {
//     int n1, n2, n3;
//     n1 = 0;
//     n2 = 1;
//     for (int n = 1; n < index; ++n)
//     {
//         n3 = n1 + n2;
//         n1 = n2;
//         n2 = n3;
//         std::cout << n3 << ", ";
//     }
//     return n3;
// }
