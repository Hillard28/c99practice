#include <stdio.h>

int main(void) {
    int digit_seen[10] = {0};
    int digit;
    long input, n;

    do {
        printf("Enter a number: ");
        scanf("%ld", &input);
        n = input;
        while (n > 0) {
            digit = n % 10;
            digit_seen[digit] += 1;
            n /= 10;
        }

        printf("Digit:\t\t 0 1 2 3 4 5 6 7 8 9\n");
        printf("Occurrences:\t");
        for (int i = 0; i < 10; i++) {
            printf(" %d", digit_seen[i]);
            digit_seen[i] = 0;
        }
        printf("\n");
    } while (input > 0);
    
    return 0;
}
