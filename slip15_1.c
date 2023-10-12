#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for the stack
struct Stack
{
    char data;
    struct Stack *next;
};

// Function to create a new stack node
struct Stack *createNode(char data)
{
    struct Stack *newNode = (struct Stack *)malloc(sizeof(struct Stack));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack)
{
    return (stack == NULL);
}

// Function to push an element onto the stack
void push(struct Stack **stack, char data)
{
    struct Stack *newNode = createNode(data);
    newNode->next = *stack;
    *stack = newNode;
}

// Function to pop an element from the stack
char pop(struct Stack **stack)
{
    if (isEmpty(*stack))
    {
        printf("Stack is empty\n");
        exit(1);
    }
    char data = (*stack)->data;
    struct Stack *temp = *stack;
    *stack = (*stack)->next;
    free(temp);
    return data;
}

// Function to check if a character is an operator
int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to return precedence of an operator
int precedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    return 0;
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char infix[], char postfix[])
{
    struct Stack *stack = NULL;
    int i, j;
    i = j = 0;

    for (i = 0; infix[i]; i++)
    {
        // If the character is an operand, add it to the postfix expression
        if (isalnum(infix[i]))
        {
            postfix[j++] = infix[i];
        }
        // If the character is an open parenthesis, push it onto the stack
        else if (infix[i] == '(')
        {
            push(&stack, infix[i]);
        }
        // If the character is a close parenthesis, pop operators from the stack and add to postfix until an open parenthesis is encountered
        else if (infix[i] == ')')
        {
            while (!isEmpty(stack) && stack->data != '(')
            {
                postfix[j++] = pop(&stack);
            }
            if (!isEmpty(stack) && stack->data != '(')
            {
                printf("Invalid expression\n");
                exit(1);
            }
            else
            {
                pop(&stack); // Pop the open parenthesis
            }
        }
        // If the character is an operator, pop operators from the stack and add to postfix if they have higher precedence
        else if (isOperator(infix[i]))
        {
            while (!isEmpty(stack) && precedence(infix[i]) <= precedence(stack->data))
            {
                postfix[j++] = pop(&stack);
            }
            push(&stack, infix[i]);
        }
    }

    // Pop any remaining operators from the stack and add to postfix
    while (!isEmpty(stack))
    {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}

int main()
{
    char infix[100], postfix[100];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
