#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "../AnthonysCLib/Arrays.h"



int main()
{
    //initializes rand seed depending on the time
    srand(time(NULL));

    //hardcoded sizes dependent on the assignment
    int E_size = 100;
    int S_size = (rand() % (1000000 - 1000) + 1000);

    //You will generate 99 distinct random numbers between 0 and 5000 and store -them in an array of size 100. Add 5001 as the 100th cell in the array.
    int *ElementsArray;
    int *SearchArray;

    ElementsArray = InitRandIntArray(E_size, 5000, true);

    PrintIntArray(ElementsArray, E_size, 2);










    return 0;
}