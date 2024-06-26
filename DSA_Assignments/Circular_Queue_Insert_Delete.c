#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 7

// Structure to represent a circular queue
typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
    int count;
} CircularQueue;

// Function to initialize the circular queue
void initializeQueue(CircularQueue* queue) {
    queue->front = 0;
    queue->rear = -1;
    queue->count = 0;
}

// Function to check if the circular queue is empty
int isEmpty(CircularQueue* queue) {
    return queue->count == 0;
}

// Function to check if the circular queue is full
int isFull(CircularQueue* queue) {
    return queue->count == MAX_SIZE;
}

// Function to insert an element into the circular queue
void enqueue(CircularQueue* queue, int element) {
    if (isFull(queue)) {
        printf("Circular Queue is full. Cannot enqueue.\n");
        exit(EXIT_FAILURE);
    }

    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->data[queue->rear] = element;
    queue->count++;
}

// Function to delete an element from the circular queue
int dequeue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Circular Queue is empty. Cannot dequeue.\n");
        exit(EXIT_FAILURE);
    }

    int element = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAX_SIZE;
    queue->count--;

    return element;
}

// Function to display the elements of the circular queue
void displayQueue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Circular Queue is empty.\n");
        return;
    }

    printf("Circular Queue elements: ");
    int i;
    for (i = 0; i < queue->count; i++) {
        int index = (queue->front + i) % MAX_SIZE;
        printf("%d ", queue->data[index]);
    }
    printf("\n");
}

int main() {
    CircularQueue queue;
    initializeQueue(&queue);

    int choice, element;

    do {
        printf("Circular Queue Operations\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (isFull(&queue)) {
                    printf("Circular Queue is full. Cannot enqueue.\n");
                } else {
                    printf("Enter the element to enqueue: ");
                    scanf("%d", &element);
                    enqueue(&queue, element);
                    printf("Element enqueued successfully.\n");
                }
                break;
            case 2:
                if (isEmpty(&queue)) {
                    printf("Circular Queue is empty. Cannot dequeue.\n");
                } else {
                    element = dequeue(&queue);
                    printf("Dequeued element: %d\n", element);
                }
                break;
            case 3:
                displayQueue(&queue);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    } while (choice != 4);

    return 0;
}
