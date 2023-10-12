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
void search()
{
    int num;
    printf("\nENTER THE DAT TO BE SEARCHED:");
    scanf("%d", &num);
    temp = start;
    while (temp != NULL)
    {
        if (temp->data == num)
        {
            printf("\n%d IS FOUND IN LIST", num);
            return;
        }
        temp = temp->next;
    }
    printf("\n%d IS NOT FOUND IN LIST", num);
}
void display()
{
    struct node *q;
    if (start == NULL)
        printf("LINK LIST EMPTY");
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
void insert_end()
{
    int number;
    printf("\nENTER A NUMBER:");
    scanf("%d", &number);
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = number;
    temp->next = NULL;
    q = start;
    while (q->next != NULL)
    {
        q = q->next;
    }
    q->next = temp;
}
void main()
{
    int ch;
    while (1)
    {
        printf("\n-------------------------------------------------------\n");
        printf("1.Create\n2.Display\n3.Search\n4.Insert At Last\n5.Exit\nENTER YOUR CHOICE:");
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
            search();
            break;
        case 4:
            insert_end();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("INVALID CHOICE! ");
        }
    }
    getch();
}
