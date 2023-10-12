#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct bst
{
    int data;
    struct bst *lchild, *rchild;
} node;
struct bst *create()
{
    struct bst *temp;
    temp = (struct bst *)malloc(sizeof(struct bst));
    temp->lchild = NULL;
    temp->rchild = NULL;
    return temp;
}
void insert(struct bst *r, struct bst *new1)
{
    if (new1->data < r->data)
    {
        if (r->lchild == NULL)
            r->lchild = new1;
        else
            insert(r->lchild, new1);
    }
    if (new1->data > r->data)
    {
        if (r->rchild == NULL)
            r->rchild = new1;
        else
            insert(r->rchild, new1);
    }
}
void display(struct bst *temp)
{
    if (temp != NULL)
    {
        display(temp->lchild);
        printf("%d\t", temp->data);
        display(temp->rchild);
    }
}
struct bst *search(struct bst *r, int key)
{
    struct bst *temp;
    temp = r;
    while (temp != NULL)
    {
        if (temp->data == key)
            return temp;
        if (key < temp->data)
            temp = temp->lchild;
        else
            temp = temp->rchild;
    }
    return NULL;
}
void main()
{
    int ch, n, i, value;
    struct bst *temp, *root, *newnode;
    while (1)
    {
        printf("\n--------------------------------------------\n");
        printf("1.Create\n2.Display\n3.Search\n4.Exit\nENTER YOUR CHOICE:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nHOW MANY NODES STORED:");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                newnode = create();
                printf("\nENTER NODE DATA:");
                scanf("%d", &newnode->data);
                if (root == NULL)
                    root = newnode;
                else
                    insert(root, newnode);
            }
            break;
        case 2:
            printf("\nDISPLAY BINARY SEARCH TREE:");
            display(root);
            break;
        case 3:
            printf("\nENTER THE NODE VALUE TO BE SEARCHED:");
            scanf("%d", &value);
            temp = search(root, value);
            if (temp == NULL)
                printf("\nNODE NOT FOUND\n");
            else
                printf("\nNODE FOUND\n");
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("INVALID CHOICE!");
        }
    }
    getch();
}