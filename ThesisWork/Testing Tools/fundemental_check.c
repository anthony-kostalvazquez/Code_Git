#include <stdio.h>




int fundemental_check(int a)
{

    unsigned long int j = 0;

    //printf("a is = %d \n", a);

    for(unsigned long int i = 3; j < a; i += 2)
    {
        j = i * i;
        //printf("this is j %ld\n", j);

        if(a % j == 0)
        {
            //its divisable by an odd square and thus not fundamental
            //printf("Deemed not fund when j = %ld \n", j);
            return 0;
        }

    }

    return 1;
}

int main(int argc, char * argv[])
{
    int current = 7;

    for(int i = 0; i < 100; i++)
    {

        if(fundemental_check(current) == 1)
        {
            printf("%d is fundemental\n", current);
        }

        current += 24;

    }
    return 0;

}