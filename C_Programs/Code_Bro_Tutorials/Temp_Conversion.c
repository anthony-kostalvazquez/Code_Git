#include <stdio.h>
#include <ctype.h>

int main(){

    char unit;
    float temp;
    float converted_temp;

    printf("\nIs your tempature in C or F: ");
    scanf("%c",&unit);

    printf("Enter the temp: ");
    scanf("%f", &temp);


    unit = toupper(unit);

    if(unit == 'C'){
        converted_temp = (temp * 9/5) + 32;
        printf("%.1f degrees celsius is equal to %.1f degrees fahrenheit \n",temp ,converted_temp);
    }
    else if(unit =='F'){
        converted_temp = ((temp - 32) * 5) / 9;
        printf("%.1f degrees fahrenheit is equal to %.1f degrees celcius \n",temp ,converted_temp);
    }
    else{
        printf("\n %c is not a valid unit of measurement", unit);

    }


}