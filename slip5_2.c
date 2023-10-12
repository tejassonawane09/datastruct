/* write a c program to create a linked list with a given number in which the data part
contain individual digit of a numer*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
// #include <alloc.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL, *temp = NULL;
void main()
{
    int num, a[10], i, j;
    // clrscr();
    printf("enter the number:-");
    scanf("%d", &num);
    i = 0;
    while (num > 0)
    {
        a[i] = num % 10;
        i++;
        num = num / 10;
    }
    i--;
    printf("\nthe display of linked list is:-\n");
    for (j = i; j >= 0; j--)
    {
        if (start == NULL)
        {
            start = malloc(sizeof(struct node));
            start->data = a[j];
            printf("%d", start->data);
            start->next = NULL;
            temp = start;
        }
        else
        {
            temp->next = malloc(sizeof(struct node));
            temp->next->data = a[j];
            printf(",%d", temp->next->data);
            temp->next->next = NULL;
            temp = temp->next;
        }
    }
    getch();
}