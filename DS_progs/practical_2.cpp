#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int s[5], top = -1;

void push()
{
    if (top == 4)
        printf("\nStack overflow!!!!");
    else
    {
        printf("\nEnter element to insert: ");
        scanf("%d", &s[++top]);
    }
}

void pop()
{
    if (top == -1)
        printf("\nStack underflow!!!");
    else
        printf("\nElement popped is: %d", s[top--]);
}

void display()
{
    int t = top;

    if (t == -1)
        printf("\nStack empty!!");
    else
        printf("\nStack elements are:\n");

    while (t >= 0)
        printf("%d ", s[t--]);
}

void palindrome()
{
    int num[5], rev[5], i, t;

    for (i = 0, t = top; t >= 0; i++, t--)
        num[i] = rev[t] = s[t];

    for (i = 0; i <= top; i++)
        if (num[i] != rev[i])
            break;

    if (i == top + 1)
        printf("\nIt is a palindrome");
    else
        printf("\nIt is not a palindrome");
}

int main()
{
    int ch;
    do
    {
        printf("\n...Stack operations.....\n");
        printf("1.PUSH\n");
        printf("2.POP\n");
        printf("3.Palindrome\n");
        printf("4.Display\n");
        printf("5.Exit\n________________\n");
        printf("Enter choice:");
        scanf("%d", &ch);

        switch (ch)
        {

        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            palindrome();
            break;

        case 4:
            display();
            break;

        case 5:
            exit(0);

        default:
            printf("\nInvalid choice");
        }
    } while (1);

    return 0;
}

