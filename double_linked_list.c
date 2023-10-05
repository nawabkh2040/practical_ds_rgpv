// Que:- Write a program in c to create double linked list and display the elements in reverse order.
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to insert a new node at the end of the doubly linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// Function to display the doubly linked list in reverse order
void displayReverse(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    printf("Doubly Linked List (in reverse order): ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, data;

    printf("Enter the number of elements in the doubly linked list: ");
    scanf("%d", &n);

    printf("Enter the elements of the doubly linked list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertAtEnd(&head, data);
    }

    displayReverse(head);

    return 0;
}

/*
Output
Enter the number of elements in the doubly linked list: 3
Enter the elements of the doubly linked list:
3
2
1
Doubly Linked List (in reverse order): 1 -> 2 -> 3 -> NULL

*/