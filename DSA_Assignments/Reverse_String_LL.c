#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the stack
typedef struct Node {
    char data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push an element onto the stack
void push(Node** top, char data) {
    Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

// Function to pop an element from the stack
char pop(Node** top) {
    if (*top == NULL) {
        printf("Stack underflow!\n");
        exit(EXIT_FAILURE);
    }
    Node* temp = *top;
    char data = temp->data;
    *top = (*top)->next;
    free(temp);
    return data;
}

// Function to check if the stack is empty
int isEmpty(Node* top) {
    return top == NULL;
}

// Function to reverse a string using a stack
void reverseString(char* str) {
    Node* stack = NULL;
    int i = 0;

    // Push each character of the string onto the stack
    while (str[i] != '\0') {
        push(&stack, str[i]);
        i++;
    }

    i = 0;
    // Pop each character from the stack and store it back in the string
    while (!isEmpty(stack)) {
        str[i] = pop(&stack);
        i++;
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove the newline character from fgets()
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }

    printf("Original String: %s\n", str);

    reverseString(str);

    printf("Reversed String: %s\n", str);

    return 0;
}
