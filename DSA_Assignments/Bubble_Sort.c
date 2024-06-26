#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

// Function to generate random numbers between min and max (inclusive)
int getRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to perform bubble sort
void bubbleSort(int arr[], int size) {
    int i, j;

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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

    // Sort the array using bubble sort
    bubbleSort(numbers, SIZE);

    printf("Sorted array: ");
    printArray(numbers, SIZE);

    return 0;
}
