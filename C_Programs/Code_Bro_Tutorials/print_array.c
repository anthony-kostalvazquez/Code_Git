#include <stdio.h>

int main()
{
    double prices[] = {5.0, 10.0, 15.0, 25.0, 20.0, 30.0};

    for(int i =0; i < sizeof(prices)/sizeof(prices[0]); i++)
    {
        printf("%lf\n", prices[i]);

    }
    return 0;
}