#include <stdio.h>

int power(int x, int pow) {
    int result = x;

    if (pow == 0) {
        result = 1;
    }
    else {
        for (int i = 1; i < pow; i++) {
            result *= x;
        }
    }
    return result;
}

int main(void) {
    int x, value;
    int pow = 5;

    printf("Input a value for x: ");
    scanf("%d", &x);
    printf("Value: %d", 3*power(x, 5) + 2*power(x, 4) - 5*power(x, 3) - power(x,2) + 7*x - 6);
    
    return 0;
}
