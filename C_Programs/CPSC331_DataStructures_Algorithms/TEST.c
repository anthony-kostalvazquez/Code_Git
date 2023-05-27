#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>




int main()
{
    for (int i = 0; i <= 1; i++)
    {
        for (int j = 1; j >= 0 ; j--)
        {
            printf("(%d, %d)", i-j, j+i-1);
        }
        
    }
    


    return 0;
}