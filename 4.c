

#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}


void push(struct Node** top, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = *top;
    *top = newNode;
    printf("Pushed %d onto the stack.\n", value);
}


int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }

    struct Node* temp = *top;
    int value = temp->data;
    *top = temp->next;
    free(temp);
    return value;
}


void peek(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Top element: %d\n", top->data);
}


void display(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements:\n");
    while (top != NULL) {
        printf("%d\n", top->data);
        top = top->next;
    }
}

int main() {
    struct Node* top = NULL;
    char choice;
    int value;

    do {
        printf("\nStack Menu:\n");
        printf("a. Push\n");
        printf("b. Pop\n");
        printf("c. Peek\n");
        printf("d. Display\n");
        printf("e. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&top, value);
                break;

            case 'b':
                value = pop(&top);
                if (value != -1) {
                    printf("Popped %d from the stack.\n", value);
                }
                break;

            case 'c':
                peek(top);
                break;

            case 'd':
                display(top);
                break;

            case 'e':
                
                while (top != NULL) {
                    struct Node* temp = top;
                    top = top->next;
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

