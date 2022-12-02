#include <stdio.h>
#include <ctype.h>

int main(void) {
    char message[100] = {0};
    int i = 0;
    int j;
    char c;

    printf("Enter message: ");
    while ((c = getchar()) != '\n' && i < 100) {
        message[i++] = c;
    }

    printf("In B1FF-speak: ");
    for (j = 0; j < i; j++) {
        switch (c = toupper(message[j])) {
            case 'A':
                putchar('4');
                break;
            case 'B':
                putchar('8');
                break;
            case 'E':
                putchar('3');
                break;
            case 'I':
                putchar('1');
                break;
            case 'O':
                putchar('0');
                break;
            case 'S':
                putchar('5');
                break;
            default:
                putchar(c);
                break;
        }
    }
    printf("!!!!!!!!!!\n");

    return 0;
}
