/*Menu driven program for singly linked list
  1 Create
  2 Display
  3 Exit*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct singly
{
    int data;
    struct singly *next;
} *start;

void create()
{
    struct singly *temp, *q;
    temp = (struct singly *)malloc(sizeof(struct singly));
    printf("Enter the data:");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (start == NULL)
        start = temp;
    else
    {
        q = start;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = temp;
    }
}

void display()
{
    struct singly *q;
    if (start == NULL)
        printf("Link List Empty");
    else
    {
        q = start;
        while (q != NULL)
        {
            printf("%d ", q->data);
            q = q->next;
        }
    }
}

void main()
{
    int choice;
    // clrscr();
    start = NULL;
    while (1)
    {
        printf("\n----------Singly Linked List---------------------\n");
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid Choice");
        }
    }
}