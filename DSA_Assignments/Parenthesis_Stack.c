#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
bool isFull(Stack* stack) {
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

// Function to get the top element from the stack
char peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[stack->top];
}

// Function to match parentheses in the expression
bool matchParentheses(char* expression) {
    Stack* stack = createStack(strlen(expression));

    for (int i = 0; i < strlen(expression); i++) {
        char ch = expression[i];

        if (ch == '(' || ch == '[' || ch == '{') {
            push(stack, ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (isEmpty(stack)) {
                free(stack);
                return false;
            }

            char top = peek(stack);
            if ((ch == ')' && top == '(') || (ch == ']' && top == '[') || (ch == '}' && top == '{')) {
                pop(stack);
            } else {
                free(stack);
                return false;
            }
        }
    }

    bool result = isEmpty(stack);
    free(stack);
    return result;
}

// Function to evaluate the expression
int evaluateExpression(char* expression) {
    if (!matchParentheses(expression)) {
        printf("Mismatched parentheses\n");
        return 0;
    }

    Stack* stack = createStack(strlen(expression));

    for (int i = 0; i < strlen(expression); i++) {
        char ch = expression[i];

        if (ch == ' ' || ch == '\t') {
            continue;
        } else if (ch == '(' || ch == '[' || ch == '{') {
            push(stack, ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            int result = 0;
            if (isEmpty(stack)) {
                free(stack);
                return result;
            }

            char top = peek(stack);
            if ((ch == ')' && top == '(') || (ch == ']' && top == '[') || (ch == '}' && top == '{')) {
                pop(stack);
            } else {
                free(stack);
                return result;
            }
        } else if (ch >= '0' && ch <= '9') {
            int operand = ch - '0';
            while (i + 1 < strlen(expression) && expression[i + 1] >= '0' && expression[i + 1] <= '9') {
                operand = operand * 10 + (expression[i + 1] - '0');
                i++;
            }
            push(stack, operand);
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            if (isEmpty(stack)) {
                free(stack);
                return 0;
            }

            int operand1 = pop(stack);
            int operand2 = pop(stack);

            switch (ch) {
                case '+':
                    push(stack, operand2 + operand1);
                    break;
                case '-':
                    push(stack, operand2 - operand1);
                    break;
                case '*':
                    push(stack, operand2 * operand1);
                    break;
                case '/':
                    if (operand1 == 0) {
                        printf("Division by zero\n");
                        free(stack);
                        return 0;
                    }
                    push(stack, operand2 / operand1);
                    break;
            }
        } else {
            free(stack);
            return 0;
        }
    }

    int result = pop(stack);
    free(stack);
    return result;
}

int main() {
    char expression[100];

    printf("Enter an expression: ");
    fgets(expression, sizeof(expression), stdin);
    expression[strcspn(expression, "\n")] = '\0';

    int value = evaluateExpression(expression);
    printf("Result: %d\n", value);

    return 0;
}
