#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

// Function to generate random numbers between min and max (inclusive)
int getRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to swap two numbers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform selection sort
void selectionSort(int arr[], int size) {
    int i, j, minIndex;

    for (i = 0; i < size - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(&arr[i], &arr[minIndex]);
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

    // Sort the array using selection sort
    selectionSort(numbers, SIZE);

    printf("Sorted array: ");
    printArray(numbers, SIZE);

    return 0;
}
