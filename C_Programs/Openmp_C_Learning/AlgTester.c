#include <stdio.h>
#include "omp.h"

int main()
{
    int x = 0;
    int y = 0;
    #pragma omp parallel
    {
        
        int ID = omp_get_thread_num();

        printf("hello (%d)", ID);
        printf("world (%d) \n", ID);
        x++;
    }

    printf("%d", x);
}