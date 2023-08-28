

#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};


struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}


void insertNode(struct Node** head, int value, int position) {
    struct Node* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    if (position == 1) {
        newNode->next = *head;
        (*head)->prev = newNode;
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

    newNode->prev = temp;
    newNode->next = temp->next;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

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
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }

    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
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


void reversePrint(struct Node* tail) {
    struct Node* temp = tail;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
}

int main() {
    struct Node* head = NULL;
    char choice;
    int data, position;

    do {
        printf("\nDoubly Linked List Menu:\n");
        printf("a. Insert node\n");
        printf("b. Delete node by position\n");
        printf("c. Count nodes\n");
        printf("d. Reverse print linked list\n");
        printf("e. Exit\n");
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
    } while (choice != 'e');

    return 0;
}

