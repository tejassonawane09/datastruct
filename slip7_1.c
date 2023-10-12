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
struct bst *minvalue(struct bst *node)
{
    struct bst *current = node;
    while (current && current->lchild != NULL)
        current = current->lchild;

    return current;
}
struct bst *deletenode(struct bst *root, int key)
{
    struct bst *temp;
    if (root == NULL)
        return root;
    if (key < root->data)
        root->lchild = deletenode(root->lchild, key);
    else if (key > root->data)
        root->rchild = deletenode(root->rchild, key);
    else
    {
        if (root->lchild == NULL)
        {
            temp = root->rchild;
            free(root);
            return temp;
        }
        else if (root->rchild == NULL)
        {
            temp = root->lchild;
            free(root);
            return temp;
        }

        temp = minvalue(root->rchild);
        root->data = temp->data;

        root->rchild = deletenode(root->rchild, temp->data);
    }
    return root;
}
void main()
{
    int ch, n, i, value;
    struct bst *newnode, *temp, *root;
    while (1)
    {
        printf("\n-------------------------------------------\n");
        printf("1.Create\n2.Display\n3.Delete\n4.Exit\nENTER YOUR CHOICE:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nENTER HOW MANY NODE:");
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
            printf("\nENTER THE NODE VALUE TO BE DELETED:");
            scanf("%d", &value);
            root = deletenode(root, value);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("INVALID CHOICE!");
        }
    }
}