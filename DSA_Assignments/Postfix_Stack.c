#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

// Structure to represent a stack
typedef struct {
    int* data;
    int top;
    int capacity;
} Stack;

// Function to create a new stack
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (int*)malloc(capacity * sizeof(int));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

// Function to check if the stack is empty
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
bool isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Function to push an element onto the stack
void push(Stack* stack, int element) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->data[++stack->top] = element;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[stack->top--];
}

// Function to evaluate the postfix expression
int evaluatePostfixExpression(char* expression) {
    Stack* stack = createStack(strlen(expression));

    for (int i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            int operand = 0;
            while (isdigit(expression[i])) {
                operand = operand * 10 + (expression[i] - '0');
                i++;
            }
            i--; // Adjust the index for the next iteration
            push(stack, operand);
        } else if (expression[i] == ' ') {
            continue;
        } else {
            if (isEmpty(stack)) {
                printf("Invalid postfix expression\n");
                free(stack->data);
                free(stack);
                exit(EXIT_FAILURE);
            }

            int operand2 = pop(stack);
            int operand1 = pop(stack);

            switch (expression[i]) {
                case '+':
                    push(stack, operand1 + operand2);
                    break;
                case '-':
                    push(stack, operand1 - operand2);
                    break;
                case '*':
                    push(stack, operand1 * operand2);
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Division by zero\n");
                        free(stack->data);
                        free(stack);
                        exit(EXIT_FAILURE);
                    }
                    push(stack, operand1 / operand2);
                    break;
                default:
                    printf("Invalid postfix expression\n");
                    free(stack->data);
                    free(stack);
                    exit(EXIT_FAILURE);
            }
        }
    }

    if (isEmpty(stack)) {
        printf("Invalid postfix expression\n");
        free(stack->data);
        free(stack);
        exit(EXIT_FAILURE);
    }

    int result = pop(stack);
    free(stack->data);
    free(stack);
    return result;
}

int main() {
    char expression[100];

    printf("Enter a postfix expression: ");
    fgets(expression, sizeof(expression), stdin);
    expression[strcspn(expression, "\n")] = '\0';

    int value = evaluatePostfixExpression(expression);
    printf("Result: %d\n", value);

    return 0;
}
