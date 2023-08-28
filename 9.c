

#include <stdio.h>
#include <stdlib.h>

struct StackNode {
    int data;
    struct StackNode* next;
};

struct Stack {
    struct StackNode* top;
};

struct StackNode* createStackNode(int data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

void push(struct Stack* stack, int data) {
    struct StackNode* newNode = createStackNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(struct Stack* stack) {
    if (stack->top == NULL)
        return -1;
    struct StackNode* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

struct Queue {
    struct Stack* stack1;
    struct Stack* stack2;
};

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->stack1 = createStack();
    queue->stack2 = createStack();
    return queue;
}

void enqueue(struct Queue* queue, int data) {
    push(queue->stack1, data);
}

int dequeue(struct Queue* queue) {
    if (queue->stack1->top == NULL && queue->stack2->top == NULL)
        return -1;
    
    if (queue->stack2->top == NULL) {
        while (queue->stack1->top != NULL) {
            int data = pop(queue->stack1);
            push(queue->stack2, data);
        }
    }
    
    return pop(queue->stack2);
}

int main() {
    struct Queue* queue = createQueue();
    int choice, data;
    
    do {
        printf("\nQueue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(queue, data);
                printf("Enqueued %d into the queue.\n", data);
                break;

            case 2:
                data = dequeue(queue);
                if (data != -1) {
                    printf("Dequeued %d from the queue.\n", data);
                } else {
                    printf("Queue is empty.\n");
                }
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please choose again.\n");
        }
    } while (choice != 3);

    free(queue->stack1);
    free(queue->stack2);
    free(queue);

    return 0;
}

