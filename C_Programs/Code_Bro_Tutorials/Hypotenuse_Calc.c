#include <stdio.h>
#include <math.h>

int main(){
    //stating variables
    double side_1;
    double side_2;
    double hypotenuse;

    //printing a nice statement so people know what the code does
    printf("\nHello, given 2 sides of a right angle triangle i can calculate the hypotenuse\n");

    //grabbing input
    printf("Side 1: ");
    scanf("%lf", & side_1);
    printf("Side 2: ");
    scanf("%lf", & side_2);

    //calculations
    hypotenuse = sqrt(pow(side_1,2)+pow(side_2,2));

    //printing output
    printf("hypotenuse: %lf \n", hypotenuse );

}