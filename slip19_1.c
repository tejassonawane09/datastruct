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

// Function to reverse a word in the string
void reverseWord(char *word)
{
    struct Node *stack = NULL;

    for (int i = 0; i < strlen(word); i++)
    {
        push(&stack, word[i]);
    }

    for (int i = 0; i < strlen(word); i++)
    {
        word[i] = pop(&stack);
    }
}

// Function to reverse each word in the input string
void reverseWordsInString(char *str)
{
    char *token = strtok(str, " ");
    while (token != NULL)
    {
        reverseWord(token);
        token = strtok(NULL, " ");
    }
}

int main()
{
    char input[1000];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';

    reverseWordsInString(input);
    printf("Reversed string: %s\n", input);

    return 0;
}
