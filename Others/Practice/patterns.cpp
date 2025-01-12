/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void pattern1(int N = 5)
{
    /*
     *  *  *  *  *
     *  *  *  *  *
     *  *  *  *  *
     *  *  *  *  *
     *  *  *  *  *
     */

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            printf(" * ");
        }
        printf("\n");
    }
}

void pattern2(int N = 5)
{
    /*
     *
     *  *
     *  *  *
     *  *  *  *
     *  *  *  *  *
     */

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf(" * ");
        }
        printf("\n");
    }
}

void pattern3(int N = 5)
{
    /*
        1
        1  2
        1  2  3
        1  2  3  4
        1  2  3  4  5
    */

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf(" %d ", j);
        }
        printf("\n");
    }
}

void pattern4(int N = 5)
{
    /*
        1
        2  2
        3  3  3
        4  4  4  4
        5  5  5  5  5
    */

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf(" %d ", i);
        }
        printf("\n");
    }
}

void pattern5(int N = 5)
{
    /*
     *  *  *  *  *
     *  *  *  *
     *  *  *
     *  *
     *
     */

    for (int i = 1; i <= N; i++)
    {
        for (int j = N - i + 1; j > 0; j--)
        {
            printf(" * ");
        }
        printf("\n");
    }
}

void pattern6(int N = 5)
{
    /*
      1  2  3  4  5
      1  2  3  4
      1  2  3
      1  2
      1
    */

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N - i + 1; j++)
        {
            printf(" %d ", j);
        }
        printf("\n");
    }
}

void pattern7(int N = 6)
{
    /*
     *
     ***
     *****
     *******
     *********
     ***********
     */

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - i + 1; j++)
        {
            printf(" ");
        }

        for (int j = 0; j < 2 * i + 1; j++)
        {
            printf("*");
        }

        for (int j = 0; j < N - i + 1; j++)
        {
            printf(" ");
        }
        printf("\n");
    }
}

void pattern8(int N = 6)
{
    /*
     ***********
     *********
     *******
     *****
     ***
     *
     */

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf(" ");
        }

        for (int j = 0; j < 2 * N - (2 * i + 1); j++)
        {
            printf("*");
        }

        for (int j = 0; j < i; j++)
        {
            printf(" ");
        }
        printf("\n");
    }
}

void pattern9(int N = 6)
{
    /*
     *
     ***
     *****
     *******
     *********
     ***********
     ***********
     *********
     *******
     *****
     ***
     *
     */
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - i + 1; j++)
        {
            printf(" ");
        }

        for (int j = 0; j < 2 * i + 1; j++)
        {
            printf("*");
        }

        for (int j = 0; j < N - i + 1; j++)
        {
            printf(" ");
        }
        printf("\n");
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i + 1; j++)
        {
            printf(" ");
        }

        for (int j = 0; j < 2 * N - (2 * i + 1); j++)
        {
            printf("*");
        }

        for (int j = 0; j <= i + 1; j++)
        {
            printf(" ");
        }
        printf("\n");
    }
}

void pattern10(int N = 6)
{
    /*
     *
     **
     ***
     ****
     *****
     ******
     *****
     ****
     ***
     **
     *
     */
    for (int i = 1; i <= 2 * N - 1; i++)
    {

        int stars = i;
        if (i > N)
            stars = 2 * N - i;

        for (int j = 1; j <= stars; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

void pattern11(int N = 5)
{
    /*
        1
        1  2
        1  2  3
        1  2  3  4
        1  2  3  4  5
    */

    int ans = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf(" %d ", ans);
            ans = ans == 0 ? 1 : 0;
        }
        printf("\n");
    }
}

void pattern12(int N = 4)
{
    /*
        1      1
        12    21
        123  321
        12344321
    */

    int spaces = 2 * (N - 1);

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%d", j);
        }

        for (int j = 0; j < spaces; j++)
        {
            printf(" ");
        }

        for (int j = i; j >= 1; j--)
        {
            printf("%d", j);
        }
        printf("\n");
        spaces -= 2;
    }
}

void pattern13(int N = 5)
{
    /*
         1
         2  3
         4  5  6
         7  8  9  10
         11  12  13  14  15
    */

    int cnt = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf(" %d ", cnt++);
        }
        printf("\n");
    }
}

void pattern14(int N = 5)
{
    /*
         A
         A  B
         A  B  C
         A  B  C  D
         A  B  C  D  E
    */

    for (int i = 0; i < N; i++)
    {
        for (char j = 'A'; j <= 'A' + i; j++)
        {
            printf(" %c ", j);
        }
        printf("\n");
    }
}

