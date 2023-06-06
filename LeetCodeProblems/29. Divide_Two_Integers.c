#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int divide(int dividend, int divisor)
{
    //initialize some variables
    int WholeParts = 0;
    int tmp = 0;
    int d = dividend;
    int div = divisor;
    int mul = 0;


    //set the variables to be negative (so they will always fit into the int type)
    if(d > 0)
    {
        d = d * (-1);
    }
    if(div > 0)
    {
        div = div * -1;
    }


    //log(n) 
    while(d <= div)
    {
        tmp = div;
        mul = 1;
        while(d<=tmp)
            d = d - tmp;
            WholeParts = WholeParts - mul;
            mul = mul + mul;
            tmp = tmp + tmp;
    }

    //takes care of the case where the answer is 2147483648 (But this doesnt fit into the int type)
    if(WholeParts == -2147483648 && !(dividend > 0 ^ divisor > 0))
    {
        return(2147483647);
    }

    //flips the results sign if its +/- or -/+
    if( !(dividend > 0 ^ divisor > 0))
    {
        WholeParts = WholeParts * -1;
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