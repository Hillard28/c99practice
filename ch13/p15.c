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

int evaluate_RPN_expression(const char *expression) {
    int op1, op2, i;

    for (i = 0; expression[i]; i++) {
        if ('0' <= expression[i] && expression[i] <= '9') {
            push(expression[i] - '0');
        }
        else {
            switch (expression[i]) {
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
                        return pop();
                    }
                    else {
                        printf("\nNot enough operators in expression\n");
                        exit(EXIT_FAILURE);
                    }
                case ' ':
                    break;
                default:
                    printf("\nInvalid input\n");
                    exit(EXIT_FAILURE);
            }
        }
    }
    exit(EXIT_FAILURE);
}

int main(void) {
    char input[STACK_SIZE + 1], ch;
    int i;

    i = 0;
    printf("Enter an RPN expression: ");
    while ((ch = getchar()) != '\n' && i < STACK_SIZE) {
        input[i++] = ch;
    }
    input[i++] = '\0';

    printf("Value of expression: %d\n", evaluate_RPN_expression(input));
    
    return 0;
}
