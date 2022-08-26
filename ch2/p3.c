#include <stdio.h>

int main(void)
{
  float pi = 3.14159f, r, v;
  printf("Please enter the radius of the sphere: ");
  scanf("%f", &r);
  printf("The volume of a sphere of radius %.1fm is: %.2f", 4.0f/3.0f * pi * r * r * r);
  
  return 0;
}
