// Display input phone number

#include <stdio.h>

int main(void)
{
    int area, off, sub;

    printf("Enter a phone number [(xxx) xxx-xxxx]:");
    scanf("(%3d) %3d -%4d", &area, &off, &sub);

    printf("You entered: %3d.%3d.%4d\n", area, off, sub);

    return 0;
}
