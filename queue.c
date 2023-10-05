// Que:-  Write a program in c to implement the concept of Circular Queue
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

// Structure to represent the Circular Queue
struct CircularQueue {
    int items[MAX_SIZE];
    int front, rear;
};

// Function to enqueue an element into the Circular Queue
void enqueue(struct CircularQueue* queue, int data) {
    if (((queue->rear + 1) % MAX_SIZE) == queue->front) {
        printf("Queue is full. Cannot enqueue %d\n", data);
    } else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear = (queue->rear + 1) % MAX_SIZE;
        queue->items[queue->rear] = data;
        printf("%d enqueued to the queue\n", data);
    }
}

// Function to dequeue an element from the Circular Queue
int dequeue(struct CircularQueue* queue) {
    int data = -1;
    if (queue->front == -1) {
        printf("Queue is empty. Cannot dequeue\n");
    } else {
        data = queue->items[queue->front];
        if (queue->front == queue->rear) {
            // Queue has only one element, reset front and rear
            queue->front = -1;
            queue->rear = -1;
        } else {
            queue->front = (queue->front + 1) % MAX_SIZE;
        }
    }
    return data;
}

// Function to display the elements in the Circular Queue
void display(struct CircularQueue* queue) {
    if (queue->front == -1) {
        printf("Queue is empty\n");
    } else {
        int i = queue->front;
        printf("Queue elements: ");
        while (1) {
            printf("%d ", queue->items[i]);
            if (i == queue->rear) {
                break;
            }
            i = (i + 1) % MAX_SIZE;
        }
        printf("\n");
    }
}

int main() {
    struct CircularQueue queue;
    queue.front = -1;
    queue.rear = -1;

    int choice, data;

    do {
        printf("\nCircular Queue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(&queue, data);
                break;
            case 2:
                data = dequeue(&queue);
                if (data != -1) {
                    printf("Dequeued element: %d\n", data);
                }
                break;
            case 3:
                display(&queue);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
/*
Output 

Circular Queue Menu:
1. Enqueue
2. Dequeue
3. Display
4. Quit
Enter your choice: 1
Enter data to enqueue: 1
1 enqueued to the queue

Circular Queue Menu:
1. Enqueue
2. Dequeue
3. Display
4. Quit
Enter your choice: 3
Queue elements: 1

Circular Queue Menu:
1. Enqueue
2. Dequeue
3. Display
4. Quit
Enter your choice: 1
Enter data to enqueue: 2
2 enqueued to the queue

Circular Queue Menu:
1. Enqueue
2. Dequeue
3. Display
4. Quit
Enter your choice: 3
Queue elements: 1 2

Circular Queue Menu:
1. Enqueue
2. Dequeue
3. Display
4. Quit
Enter your choice: 2
Dequeued element: 1

Circular Queue Menu:
1. Enqueue
2. Dequeue
3. Display
4. Quit
Enter your choice: 3
Queue elements: 2

Circular Queue Menu:
1. Enqueue
2. Dequeue
3. Display
4. Quit
Enter your choice:

*/



