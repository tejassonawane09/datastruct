#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct bst
{
    int data;
    struct bst *lchild, *rchild;
} node;
int cnt = 0, leafcnt = 0, nleafcnt = 0;
struct bst *create()
{
    struct bst *temp = (struct bst *)malloc(sizeof(struct bst));
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
void inorder(struct bst *temp)
{
    if (temp != NULL)
    {
        inorder(temp->lchild);
        printf("%d\t", temp->data);
        inorder(temp->rchild);
    }
}
void postorder(struct bst *temp)
{
    if (temp != NULL)
    {
        postorder(temp->lchild);
        postorder(temp->rchild);
        printf("%d\t", temp->data);
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
    int ch, n, i, value;
    struct bst *newnode, *root, *temp;
    root = NULL;
    while (1)
    {
        printf("\n---------------------------\n");
        printf("1.Create\n2.Search\n3.Inorder\n4.Preorder\n5.Postorder\n6.Exit");
        printf("\n---------------------------\n");
        printf("\nENTER YOUR CHOICE:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nHOW MANY NODES TO CREATE:");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                newnode = create();
                printf("\nENTER THE NODE DATA:");
                scanf("%d", &newnode->data);
                if (root == NULL)
                    root = newnode;
                else
                    insert(root, newnode);
            }
            break;
        case 2:
            printf("\nENTER THE NODE VALUE TO BE SEARCHED:");
            scanf("%d", &value);
            temp = search(root, value);
            if (temp == NULL)
                printf("\nNODE NOT FOUND\n");
            else
                printf("\nNODE FOUND\n");
            break;
        case 3:
            printf("\nINORDER TRAVERSAL:");
            inorder(root);
            break;
        case 4:
            printf("\nPREORDER TRAVERSAL:");
            preorder(root);
            break;
        case 5:
            printf("\nPOSTORDER TRAVERSAL:");
            postorder(root);
            break;
        case 6:
            exit(0);
        default:
            printf("INVALID CHOICE!");
        }
    }
    getch();
}