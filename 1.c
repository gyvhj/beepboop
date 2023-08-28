

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


void insertNode(struct Node** head, int value, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}


void deleteNode(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = *head;
    if (position == 1) {
        *head = temp->next;
        free(temp);
        return;
    }

    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range\n");
        return;
    }

    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}


int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void reversePrint(struct Node* head) {
    if (head == NULL) {
        return;
    }
    reversePrint(head->next);
    printf("%d ", head->data);
}


void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

int main() {
    struct Node* head = NULL;
    char choice;
    int data, position;

    do {
        printf("\nLinked List Menu:\n");
        printf("a. Insert node\n");
        printf("b. Delete node by position\n");
        printf("c. Count nodes\n");
        printf("d. Reverse print linked list\n");
        printf("e. Reverse linked list\n");
        printf("f. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                printf("Enter data and position: ");
                scanf("%d %d", &data, &position);
                insertNode(&head, data, position);
                printf("Node inserted.\n");
                break;

            case 'b':
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteNode(&head, position);
                printf("Node deleted.\n");
                break;

            case 'c':
                printf("Number of nodes: %d\n", countNodes(head));
                break;

            case 'd':
                printf("Reverse print: ");
                reversePrint(head);
                printf("\n");
                break;

            case 'e':
                reverseList(&head);
                printf("Linked list reversed.\n");
                break;

            case 'f':
            
                while (head != NULL) {
                    struct Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please choose again.\n");
        }
    } while (choice != 'f');

    return 0;
}

