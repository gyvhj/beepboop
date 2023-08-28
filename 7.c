

#include <stdio.h>
#include <stdlib.h>

struct QueueNode {
    int data;
    struct QueueNode* next;
};

struct LinearQueue {
    struct QueueNode *front, *rear;
};

struct QueueNode* createQueueNode(int data) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct LinearQueue* createLinearQueue() {
    struct LinearQueue* queue = (struct LinearQueue*)malloc(sizeof(struct LinearQueue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(struct LinearQueue* queue, int data) {
    struct QueueNode* newNode = createQueueNode(data);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

int dequeue(struct LinearQueue* queue) {
    if (queue->front == NULL)
        return -1;
    struct QueueNode* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    free(temp);
    if (queue->front == NULL)
        queue->rear = NULL;
    return data;
}

int size(struct LinearQueue* queue) {
    int count = 0;
    struct QueueNode* temp = queue->front;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int isEmpty(struct LinearQueue* queue) {
    return queue->front == NULL;
}

int isFull(struct LinearQueue* queue, int capacity) {
    return 0;
}

int main() {
    struct LinearQueue* arrayQueue = createLinearQueue();
    struct LinearQueue* linkedListQueue = createLinearQueue();
    
    int choice, data, capacity;
    
    printf("Enter the capacity of the queue: ");
    scanf("%d", &capacity);

    do {
        printf("\nQueue Menu:\n");
        printf("1. Enqueue (Array)\n");
        printf("2. Dequeue (Array)\n");
        printf("3. Size (Array)\n");
        printf("4. Enqueue (Linked List)\n");
        printf("5. Dequeue (Linked List)\n");
        printf("6. Size (Linked List)\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (!isFull(arrayQueue, capacity)) {
                    printf("Enter data to enqueue: ");
                    scanf("%d", &data);
                    enqueue(arrayQueue, data);
                    printf("Enqueued %d into the array queue.\n", data);
                } else {
                    printf("Array queue is full (overflow).\n");
                }
                break;

            case 2:
                if (!isEmpty(arrayQueue)) {
                    int dequeued = dequeue(arrayQueue);
                    printf("Dequeued %d from the array queue.\n", dequeued);
                } else {
                    printf("Array queue is empty (underflow).\n");
                }
                break;

            case 3:
                printf("Size of array queue: %d\n", size(arrayQueue));
                break;

            case 4:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(linkedListQueue, data);
                printf("Enqueued %d into the linked list queue.\n", data);
                break;

            case 5:
                if (!isEmpty(linkedListQueue)) {
                    int dequeued = dequeue(linkedListQueue);
                    printf("Dequeued %d from the linked list queue.\n", dequeued);
                } else {
                    printf("Linked list queue is empty (underflow).\n");
                }
                break;

            case 6:
                printf("Size of linked list queue: %d\n", size(linkedListQueue));
                break;

            case 7:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please choose again.\n");
        }
    } while (choice != 7);

    while (!isEmpty(arrayQueue)) {
        dequeue(arrayQueue);
    }
    free(arrayQueue);

    while (!isEmpty(linkedListQueue)) {
        dequeue(linkedListQueue);
    }
    free(linkedListQueue);

    return 0;
}

