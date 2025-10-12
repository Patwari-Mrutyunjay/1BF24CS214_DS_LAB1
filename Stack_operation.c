#include<stdio.h>
#include<stdlib.h>
#define N 5

int stack[N];
int top = -1;

void push() {
    int x;
    if (top == N - 1) {
        printf("Stack Overflow!\n");
    } else {
        printf("Enter the element to be inserted: ");
        scanf("%d", &x);
        stack[++top] = x;
        printf("%d pushed to stack.\n", x);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
    } else {
        printf("The element popped is %d\n", stack[top--]);
    }
}

void peek() {
    if (top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("Top element is %d\n", stack[top]);
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements (top to bottom):\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    char choice;

    while (1) {
        printf("\nEnter your choice:\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1': push(); break;
            case '2': pop(); break;
            case '3': peek(); break;
            case '4': display(); break;
            case '5':
                printf("Program terminated successfully.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
    return 0;
}

