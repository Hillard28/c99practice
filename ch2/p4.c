#include <stdio.h>

int main(void)
{
  float pretax;
  
  printf("Enter an amount: ");
  scanf("%f", &pretax);  
  printf("A pretax amount of %.2f with tax added: %.2f", pretax, pretax * 1.05f);
  
  return 0;
}
