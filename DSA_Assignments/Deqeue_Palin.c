#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

// Structure to represent a node in the deque
typedef struct Node {
    char data;
    struct Node* next;
    struct Node* prev;
} Node;

// Structure to represent a deque
typedef struct {
    Node* front;
    Node* rear;
} Deque;

// Function to create a new node
Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to initialize a deque
void initializeDeque(Deque* deque) {
    deque->front = NULL;
    deque->rear = NULL;
}

// Function to check if the deque is empty
int isEmpty(Deque* deque) {
    return deque->front == NULL;
}

// Function to insert an element at the front of the deque
void insertFront(Deque* deque, char data) {
    Node* newNode = createNode(data);
    if (isEmpty(deque)) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
    }
}

// Function to insert an element at the rear of the deque
void insertRear(Deque* deque, char data) {
    Node* newNode = createNode(data);
    if (isEmpty(deque)) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->prev = deque->rear;
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
}

// Function to remove an element from the front of the deque
char removeFront(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque underflow!\n");
        exit(EXIT_FAILURE);
    }
    Node* temp = deque->front;
    char data = temp->data;
    deque->front = deque->front->next;
    if (deque->front == NULL) {
        deque->rear = NULL;
    } else {
        deque->front->prev = NULL;
    }
    free(temp);
    return data;
}

// Function to remove an element from the rear of the deque
char removeRear(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque underflow!\n");
        exit(EXIT_FAILURE);
    }
    Node* temp = deque->rear;
    char data = temp->data;
    deque->rear = deque->rear->prev;
    if (deque->rear == NULL) {
        deque->front = NULL;
    } else {
        deque->rear->next = NULL;
    }
    free(temp);
    return data;
}

// Function to check whether a given string is a palindrome or not
int isPalindrome(char* str) {
    Deque deque;
    initializeDeque(&deque);
    int length = strlen(str);
    int i;

    // Insert each character of the string into the rear of the deque
    for (i = 0; i < length; i++) {
        char ch = tolower(str[i]);
        if (isalpha(ch)) {
            insertRear(&deque, ch);
        }
    }

    // Compare characters from both ends of the deque
    while (!isEmpty(&deque)) {
        if (deque.front != deque.rear && deque.front->data != deque.rear->data) {
            return 0; // Not a palindrome
        }
        removeFront(&deque);
        if (!isEmpty(&deque)) {
            removeRear(&deque);
        }
    }

    return 1; // Palindrome
}

int main() {
    char str[MAX_LENGTH];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove the newline character from fgets()
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }

    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
