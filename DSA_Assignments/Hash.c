#include <stdio.h>
#include <stdlib.h>

#define SIZE 11

// Structure for a hash node
struct Node {
    int key;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

// Function to calculate the hash index for a key
int hashFunction(int key) {
    return key % SIZE;
}

// Function to insert a key into the hash table
void insertKey(struct Node* hashTable[], int key) {
    int index = hashFunction(key);

    struct Node* newNode = createNode(key);
    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        struct Node* current = hashTable[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to display the hash table
void displayHashTable(struct Node* hashTable[]) {
    for (int i = 0; i < SIZE; i++) {
        printf("%d: ", i);
        struct Node* current = hashTable[i];
        while (current != NULL) {
            printf("%d -> ", current->key);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() {
    struct Node* hashTable[SIZE];
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = NULL;
    }

    int keys[] = {23, 24, 36, 16, 17, 7, 11, 1, 14, 29, 20, 56, 42};
    int numKeys = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < numKeys; i++) {
        insertKey(hashTable, keys[i]);
    }

    displayHashTable(hashTable);

    return 0;
}
