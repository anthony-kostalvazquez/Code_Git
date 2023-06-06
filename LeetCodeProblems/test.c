#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int divide(int dividend, int divisor)
{
    //initialize some variables
    long int tmp = 0;
    long int WholeParts = 0;
    long int mul = 0;

    long int d = dividend;
    long int div = divisor;
    if(d < 0)
    {
        d = d * (-1);
    }
    if(div < 0)
    {
        div = div * (-1);
    }

    //log(n) 
    while(d >= div)
    {
        tmp = div;
        mul = 1;
        printf("---InnerLoop---\ntmp = %ld mul = %ld d = %ld div = %ld\n", tmp, mul, d, div);
        while(d >= tmp)
        {
            d = d - tmp;
            WholeParts += mul;
            mul += mul;
            tmp += tmp;
            printf("---OutterLoop---\ntmp = %ld mul = %ld d = %ld div = %ld\n", tmp, mul, d, div);
        }
    }

    //flips the results sign if its +/- or -/+
    if((dividend > 0 ^ divisor > 0))
    {
        WholeParts = WholeParts * -1;
    }

    if(WholeParts > 2147483647)
    {
        return(2147483647);
    }

    return(WholeParts);
}

int main()
{
    int dividend = 20;
    int divisor = 3;

    printf("%d / %d = %d\n", dividend, divisor, divide(dividend, divisor));

    return 0;
}