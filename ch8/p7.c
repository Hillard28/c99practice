#include <stdio.h>

int main(void) {
    int matrix[25];
    int total, i, j;

    for (i = 0; i < 5; i++) {
        printf("Enter row %d: ", i + 1);
        for (j = 0; j < 5; j++) {
            scanf("%d", &matrix[5*i + j]);
        }
    }

    printf("Row totals:");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            total += matrix[5*i + j];
        }
        printf(" %d", total);
        total = 0;
    }
    printf("\n");

    printf("Column totals:");
    for (j = 0; j < 5; j++) {
        for (i = 0; i < 5; i++) {
            total += matrix[5*i + j];
        }
        printf(" %d", total);
        total = 0;
    }
    printf("\n");

    return 0;
}
