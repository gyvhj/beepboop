

#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


struct Node* buildCircularLinkedList(int n) {
    struct Node* head = createNode(1);
    struct Node* current = head;

    for (int i = 2; i <= n; i++) {
        current->next = createNode(i);
        current = current->next;
    }

    current->next = head; // Make it circular
    return head;
}


void josephus(struct Node** head, int k) {
    struct Node* current = *head;
    struct Node* prev = NULL;

 
    while (current->next != current) {
        for (int i = 1; i < k; i++) {
            prev = current;
            current = current->next;
        }
        
        prev->next = current->next; // Eliminate the current person
        free(current);
        current = prev->next;
    }

    *head = current; // The last person standing
}

int main() {
    int n, k;
    printf("Enter the number of people: ");
    scanf("%d", &n);
    printf("Enter the value of k: ");
    scanf("%d", &k);

    if (n <= 0 || k <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    struct Node* head = buildCircularLinkedList(n);
    josephus(&head, k);

    printf("The person in position %d survives.\n", head->data);

    
    struct Node* temp = head->next;
    while (temp != head) {
        struct Node* toFree = temp;
        temp = temp->next;
        free(toFree);
    }
    free(head);

    return 0;
}

