

#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, char item) {
    stack->array[++stack->top] = item;
}

char pop(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

void infixToPostfix(const char* infix) {
    struct Stack* stack = createStack(strlen(infix) + 1);
    int i, j = 0;
    char postfix[100];

    for (i = 0; infix[i]; ++i) {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
            postfix[j++] = infix[i];
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^') {
            while (!isEmpty(stack) && precedence(infix[i]) <= precedence(stack->array[stack->top]))
                postfix[j++] = pop(stack);
            push(stack, infix[i]);
        } else if (infix[i] == '(')
            push(stack, infix[i]);
        else if (infix[i] == ')') {
            while (!isEmpty(stack) && stack->array[stack->top] != '(')
                postfix[j++] = pop(stack);
            if (!isEmpty(stack) && stack->array[stack->top] != '(')
                return;
            else
                pop(stack);
        }
    }

    while (!isEmpty(stack))
        postfix[j++] = pop(stack);

    postfix[j] = '\0';
    printf("Postfix expression: %s\n", postfix);
}

int main() {
    char infix[100];
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);

    return 0;
}

