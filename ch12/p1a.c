#include <stdio.h>

#define MAX_SIZE 100

int main(void) {
    char array[MAX_SIZE], ch;
    int i;
    
    i = 0;

    printf("Enter a message: ");
    for (i = 0; i < MAX_SIZE; i++) {
        ch = getchar();
        if (ch == '\n') {
            break;
        }
        else {
            array[i] = ch;
        }
    }

    printf("Reversal is: ");
    while (i > 0) {
        printf("%c", array[--i]);
    }

    return 0;
}
