// Que:- Write a program in c to search the elements in the linked list and display the position

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to search for an element in the linked list and return its position
int searchElement(struct Node* head, int key) {
    int position = 1;
    while (head != NULL) {
        if (head->data == key) {
            return position;
        }
        head = head->next;
        position++;
    }
    return -1; // Element not found
}

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

int main() {
    struct Node* head = NULL;
    int n, key;

    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);

    printf("Enter the elements of the linked list:\n");
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        insertAtBeginning(&head, data);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    int position = searchElement(head, key);
    if (position != -1) {
        printf("Element found at position %d\n", position);
    } else {
        printf("Element not found in the linked list\n");
    }

    return 0;
}

/*
OutPut 
Enter the number of elements in the linked list: 8
Enter the elements of the linked list:
1
2
3
5
6
4
9
7
Enter the element to search: 5
Element found at position 5
*/