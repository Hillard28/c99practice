#include <stdio.h>

int power(int x, int pow) {
    int result = x;

    if (pow == 0) {
        return 1;
    }
    else if (pow % 2 == 0) {
        result = power(x, pow / 2);
        return result * result;
    }
    else {
        return x * power(x, pow - 1);
    }
}

int main(void) {
    int x, p;

    printf("Input a value for x: ");
    scanf("%d", &x);
    printf("Input a power for x to be raised to: ");
    scanf("%d", &p);
    printf("Value: %d", power(x, p));
    
    return 0;
}
