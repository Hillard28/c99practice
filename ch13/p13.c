#include <stdio.h>

#define MAX_SIZE 80

void encrypt(char *message, int shift) {
    int i;

    for (i = 0; message[i]; i++) {
        if ('a' <= message[i] && message[i] <= 'z') {
            message[i] = ((message[i] - 'a') + shift) % 26 + 'a';
        }
        else if ('A' <= message[i] && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A') + shift) % 26 + 'A';
        }
    }
}

int main(void) {
    char message[MAX_SIZE + 1], c;
    int shift, j;
    int i = 0;

    printf("Enter message to be encrypted: ");
    while ((c = getchar()) != '\n' && i < MAX_SIZE) {
        message[i++] = c;
    }
    message[i] = '\0';
    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);
    encrypt(message, shift);
    printf("Encrypted message: %s\n", message);

    return 0;
}
