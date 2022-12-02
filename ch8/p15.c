#include <stdio.h>

int main(void) {
    char message[80];
    int i = 0;
    int shift, j;
    char c;

    printf("Enter message to be encrypted: ");
    while ((c = getchar()) != '\n' && i < 80) {
        message[i++] = c;
    }
    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);
    printf("Encrypted message: ");
    for (j = 0; j < i; j++) {
        if ('a' <= message[j] && message[j] <= 'z') {
            c = ((message[j] - 'a') + shift) % 26 + 'a';
        }
        else if ('A' <= message[j] && message[j] <= 'Z') {
            c = ((message[j] - 'A') + shift) % 26 + 'A';
        }
        else {
            c = message[j];
        }
        putchar(c);
    }
    printf("\n");

    return 0;
}
