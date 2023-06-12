#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


int main()
{
    printf("%f %ld\n",((log10(2147483647) + 2) * 2) + 3,sizeof(char * ) * 3);
}