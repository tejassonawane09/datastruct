#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct list
{
    int data;
    struct list *link;
} *front = NULL, *rear = NULL;
void create(int m)
{
    struct list *tmp;
    tmp = (struct list *)malloc(sizeof(struct list));
    tmp->data = m;
    tmp->link = NULL;
    if (front == NULL)
        front = tmp;
    else
        rear->link = tmp;
    rear = tmp;
}
void del()
{
    struct list *tmp;
    if (front == NULL)
        printf("\n\nQUEUE IS FULL");
    else
    {
        tmp = front;
        printf("\n\nDELETED IS ELEMENT % d", tmp->data);
        front = front->link;
        free(tmp);
    }
}
void disp()
{
    struct list *q;
    if (front == NULL)
        printf("\n\nQUEUE IS EMPTY");
    else
    {
        q = front;
        while (q != NULL)
        {
            printf("% d == >", q->data);
            q = q->link;
        }
    }
}
void main()
{
    int i, n, ch;
    // clrscr();
    do
    {
        printf("\n\nMENU");
        printf("\n\n1.INSERT ");
        printf("\n\n2.DELETE ");
        printf("\n\n3.DISPLAY");
        printf("\n\n4.EXIT");
        printf("\n\nENTER YOUR CHOICE:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\n\nENTER THE NUMBER:");
            scanf("%d", &n);
            create(n);
            break;
        case 2:
            del();
            break;
        case 3:
            printf("\n\nQUEUE ELEMENTS ARE \n\n");
            disp();
            break;
        case 4:
            exit(0);
        }
    } while (ch != 4);
    getch();
}