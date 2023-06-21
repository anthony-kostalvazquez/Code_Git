#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>

double myPow(double x, int n)
{
    int power = n;

    if(n < 0)
    {
        x = 1/x;
        power = -power;
    }

    double result = 1;
    double tmp = x;

    while(abs(power) > 0)
    {
        printf("result = %lf, tmp = %lf, power = %d\n", result, tmp, power);
        if(power % 2 == 1)//the power is odd
        {
            result = result * tmp;
            power--;
        }
        else//the power is even
        {
            tmp = tmp * tmp;
            power = power / 2;
        }
    }

    printf("result = %lf, tmp = %lf, power = %d\n", result, tmp, power);
    return(result);   
}

int main()
{
    printf("result is %lf", myPow(2,2));

    return 0;
}