

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


struct Stack {
    int top;
    unsigned capacity;
    int* array;
};


struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}


int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int item) {
    stack->array[++stack->top] = item;
}


int pop(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return -1; 
}


int evaluatePostfix(const char* postfix) {
    struct Stack* stack = createStack(strlen(postfix));
    int i, operand1, operand2;

    for (i = 0; postfix[i]; ++i) {
        if (isdigit(postfix[i]))
            push(stack, postfix[i] - '0');
        else {
            operand2 = pop(stack);
            operand1 = pop(stack);

            switch (postfix[i]) {
                case '+':
                    push(stack, operand1 + operand2);
                    break;
                case '-':
                    push(stack, operand1 - operand2);
                    break;
                case '*':
                    push(stack, operand1 * operand2);
                    break;
                case '/':
                    push(stack, operand1 / operand2);
                    break;
            }
        }
    }

    return pop(stack);
}

int main() {
    char postfix[100];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}

