// Receives three-digit number from user, then prints the number with digits reversed

#include <stdio.h>

int main(void)
{
  int d;
  
  printf("Enter a three-digit number: ");
  scanf("%d", &d);
  
  printf("The reversal is: %d%d%d\n", d % 10, (d / 10) % 10, d / 100);
  
  return 0;
}
