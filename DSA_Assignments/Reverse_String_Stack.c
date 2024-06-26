#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a stack
typedef struct {
    char* data;
    int top;
    int capacity;
} Stack;

// Function to create a new stack
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (char*)malloc(capacity * sizeof(char));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Function to push an element onto the stack
void push(Stack* stack, char element) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->data[++stack->top] = element;
}

// Function to pop an element from the stack
char pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[stack->top--];
}

// Function to reverse a string using a stack
void reverseString(char* str) {
    int length = strlen(str);

    // Create a stack
    Stack* stack = createStack(length);

    // Push each character of the string onto the stack
    for (int i = 0; i < length; i++) {
        push(stack, str[i]);
    }

    // Pop characters from the stack and store them back in the string
    for (int i = 0; i < length; i++) {
        str[i] = pop(stack);
    }

    // Free the memory allocated for the stack
    free(stack->data);
    free(stack);
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    reverseString(str);

    printf("Reversed string: %s\n", str);

    return 0;
}
