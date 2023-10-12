// circular singly linked list
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct link
{
    int info;
    struct link *next;
};
struct link *start = NULL;
void create()
{
    struct link *temp, *move;
    int num;
    temp = (struct link *)malloc(sizeof(struct link));
    printf("\nENTER NUMBER:");
    scanf("%d", &num);
    temp->info = num;
    temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
        temp->next = start;
    }
    else
    {
        move = start;
        while (move->next != start)
        {
            move = move->next;
        }
        move->next = temp;
        temp->next = start;
    }
}
void display()
{
    struct link *move;
    if (start == NULL)
        printf("\nLINKED LIST IS EMPTY\n");
    else
    {
        move = start;
        printf("\nELEMENTS OF LINKED LIST ARE:\n");
        while (move->next != start)
        {
            printf("%d|%d->", move->info, move->next);
            move = move->next;
        }
        printf("%d|%d", move->info, move->next);
    }
}
void main()
{
    int ch;
    // clrscr();
    while (1)
    {
        printf("\n-----------------------------------\n");
        printf("1.Create\n2.Display\n3.Exit\nENTER YOUR CHOICE:");
        scanf("%d", &ch);
        printf("\n-----------------------------------\n");
        switch (ch)
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
            printf("INVALID CHOICE!");
        }
    }
}