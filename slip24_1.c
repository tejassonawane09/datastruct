// Program to evaluate postfix expression using dynamic memory allocation

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct stack
{
    int data;
    struct stack *newnode;
};
typedef struct stack stack;
stack *top = NULL;
stack *temp, *newnode;

void push(int no)
{
    newnode = (stack *)malloc(sizeof(stack));
    newnode->data = no;
    newnode->newnode = NULL;
    if (top == NULL)
        top = newnode;
    else
    {
        newnode->newnode = top;
        top = newnode;
    }
}

int pop()
{
    int no;
    if (top == NULL)
        return -1;
    else
    {
        temp = top;
        top = temp->newnode;
        no = temp->data;
        free(temp);
        return no;
    }
}
int isOperator(char op)
{
    if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^')
        return 1;
    else
        return 0;
}

int main()
{
    char str[50];
    printf("\nEnter the postfix Expretion : ");
    scanf("%s", str);
    int op1, op2, result;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            int num = str[i] - '0';
            push(num);
        }
        else if (isOperator(str[i]))
        {
            op1 = pop();
            op2 = pop();
            switch (str[i])
            {
            case '+':
                result = op2 + op1;
                break;
            case '-':
                result = op2 - op1;
                break;
            case '*':
                result = op2 * op1;
                break;
            case '/':
                result = op2 / op1;
                break;
            case '^':
                result = pow(op2, op1);
                break;
            }
            push(result);
        }
    }
    printf("result : %d", pop());
    return 0;
}