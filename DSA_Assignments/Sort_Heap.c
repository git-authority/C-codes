#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

// Function to generate random numbers between min and max (inclusive)
int getRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree rooted at index i
void heapify(int arr[], int n, int i) {
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than current largest
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not the root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Function to perform heap sort
void heapSort(int arr[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from heap one by one
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to the end
        swap(&arr[0], &arr[i]);

        // Call heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int numbers[SIZE];

    // Generate random numbers
    srand(time(0));
    for (int i = 0; i < SIZE; i++) {
        numbers[i] = getRandomNumber(1, 100);
    }

    printf("Original array: ");
    printArray(numbers, SIZE);

    // Sort the array using heapsort
    heapSort(numbers, SIZE);

    printf("Sorted array: ");
    printArray(numbers, SIZE);

    return 0;
}
