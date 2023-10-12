/*stack
push
pop
show
exit*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 10
int stack[MAX], top;
void push()
{
    if (top == MAX - 1)
        printf("\nSTACK IS FULL");
    else
    {
        printf("\nENTER THE VALUE:");
        top++;
        scanf("%d", &stack[top]);
    }
}
void pop()
{
    if (top == -1)
        printf("\nSTACK IS EMPTY");
    else
    {
        printf("\nDELETED ELEMENT IS %d", stack[top]);
        top--;
    }
}
void show()
{
    int i;
    for (i = top; i >= 0; i--)
    {
        printf("%d\t", stack[i]);
    }
}
int main()
{
    int ch;
    top = -1;
    while (1)
    {
        printf("\n---------------------\n");
        printf("1.Push\n2.Pop\n3.Show\n4.Exit");
        printf("\nENTER YOUR CHOICE:");
        scanf("%d", &ch);
        printf("\n---------------------\n");
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            show();
            break;
        case 4:
            exit(0);
        default:
            printf("INVALID CHOICE!");
        }
    }
    return 0;
}