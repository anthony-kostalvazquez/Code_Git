#include <stdio.h>
#include <stdbool.h>


long int reverse(long int x)
{
    //if x is negative this will multiply it by -1 to turn it positive, then at the end multiply the result by -1 to account for the negative case
    int neg_modifier = 1;
    if(x < 0)
    {
        neg_modifier = -1;
        x = x * neg_modifier;
    }

    
    long int output = 0;
    while(x > 0)
    {
        if((output > 214748364))
        {
            return(0);
        }

        output = (output*10) + (x % 10);
        x = x/10;
    }

    return(output * neg_modifier);
}


int main()
{
    long int input;

    //gets user input
    while(true)
    {
        printf("Type a ulong to reverse: \n");
        scanf("%ld", &input);
        printf("you inputed : %ld\n", input);

        printf("the reverse fuction outputted: %ld\n", reverse(input));
    }



    return 0;
}