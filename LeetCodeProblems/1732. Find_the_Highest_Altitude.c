#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int largestAltitude(int* gain, int gainSize)
{
    int current_total_alt = 0;
    int record_alt = 0;

    for (int i = 0; i < gainSize; i++)
    {
        current_total_alt += gain[i];
        printf("i = %d, alt = %d\n", i, current_total_alt);
        if (current_total_alt > record_alt)
        {
            record_alt = current_total_alt;
        }
        
    }
    

    return record_alt;
}



int main()
{
    int input[5] = {-5,1,5,0,-7};


    printf("the highest alt = %d", largestAltitude(input, 5));




    return 0;
}