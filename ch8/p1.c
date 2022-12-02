#include <stdio.h>

int main(void) {
    int digit_seen[10] = {0};
    int repeated_digit[10] = {0};
    int repeated = 0;
    int digit;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0) {
        digit = n % 10;
        if (digit_seen[digit]) {
            repeated_digit[digit] = 1;
            repeated = 1;
        }
        digit_seen[digit] = 1;
        n /= 10;
    }

    if (repeated) {
        printf("Repeated digit(s):");
        for (int i = 0; i < 10; i++) {
            if (repeated_digit[i]) {
                printf(" %d", i);
            }
        }
        printf("\n");
    } else {
        printf("No repeated digit(s)\n");
    }
    
    return 0;
}
