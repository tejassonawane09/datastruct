// create circular double linked list and display it
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev, *next;
} *head;
void insertion()
{
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("\nENTER VALUE:");
    scanf("%d", &item);
    ptr->data = item;
    if (head == NULL)
    {
        head = ptr;
        ptr->next = head;
        ptr->prev = head;
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->prev = temp;
        head->prev = ptr;
        ptr->next = head;
    }
    printf("\nNODE INSERTED\n");
}

void display()
{
    struct node *ptr;
    ptr = head;
    if (head == NULL)
    {
        printf("\nNOTHING TO PRINT!");
    }
    else
    {
        printf("\nPRINTING VALUES:\n");
        while (ptr->next != head)
        {
            printf("%d-%d-%d=>", ptr->prev, ptr->data, ptr->next);
            ptr = ptr->next;
        }
        printf("%d-%d-%d", ptr->prev, ptr->data, ptr->next);
    }
}
int main()
{
    int choice = 0;
    head = NULL;
    while (choice != 3)
    {
        printf("\n-------------------------------------");
        printf("\n1.Insert\n2.Display\n3.Exit\n\nEnter Your Choice:");
        scanf("\n%d", &choice);
        printf("\n--------------------------------------");
        switch (choice)
        {
        case 1:
            insertion();
            break;
        case 2:
            display();
            break;
        case 3:
            exit(0);
        default:
            printf("PLEASE ENTER VALID CHOICE!");
        }
    }
    return (0);
}