// Write a program in c to implement quick sort.

#include <stdio.h>

// Function to swap two elements in an array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = (low - 1); // Index of the smaller element

    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++; // Increment the index of the smaller element
            swap(&arr[i], &arr[j]);
        }
    }

    // Swap the pivot element with the element at (i+1), placing the pivot in its correct position
    swap(&arr[i + 1], &arr[high]);
    return (i + 1); // Return the pivot index
}

// Function to perform quick sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Find the pivot element such that
        // elements smaller than the pivot are on the left
        // elements greater than the pivot are on the right
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after the pivot
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    // Perform quick sort
    quickSort(arr, 0, size - 1);

    printf("\nSorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
/*
Output 
Original array: 64 34 25 12 22 11 90
Sorted array: 11 12 22 25 34 64 90
*/