void pattern15(int N = 5)
{
    /*
         A  B  C  D  E
         A  B  C  D
         A  B  C
         A  B
         A
    */

    for (int i = N - 1; i >= 0; i--)
    {
        for (char j = 'A'; j <= 'A' + i; j++)
        {
            printf(" %c ", j);
        }
        printf("\n");
    }
}

void pattern16(int N = 5)
{
    /*
         A
         B  B
         C  C  C
         D  D  D  D
         E  E  E  E  E
    */

    for (int i = 0; i < N; i++)
    {
        char ch = 'A' + i;
        for (int j = 0; j <= i; j++)
        {
            printf(" %c ", ch);
        }
        printf("\n");
    }
}

void pattern17(int N = 5)
{
    /*
            A
           ABA
          ABCBA
         ABCDCBA
        ABCDEDCBA
    */
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            printf(" ");
        }

        char ch = 'A';
        int breakpoint = (2 * i + 1) / 2;

        for (int j = 1; j <= 2 * i + 1; j++)
        {
            printf("%c", ch);
            if (j <= breakpoint)
                ch++;
            else
                ch--;
        }

        for (int j = 0; j < N - i - 1; j++)
        {
            printf(" ");
        }
        printf("\n");
    }
}

void pattern18(int N = 5)
{
    /*
        E
        DE
        CDE
        BCDE
        ABCDE
    */
    for (int i = 0; i < N; i++)
    {
        char ch = 'A' + N - 1;
        for (char c = ch - i; c <= ch; c++)
        {
            printf("%c", c);
        }
        printf("\n");
    }
}

void pattern19(int N = 5)
{
    /*
     **********
     ****  ****
     ***    ***
     **      **
     *        *
     *        *
     **      **
     ***    ***
     ****  ****
     **********
     */

    int spaces = 0;
    for (int i = 0; i < N; i++)
    {

        for (int j = 1; j <= N - i; j++)
        {
            printf("*");
        }

        for (int j = 0; j < spaces; j++)
        {
            printf(" ");
        }

        for (int j = 1; j <= N - i; j++)
        {
            printf("*");
        }
        printf("\n");
        spaces += 2;
    }

    spaces = 2 * N - 2;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("*");
        }

        for (int j = 0; j < spaces; j++)
        {
            printf(" ");
        }

        for (int j = 1; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
        spaces -= 2;
    }
    // printf("\nNot Implemented Yet.\n");
}

void pattern20(int N = 5)
{
    /*
     *        *
     **      **
     ***    ***
     ****  ****
     **********
     ****  ****
     ***    ***
     **      **
     *        *
     */
    int spaces = 2 * N - 2;
    for (int i = 1; i <= 2 * N - 1; i++)
    {
        int stars = i;

        if (i > N)
            stars = 2 * N - i;

        for (int j = 1; j <= stars; j++)
        {
            printf("*");
        }

        for (int j = 1; j <= spaces; j++)
        {
            printf(" ");
        }

        for (int j = 1; j <= stars; j++)
        {
            printf("*");
        }

        if (i < N)
            spaces -= 2;
        else
            spaces += 2;
        printf("\n");
    }

    // printf("\nNot Implemented Yet.\n");
}

void pattern21(int N = 5)
{
    /*
     *****
     *   *
     *   *
     *   *
     *****
     */
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == 0 || j == 0 || i == N - 1 || j == N - 1)
            {
                printf("*");
            }
            else
                printf(" ");
        }
        printf("\n");
    }
}

void pattern22(int N = 4)
{
    /*
        4444444
        4333334
        4322234
        4321234
        4322234
        4333334
        4444444
    */
    for (int i = 0; i < 2 * N - 1; i++)
    {
        for (int j = 0; j < 2 * N - 1; j++)
        {
            // Initialising the top, down, left and right indices of a cell.
            int top = i;
            int bottom = j;
            int right = (2 * N - 2) - j;
            int left = (2 * N - 2) - i;

            // Min of 4 directions and then we subtract from n
            // because previously we would get a pattern whose border
            // has 0's, but we want with border N's and then decreasing inside.
            int ans = N - (int)min(min(top, bottom), min(left, right));
            printf("%d", ans);
        }

        // As soon as the numbers for each iteration are printed, we move to the
        // next row and give a line break otherwise all numbers
        // would get printed in 1 line.
        printf("\n");
    }

    // printf("\nNot Implemented Yet.\n");
}

int main()
{
    pattern1();
    pattern2();
    pattern3();
    pattern4();
    pattern5();
    pattern6();
    pattern7();
    pattern8();
    pattern9();
    pattern10();
    pattern11();
    pattern12();
    pattern13();
    pattern14();
    pattern15();
    pattern16();
    pattern17();
    pattern18();
    pattern19();
    pattern20();
    pattern21();
    pattern22();
}
