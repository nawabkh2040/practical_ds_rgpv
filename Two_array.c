//Que:- Write a program in c to read two arrays from the user and merge them and display the elements 
#include <stdio.h>

int main() {
    int arr1[100], arr2[100], mergeArr[200];
    int size1, size2, mergedSize;

    // Input for the first array
    printf("Enter the size of the first array: ");
    scanf("%d", &size1);

    printf("Enter elements of the first array:\n");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }

    // Input for the second array
    printf("Enter the size of the second array: ");
    scanf("%d", &size2);

    printf("Enter elements of the second array:\n");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    // Merging the two arrays
    mergedSize = size1 + size2;
    for (int i = 0; i < size1; i++) {
        mergeArr[i] = arr1[i];
    }
    for (int i = 0; i < size2; i++) {
        mergeArr[size1 + i] = arr2[i];
    }

    // Displaying the merged array
    printf("Merged array: ");
    for (int i = 0; i < mergedSize; i++) {
        printf("%d ", mergeArr[i]);
    }
    printf("\n");

    return 0;
}

// output
/*
Enter the size of the first array: 3
Enter elements of the first array:
1
2
3
Enter the size of the second array: 3
Enter elements of the second array:
9
8
7
Merged array: 1 2 3 9 8 7

*/