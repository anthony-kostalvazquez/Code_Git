#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



double new21Game(int n, int k, int maxPts)
{
    


}



int main()
{
    int n = 0;
    int k = 0;
    int maxPts = 0;
    //gets user input

    while(true)
    {
        printf("Type the n value: \n");
        scanf("%d", &n);
        printf("Type the k value: \n");
        scanf("%d", &k);
        printf("Type the maxPts value: \n");
        scanf("%d", &maxPts);

        printf("INPUT: n = %d k = %d maxPts = %d\n", n,k,maxPts);
        printf("OUTPUT: %f\n", new21Game(n, k, maxPts));
    }




    return 0;
}