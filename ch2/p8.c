// Calculates the remaining balance of a loan after the first three periods

#include <stdio.h>

int main(void)
{
    float loan, irate, pay;

    printf("Enter amount of loan: ");
    scanf("%f", &loan);
    printf("Enter interest rate: ");
    scanf("%f", &irate);
    printf("Enter monthly payment: ");
    scanf("%f", &pay);

    loan = (loan * (1 + irate / (100 * 12))) - pay;
    printf("Balance remaining after first payment: %.2f\n", loan);
    loan = (loan * (1 + irate / (100 * 12))) - pay;
    printf("Balance remaining after second payment: %.2f\n", loan);
    loan = (loan * (1 + irate / (100 * 12))) - pay;
    printf("Balance remaining after third payment: %.2f\n", loan);

    return 0;
}
