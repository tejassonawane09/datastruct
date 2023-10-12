#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct dlink
{
    int info;
    struct dlink *left, *right;
};
struct dlink *start = NULL, *end = NULL;
void insert()
{
    struct dlink *temp, *move;
    int num;
    temp = (struct dlink *)malloc(sizeof(struct dlink));
    printf("\nENTER THE NUMBER:");
    scanf("%d", &num);
    temp->info = num;
    temp->left = NULL;
    temp->right = NULL;
    if (start == NULL)
    {
        start = temp;
        end = temp;
    }
    else
    {
        move = start;
        while (move->right != NULL)
        {
            move = move->right;
        }
        move->right = temp;
        temp->left = move;
        end = temp;
    }
}
void show()
{
    struct dlink *move;
    if (start == NULL)
        printf("\nLIST IS EMPTY\n");
    else
    {
        move = start;
        printf("\n");
        while (move != NULL)
        {
            printf("%d-%d-%d=>", move->left, move->info, move->right);
            move = move->right;
        }
    }
}
void main()
{
    int ch;
    while (1)
    {
        printf("\n--------------Main_Menu---------------\n");
        printf("1.Insert\n2.Show\n3.Exit\nENTER YOUR CHOICE:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            show();
            break;
        case 3:
            exit(0);
        default:
            printf("\nINVALID CHOICE!");
        }
    }
    getch();
}