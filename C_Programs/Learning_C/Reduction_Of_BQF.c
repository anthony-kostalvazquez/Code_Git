#include <stdio.h>

int main()
{
    //initialization
    int Input_Poly[3];
    char text_array[] = {'a', 'b', 'c'};

    //input loop
    printf("Please Input Your Quadratic Form ax^2 + bxy + cy^2 one variable at a time\n");
    for(int i = 0; i < 3; i++)
    {
        printf("Please input your %c value \n", text_array[i]);
        scanf("%d", &Input_Poly[i]);
    }
    printf("Your input is %dx^2 + %dxy + %dy^2\n", Input_Poly[0], Input_Poly[1], Input_Poly[2]);

    //Replacement loop
    while ((Input_Poly[0] > Input_Poly[1]) OR (Input_Poly[1] > Input_Poly[0]) OR (Input_Poly[1] <= -Input_Poly[0]))
    {
        
    }
    



    return 0;
}