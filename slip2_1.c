#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

int top = -1;
char stack[MAX];
void push(char item)
{
    if (top == (MAX - 1))
    {
        printf("\nSTACK OVERFLOW\n");
        return;
    }
    stack[++top] = item;
}
char pop()
{
    if (top == -1)
    {
        printf("\nSTACK UNDERFLOW\n");
        exit(1);
    }
    return stack[top--];
}
void main()
{
    char str[20];
    int i;
    printf("\nENTER THE STRING:");
    gets(str);
    for (i = 0; i < strlen(str); i++)
        push(str[i]);
    for (i = 0; i < strlen(str); i++)
        str[i] = pop();
    printf("\nREVERSED STRING IS:");
    puts(str);
    getch();
}