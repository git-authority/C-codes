#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 8

// Structure to represent a queue
typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
    int count;
} Queue;

// Function to initialize the queue
void initializeQueue(Queue* queue) {
    queue->front = 0;
    queue->rear = -1;
    queue->count = 0;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->count == 0;
}

// Function to check if the queue is full
int isFull(Queue* queue) {
    return queue->count == MAX_SIZE;
}

// Function to insert an element into the queue
void enqueue(Queue* queue, int element) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        exit(EXIT_FAILURE);
    }

    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->data[queue->rear] = element;
    queue->count++;
}

// Function to delete an element from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        exit(EXIT_FAILURE);
    }

    int element = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAX_SIZE;
    queue->count--;

    return element;
}

int main() {
    Queue queue;
    initializeQueue(&queue);

    int choice, element;

    do {
        printf("Queue Operations\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (isFull(&queue)) {
                    printf("Queue is full. Cannot enqueue.\n");
                } else {
                    printf("Enter the element to enqueue: ");
                    scanf("%d", &element);
                    enqueue(&queue, element);
                    printf("Element enqueued successfully.\n");
                }
                break;
            case 2:
                if (isEmpty(&queue)) {
                    printf("Queue is empty. Cannot dequeue.\n");
                } else {
                    element = dequeue(&queue);
                    printf("Dequeued element: %d\n", element);
                }
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    } while (choice != 3);

    return 0;
}
