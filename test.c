#include <stdio.h>

main()
{
char in = '0';
while(1)
{
scanf("%c", &in);
if(in == 'q')
    break;
printf("We read in: %c",in);
}
printf("We broke from the loop");
}
