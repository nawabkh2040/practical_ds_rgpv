// Write a program in c to implement bubble sort.
#include <stdio.h>
void bubbleSort(int arr[], int size) {
    int temp;
    int swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = 0; // Flag to check if any swaps were made in this pass

        for (int j = 0; j < size - 1 - i; j++) {
            // If the current element is greater than the next element, swap them
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1; // Set the swapped flag to 1
            }
        }

        // If no two elements were swapped in this pass, the array is already sorted
        if (swapped == 0) {
            break;
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    // Perform bubble sort
    bubbleSort(arr, size);

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