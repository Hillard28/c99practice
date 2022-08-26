#include <stdio.h>

int main(void)
{
  int x, y;
  
  printf("Please enter a value for x: ");
  scanf("%d", &x);
  
  y = (3 * x * x * x * x * x)
    + (2 * x * x * x * x)
    - (5 * x * x * x)
    - (x * x)
    + (7 * x)
    - 6;
  
  printf("3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6 = %d\n", y);
  
  return 0;
}
