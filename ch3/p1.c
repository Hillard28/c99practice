// Accepts the date from a user in form mm/dd/yyyy and returns in form yyyymmdd

#include <stdio.h>

int main(void)
{
  int year, month, day;
  
  printf("Enter a date: ");
  scanf("%2d/ %2d/ %4d", &month, &day, &year);
  
  printf("You entered the date: %4d%2d%2d", year, month, day);
  
  return 0;
}
