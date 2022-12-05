#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 128

int operands[STACK_SIZE];
int len = 0;

void make_empty(void) {
    len = 0;
}

int is_empty(void) {
    if (len == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int is_full(void) {
    if (len == STACK_SIZE) {
        return 1;
    }
    else {
        return 0;
    }
}

void stack_overflow(void) {
    printf("\nExpression is too complex\n");
    exit(EXIT_FAILURE);
}

void stack_underflow(void) {
    printf("\nNot enough operands in expression\n");
    exit(EXIT_FAILURE);
}

void push(int i) {
    if (is_full()) {
        stack_overflow();
    }
    else {
        operands[len++] = i;
    }
}

int pop(void) {
    if (is_empty()) {
        stack_underflow();
    }
    else {
        return operands[--len];
    }
}

int main(void) {
    int op1, op2;
    char input;

    printf("Enter an RPN expression: ");
    for (;;) {
        scanf(" %c", &input);
        if ('0' <= input && input <= '9') {
            push(input - '0');
        }
        else {
            switch (input) {
                case '+':
                    push(pop() + pop());
                    break;
                case '-':
                    op2 = pop();
                    op1 = pop();
                    push(op1 - op2);
                    break;
                case '*':
                    push(pop() * pop());
                    break;
                case '/':
                    op2 = pop();
                    op1 = pop();
                    push(op1 / op2);
                    break;
                case '=':
                    if (len == 1) {
                        printf("Value of expression: %d\n", pop());
                        exit(EXIT_SUCCESS);
                    }
                    else {
                        printf("\nNot enough operators in expression\n");
                        exit(EXIT_FAILURE);
                    }
                case ' ':
                    break;
                default:
                    exit(EXIT_FAILURE);
            }
        }
    }
    
    return 0;
}
