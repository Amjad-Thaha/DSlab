#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertAtFront(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtPosition(int data, int position) {
    if (position == 0) {
        insertAtFront(data);
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    struct Node* temp = head;
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFromFront() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
}

void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteFromPosition(int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (position == 0) {
        deleteFromFront();
        return;
    }
    struct Node* temp = head;
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds\n");
        return;
    }
    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}

void displayList() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, data, position;
    while (1) {
        printf("1. Insert at Front\n2. Insert at End\n3. Insert at Position\n4. Delete from Front\n5. Delete from End\n6. Delete from Position\n7. Display\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtFront(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &position);
                insertAtPosition(data, position);
                break;
            case 4:
                deleteFromFront();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &position);
                deleteFromPosition(position);
                break;
            case 7:
                displayList();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
