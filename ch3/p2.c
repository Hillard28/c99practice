// Formats input product information

#include <stdio.h>

int main(void)
{
    int item_no, year, month, day;
    float unit_prc;

    printf("Enter item number: ");
    scanf("%d", &item_no);

    printf("Enter item number: ");
    scanf("%f", &unit_prc);
    
    printf("Enter purchase date: ");
    scanf("%2d/ %2d/ %4d", &month, &day, &year);

    printf("Item\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n");
    printf("%d\t\t$%7.2f\t%2d/%2d/%4d\n", item_no, unit_prc, month, day, year);

    return 0;
}
