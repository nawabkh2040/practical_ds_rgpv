// Write a program in c to implement the Stack with Push, Pop and Display operations.
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int items[MAX_SIZE];
    int top;
};

void initialize(struct Stack *stack) {
    stack->top = -1;
}

int isEmpty(struct Stack *stack) {
    return (stack->top == -1);
}

int isFull(struct Stack *stack) {
    return (stack->top == MAX_SIZE - 1);
}

void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push %d\n", value);
    } else {
        stack->top++;
        stack->items[stack->top] = value;
        printf("%d pushed onto the stack\n", value);
    }
}

int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    } else {
        int poppedValue = stack->items[stack->top];
        stack->top--;
        return poppedValue;
    }
}

void display(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= stack->top; i++) {
            printf("%d ", stack->items[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Stack stack;
    initialize(&stack);

    int choice, value;

    while (1) {
        printf("\nStack Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                printf("Popped element: %d\n", pop(&stack));
                break;
            case 3:
                display(&stack);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
/*
OutPut 

Stack Menu:
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 3
Stack is empty.

Stack Menu:
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 1
Enter the value to push: 1
1 pushed onto the stack

Stack Menu:
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 1
Enter the value to push: 2
2 pushed onto the stack

Stack Menu:
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 1
Enter the value to push: 3
3 pushed onto the stack

Stack Menu:
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 3
Stack elements: 1 2 3

Stack Menu:
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 2
Popped element: 3

Stack Menu:
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 3
Stack elements: 1 2

*/