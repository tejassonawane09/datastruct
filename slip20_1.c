#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a stack node
struct Node
{
    char data;
    struct Node *next;
};

// Function to create a new stack node
struct Node *newNode(char data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to check if the stack is empty
int isEmpty(struct Node *root)
{
    return (root == NULL);
}

// Function to push a character onto the stack
void push(struct Node **root, char data)
{
    struct Node *node = newNode(data);
    node->next = *root;
    *root = node;
}

// Function to pop a character from the stack
char pop(struct Node **root)
{
    if (isEmpty(*root))
    {
        printf("Stack underflow\n");
        exit(1);
    }
    struct Node *temp = *root;
    *root = (*root)->next;
    char popped = temp->data;
    free(temp);
    return popped;
}

// Function to check if a string is a palindrome
int isPalindrome(char *str)
{
    struct Node *stack = NULL;

    // Push characters onto the stack
    for (int i = 0; i < strlen(str); i++)
    {
        push(&stack, str[i]);
    }

    // Pop characters from the stack and compare with the original string
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] != pop(&stack))
        {
            return 0; // Not a palindrome
        }
    }

    return 1; // Palindrome
}

int main()
{
    char input[1000];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';

    if (isPalindrome(input))
    {
        printf("The string is a palindrome.\n");
    }
    else
    {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
