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
void inorder(struct bst *temp)
{
    if (temp != NULL)
    {
        inorder(temp->lchild);
        printf("%d\t", temp->data);
        inorder(temp->rchild);
    }
}
void preorder(struct bst *temp)
{
    if (temp != NULL)
    {
        printf("%d\t", temp->data);
        preorder(temp->lchild);
        preorder(temp->rchild);
    }
}
void main()
{
    int ch, n, i;
    struct bst *newnode, *root;
    while (1)
    {
        printf("\n----------------------------------------\n");
        printf("1.Create\n2.Inorder\n3.Postorder\n4.Exit\nENTER YOUR CHOICE:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nENTER HOW MANY NODES YOU STORED:");
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
            printf("\nInorder:");
            inorder(root);
            break;
        case 3:
            printf("\nPreorder:");
            preorder(root);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("INVALID CHOICE!");
        }
    }
}