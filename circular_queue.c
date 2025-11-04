#include <stdio.h>
#define N 5

int front = -1, rear = -1;
int queue[N];

void enqueue(int x) {
    if (front == (rear + 1) % N)
        printf("Queue Overflow!\n");
    else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
        printf("Element %d is inserted\n", queue[rear]);
    }
    else {
        rear = (rear + 1) % N;
        queue[rear] = x;
        printf("Element %d is inserted\n", queue[rear]);
    }
}

void dequeue() {
    if (front == -1 && rear == -1)
        printf("Queue Underflow!\n");

    else if (front == rear) {
        printf("Element %d is deleted\n", queue[front]);
        front = rear = -1;
    }
    else {
        printf("Element %d is deleted\n", queue[front]);
        front = (front + 1) % N;
    }
}

void display() {
    if (front == -1 && rear == -1)
        printf("Queue Underflow!\n");
    else {
        int i = front;
        printf("Queue elements: ");
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % N;
        }
        printf("%d\n", queue[rear]);
    }
}

int main() {
    printf("Circular Queue Operations!\n");
    int x;
    char m;
    printf("Select:\n a. Enqueue\n b. Dequeue\n c. Display\n d. Exit\n");

    while (1) {
        scanf(" %c", &m);

        switch (m) {
            case 'a':
                scanf("%d", &x);
                enqueue(x);
                break;

            case 'b':
                dequeue();
                break;

            case 'c':
                display();
                break;

            case 'd':
                printf("Program ended successfully!\n");
                return 0;

            default:
                printf("Invalid choice, enter again!\n");
                break;
        }
    }
}
