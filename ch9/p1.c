#include <stdio.h>

#define SIZE 100

void selection_sort(int matrix[], int size) {
    int large, i;
    int holder = 0;

    if (size == 0) {
        return;
    }
    for (i = 0; i < size; i++) {
        if (matrix[i] > holder) {
            large = i;
            holder = matrix[i];
        }
    }
    matrix[large] = matrix[size - 1];
    matrix[size - 1] = holder;

    selection_sort(matrix, size - 1);
}

int main(void) {
    int matrix[SIZE], size, i, c;
    size = 0; i = 0;

    printf("Enter a series of integers: ");
    for (size = 0; size < SIZE; size++) {
        scanf(" %d", &matrix[size]);
        if ((c = getchar()) == '\n') {
            ++size;
            break;
        }
        ungetc(c, stdin);
    }
    
    selection_sort(matrix, size);

    printf("Sorted integers:");
    
    for (i = 0; i < size; i++) {
        printf(" %d", matrix[i]);
    }
    printf("\n");

    return 0;
}
