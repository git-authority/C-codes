#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in a set
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert an element into a set
void insertElement(Node** set, int element) {
    Node* newNode = createNode(element);

    if (*set == NULL) {
        *set = newNode;
    } else {
        Node* current = *set;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to perform the union of two sets
Node* unionSets(Node* set1, Node* set2) {
    Node* result = NULL;
    Node* current = set1;

    while (current != NULL) {
        insertElement(&result, current->data);
        current = current->next;
    }

    current = set2;
    while (current != NULL) {
        if (!containsElement(result, current->data)) {
            insertElement(&result, current->data);
        }
        current = current->next;
    }

    return result;
}

// Function to check if an element is present in a set
int containsElement(Node* set, int element) {
    Node* current = set;
    while (current != NULL) {
        if (current->data == element) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

// Function to perform the intersection of two sets
Node* intersectSets(Node* set1, Node* set2) {
    Node* result = NULL;
    Node* current = set1;

    while (current != NULL) {
        if (containsElement(set2, current->data)) {
            insertElement(&result, current->data);
        }
        current = current->next;
    }

    return result;
}

// Function to display the elements of a set
void displaySet(Node* set) {
    if (set == NULL) {
        printf("Set is empty.\n");
    } else {
        Node* current = set;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

// Function to free memory occupied by a set
void freeSet(Node* set) {
    Node* current = set;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    Node* set1 = NULL;
    Node* set2 = NULL;
    Node* result = NULL;
    int element, numElements;

    printf("Enter the number of elements in Set 1: ");
    scanf("%d", &numElements);

    printf("Enter the elements of Set 1:\n");
    for (int i = 0; i < numElements; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &element);
        insertElement(&set1, element);
    }

    printf("\nEnter the number of elements in Set 2: ");
    scanf("%d", &numElements);

    printf("Enter the elements of Set 2:\n");
    for (int i = 0; i < numElements; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &element);
        insertElement(&set2, element);
    }

    printf("\nSet 1: ");
    displaySet(set1);

    printf("Set 2: ");
    displaySet(set2);

    result = unionSets(set1, set2);
    printf("Union: ");
    displaySet(result);

    result = intersectSets(set1, set2);
    printf("Intersection: ");
    displaySet(result);

    // Free memory occupied by sets
    freeSet(set1);
    freeSet(set2);
    freeSet(result);

    return 0;
}
