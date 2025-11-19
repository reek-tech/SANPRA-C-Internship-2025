#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list

struct Node {
    int data;
    struct Node *next;
};

// Insert a node at the head of the list

struct Node* insertHead(struct Node *head, int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

// Delete the first node containing the given value

struct Node* deleteByValue(struct Node *head, int value) {
    if (head == NULL)
        return head;

    // If head node is to be deleted

    if (head->data == value) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node *curr = head;
    // Find node before the one to delete

    while (curr->next && curr->next->data != value)
        curr = curr->next;

    if (curr->next) {
        struct Node *temp = curr->next;
        curr->next = curr->next->next;
        free(temp);
    }

    return head;
}

// Print all nodes in the list

void printList(struct Node *head) {
    printf("List: ");
    while (head) {
        printf("%d → ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;  // start with empty list
    int choice, value;

    while (1) {
        printf("\n1. Insert at Head\n2. Delete by Value\n3. Print List\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                head = insertHead(head, value);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                head = deleteByValue(head, value);
                break;

            case 3:
                printList(head);
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
