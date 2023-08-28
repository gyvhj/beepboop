

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

Node* create_next(int val, Node* prev) {
    Node* nxt = (Node*)calloc(1, sizeof(Node));
    nxt->val = val;
    nxt->next = NULL;
    if (prev != NULL) {
        prev->next = nxt;
    }
    return nxt;
}

Node* create_list(char* str, int len, int idx) {
    int str_len = strlen(str) - 1;
    int divs = str_len % len == 0 ? str_len / len : (str_len / len) + 1;
    int j, num = 0;

    if (divs - idx - 1 < 0) return NULL;

    int len_last_div = (str_len % len) == 0 ? 9 : str_len % len;

    if (idx != divs - 1) {
        char* start = str + len_last_div + ((divs - 1) * len) - 1 - ((idx + 1) * len) + 1;
        for (j = 0; j < len; j++) {
            num *= 10;
            num += (int)(*(start + j) - '0');
        }
    } else {
        for (j = 0; j < len_last_div; j++) {
            num *= 10;
            num += (int)((*(str + j)) - '0');
        }
    }

    Node* head = create_next(num, NULL);
    Node* current = head;

    for (int i = 1; i < divs; i++) {
        num = 0;
        if (i != divs - 1) {
            char* start = str + len_last_div + ((divs - 1) * len) - 1 - ((i + 1) * len) + 1;
            for (j = 0; j < len; j++) {
                num *= 10;
                num += (int)(*(start + j) - '0');
            }
        } else {
            for (j = 0; j < len_last_div; j++) {
                num *= 10;
                num += (int)((*(str + j)) - '0');
            }
        }
        current = create_next(num, current);
    }

    return head;
}

void print_reverse(Node* head) {
    Node* curr = head;
    int size = 0;
    while (curr != NULL) {
        size++;
        curr = curr->next;
    }
    curr = head;
    int i, j;
    for (i = 0; i < size - 1; i++) {
        curr = curr->next;
    }
    if (curr->val != 0) {
        printf("%d", curr->val);
    }
    for (i = 0; i < size - 1; i++) {
        curr = head;
        for (j = 0; j < size - 2 - i; j++) {
            curr = curr->next;
        }
        printf("%0*d", 9, curr->val);
    }
    printf("\n");
}

void delete_list(Node* head) {
    Node* curr = head;
    Node* temp = curr;
    while (curr != NULL) {
        curr = curr->next;
        free(temp);
        temp = curr;
    }
}

Node* sum_lists(Node* a, Node* b) {
    int carry = 0, sum = 0;
    int len = 9;
    Node* result = (Node*)calloc(1, sizeof(Node));
    result->val = 0;
    result->next = NULL;
    Node* a_ptr = a, *b_ptr = b, *result_ptr = result;

    while (a_ptr != NULL && b_ptr != NULL) {
        sum = (a_ptr->val) + (b_ptr->val);
        carry = sum / (int)pow(10, len);
        sum = sum % (int)pow(10, len);

        result_ptr->val += sum;
        result_ptr = create_next(carry, result_ptr);

        a_ptr = a_ptr->next;
        b_ptr = b_ptr->next;
    }

    if (a_ptr == NULL) {
        while (b_ptr != NULL) {
            result_ptr->val += b_ptr->val;
            carry = (result_ptr->val) / (int)pow(10, len);
            result_ptr->val = (result_ptr->val) % (int)pow(10, len);
            b_ptr = b_ptr->next;
            result_ptr = create_next(carry, result_ptr);
        }
    } else if (b_ptr == NULL) {
        while (a_ptr != NULL) {
            result_ptr->val += a_ptr->val;
            carry = (result_ptr->val) / (int)pow(10, len);
            result_ptr->val = (result_ptr->val) % (int)pow(10, len);
            a_ptr = a_ptr->next;
            result_ptr = create_next(carry, result_ptr);
        }
    }

    if (result_ptr->val == 0 && result_ptr->next == NULL) {
        Node* before_last = result;
        while (before_last->next != result_ptr) {
            before_last = before_last->next;
        }
        before_last->next = NULL;
        free(result_ptr);
    }

    return result;
}

int main() {
    char p[100], q[100];
    int len = 9;

    printf("Enter the first number: ");
    fgets(p, sizeof(p), stdin);
    Node* head1 = create_list(p, len, 0);

    printf("Enter the second number: ");
    fgets(q, sizeof(q), stdin);
    Node* head2 = create_list(q, len, 0);

    Node* sum_head = sum_lists(head1, head2);

    printf("Sum: ");
    print_reverse(sum_head);

    delete_list(head1);
    delete_list(head2);
    delete_list(sum_head);

    return 0;
}

