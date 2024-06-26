#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

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

// Partition function for quicksort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choose the last element as the pivot
    int i = (low - 1);      // Index of the smaller element

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Function to perform quicksort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

    // Sort the array using quicksort
    quickSort(numbers, 0, SIZE - 1);

    printf("Sorted array: ");
    printArray(numbers, SIZE);

    return 0;
}
