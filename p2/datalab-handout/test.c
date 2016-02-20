#include <stdio.h>

int main()
{
int x = 20;
int y = 10;

printf("\nTwo different: %d", (x ^ y));
printf("\nTwo same: %d,", (x ^ x));
printf("\nTwo different: %d", !(x ^ y));
printf("\nTwo same: %d,", !(x ^ x));

return 0;
}
