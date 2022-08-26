#include <stdio.h>

int main(void)
{
  float pretax, tax;
  
  printf("Enter an amount: ");
  scanf("%f", &pretax);
  
  tax = 1.05 * pretax;
  
  printf("A pretax amount of %.2f with tax added: %.2f", pretax, tax);
  
  return 0;
}
