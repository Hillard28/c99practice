#include <stdio.h>
#include <string.h>

#define MAX_SIZE 20

int read_word(char *str, int n) {
    int ch, i = 0;

    while ((ch = getchar()) != '\n' && i < n) {
        if (i < n) {
            str[i++] = ch;
        }
    }
    str[i] = '\0';
    
    return i;
}

int main(void) {
    char input[MAX_SIZE+1], smallest[MAX_SIZE+1], largest[MAX_SIZE+1];
    int i;
    
    for (i = 0;;i++) {
        printf("Enter word: ");
        if (read_word(input, MAX_SIZE) == 4) {
            break;
        }
        if (i == 0) {
            strcpy(smallest, input);
            strcpy(largest, input);
        }
        if (strcmp(input, smallest) < 0) {
            strcpy(smallest, input);
        }
        else if (strcmp(input, largest) > 0) {
            strcpy(largest, input);
        }
    }
    printf("\nSmallest word: %s\n", smallest);
    printf("Largest word: %s\n", largest);

    return 0;
}
