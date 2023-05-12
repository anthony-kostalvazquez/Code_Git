#include <stdio.h>
#include <math.h>


int main(){
    const double PI = acos(-1); //This gets a value for pi to many decimal points
    double radius;
    double circumference;
    double area;

    printf("\nEnter the radius of a circle: ");
    scanf("%lf", &radius);

    circumference = 2 * PI * radius;
    area = PI * pow(radius, 2);

    printf("\nRadius: %lf \n", radius);
    printf("Circumference: %lf \n", circumference);
    printf("Area: %lf", area);
}