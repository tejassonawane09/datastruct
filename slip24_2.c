/*
TEJAS SONAWANE
1].remove last node of the singly linked list
2].insert at the beginning of list
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *start, *temp, *q;
void create()
{
    struct node *temp, *q;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("\nENTER THE DATA:");
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
    struct node *q;
    if (start == NULL)
        printf("\nLINK LIST EMPTY");
    else
    {
        q = start;
        while (q != NULL)
        {
            printf("%d\t", q->data);
            q = q->next;
        }
    }
}
void delete_last()
{
    if (start != NULL)
    {
        temp = start;
        while (temp->next != NULL)
        {
            q = temp;
            temp = temp->next;
        }
        q->next = NULL;
        printf("\nDELETED ELEMENT IS :%d", temp->data);
        free(temp);
        printf("\nELEMENT DELETED SUCCESSFULLY");
        getch();
    }
}
void insert_start(int number)
{
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = number;
    temp->next = start;
    start = temp;
}
void main()
{
    int ch, n;
    // clrscr();
    while (1)
    {
        printf("\n-------------------------------\n");
        printf("1.Create\n2.Display\n3.Delete_last\n4.Insert_start\n5.Exit\nENTER THE CHOICE:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            delete_last();
            break;
        case 4:
            printf("\nENTER A NUMBER:");
            scanf("%d", &n);
            insert_start(n);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("\nINVALID CHOICE!");
        }
    }
    getch();
}