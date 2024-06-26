#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

// Function to generate random numbers between min and max (inclusive)
int getRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to perform insertion sort
void insertionSort(int arr[], int size) {
    int i, j, key;

    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
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

    // Sort the array using insertion sort
    insertionSort(numbers, SIZE);

    printf("Sorted array: ");
    printArray(numbers, SIZE);

    return 0;
}
