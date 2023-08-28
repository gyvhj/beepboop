nclude <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100


struct StackNode {
    char data;
    struct StackNode* next;
};


struct PostfixExpression {
    char expression[MAX_SIZE];
    int length;
};


struct StackNode* createStackNode(char data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void push(struct StackNode** top, char data) {
    struct StackNode* newNode = createStackNode(data);
    newNode->next = *top;
    *top = newNode;
}


char pop(struct StackNode** top) {
    if (*top == NULL) {
        printf("Stack underflow!\n");
        exit(EXIT_FAILURE);
    }

    char data = (*top)->data;
    struct StackNode* temp = *top;
    *top = (*top)->next;
    free(temp);
    return data;
}


int getPrecedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}


void infixToPostfix(char* infix, struct PostfixExpression* postfix) {
    struct StackNode* stack = NULL;
    postfix->length = 0;
int i;
    for (i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            postfix->expression[postfix->length++] = infix[i];
        } else if (infix[i] == '(') {
            push(&stack, infix[i]);
        } else if (infix[i] == ')') {
            while (stack != NULL && stack->data != '(') {
                postfix->expression[postfix->length++] = pop(&stack);
            }
            if (stack != NULL && stack->data == '(') {
                pop(&stack); // Pop the '('
            }
        } else {
            while (stack != NULL && getPrecedence(stack->data) >= getPrecedence(infix[i])) {
                postfix->expression[postfix->length++] = pop(&stack);
            }
            push(&stack, infix[i]);
        }
    }

    while (stack != NULL) {
        postfix->expression[postfix->length++] = pop(&stack);
    }

    postfix->expression[postfix->length] = '\0';
}

int main() {
    char infix[MAX_SIZE];
    struct PostfixExpression postfix;

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, &postfix);

    printf("Postfix expression: %s\n", postfix.expression);

    return 0;
}


