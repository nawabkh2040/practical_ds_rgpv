// Write a program in c to search the element using binary search.

#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid; // Return the index where the key is found
        }

        if (arr[mid] < key) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }

    return -1; // Return -1 if the key is not found
}

int main() {
    int arr[] = {11, 12, 22, 25, 34, 64, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    int key;
    printf("Enter the element to search for: ");
    scanf("%d", &key);

    int result = binarySearch(arr, size, key);

    if (result != -1) {
        printf("%d found at index %d\n", key, result);
    } else {
        printf("%d not found in the array\n", key);
    }

    return 0;
}
/*
Output
Enter the element to search for: 25
25 found at index 3
*/