#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

// Create Node
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// a) Create a doubly linked list (Insert at end)
void createList(int value) {
    struct Node *newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// b) Insert new node to the left of a specific node (value before key)
void insertLeft(int key, int value) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node *newNode = createNode(value);
    struct Node *temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Key not found!\n");
        return;
    }

    // Insert before head
    if (temp == head) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    newNode->next = temp;
    newNode->prev = temp->prev;
    temp->prev->next = newNode;
    temp->prev = newNode;
}

// c) Delete a node based on value
void deleteValue(int key) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value not found!\n");
        return;
    }

    // Only one node
    if (temp->prev == NULL && temp->next == NULL) {
        head = NULL;
    }
    // Delete head node
    else if (temp->prev == NULL) {
        head = temp->next;
        head->prev = NULL;
    }
    // Delete last node
    else if (temp->next == NULL) {
        temp->prev->next = NULL;
    }
    // Delete middle node
    else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    free(temp);
}

// d) Display list
void display() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = head;
    printf("Doubly Linked List: ");

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value, key;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Create (Insert at end)\n");
        printf("2. Insert to the left of a value\n");
        printf("3. Delete node by value\n");
        printf("4. Display list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            createList(value);
            break;

        case 2:
            printf("Enter key value (insert left of this): ");
            scanf("%d", &key);
            printf("Enter new value: ");
            scanf("%d", &value);
            insertLeft(key, value);
            break;

        case 3:
            printf("Enter value to delete: ");
            scanf("%d", &key);
            deleteValue(key);
            break;

        case 4:
            display();
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }
}
