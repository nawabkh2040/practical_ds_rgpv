// Write a program in c to search the element using sequential/linear search.

#include <stdio.h>

// Function to perform sequential (linear) search
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i; // Return the index where the key is found
        }
    }
    return -1; // Return -1 if the key is not found
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    int key;
    printf("Enter the element to search for: ");
    scanf("%d", &key);

    int result = linearSearch(arr, size, key);

    if (result != -1) {
        printf("%d found at index %d\n", key, result);
    } else {
        printf("%d not found in the array\n", key);
    }

    return 0;
}


/*
Output
Enter the element to search for: 34
34 found at index 1
*/