#include <stdio.h>

int main(void)
{
  int d_total, d_20, d_10, d_5, d_1;
  printf("Enter a dollar amount: ");
  scanf("%d", &d_total);
  
  d_20 = (d_total + 19) / 20;
  d_total -= d_20 * 20;
  
  d_10 = (d_total + 9) / 10;
  d_total -= d_20 * 10;
  
  d_5 = (d_total + 4) / 5;
  d_total -= d_5 * 5;
  
  d_1 = d_total;
  
  printf("$20 bills: %d\n", d_20);
  printf("$10 bills: %d\n", d_10);
  printf("$5 bills: %d\n", d_5);
  printf("$1 bills: %d\n", d_1);
  
  return 0;
}
