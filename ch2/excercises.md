1) Create and run K&R's famous "Hello, world!" program:
```
#include <stdio.h>

int main(void)
{
  printf("Hello, world!\n");
}
```
Do you get a warning message?  What's needed to make it go away?

A) The program does not return a status code upon completion.  `return 0;` should be added before the close bracket.
