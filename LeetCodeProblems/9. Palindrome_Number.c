#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool isPalindrome(int x)
{
    int input = x;
    long int reverse = 0;

    //to check the negative special case
    if (x < 0)
    {
        return(false);
    }
    
    while (input > 0)
    {
        // gets the last digit and sets it to mod
        int mod = input % 10;
        reverse = reverse*10 + mod;

        input = input / 10;

    }
    return(x == reverse);
}


int main()
{
    int Input = -123;

    printf("%d", isPalindrome(Input));

    return(0);
}