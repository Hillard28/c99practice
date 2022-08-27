// Breaks down input ISBN

#include <stdio.h>

int main(void)
{
    int gs1, grp, pub, itm, chk;

    printf("Enter ISBN: ");
    scanf("%d -%d -%d -%d -%d", &gs1, &grp, &pub, &itm, &chk);

    printf("GS1 prefix: %d\n", gs1);
    printf("Group identifier: %d\n", grp);
    printf("Publisher code: %d\n", pub);
    printf("Item number: %d\n", itm);
    printf("Check digit: %d\n", chk);

    return 0;
}
