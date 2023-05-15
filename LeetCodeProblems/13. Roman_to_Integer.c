#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//takes a single roman numeral and returns its integer value
int Return_Int_From_Single_Char(char s)
{
    switch (s)
    {
    case 'I':
        return(1);
        break;
    case 'V':
        return(5);
        break;
    case 'X':
        return(10);
        break;
    case 'L':
        return(50);
        break;
    case 'C':
        return(100);
        break;
    case 'D':
        return(500);
        break;
    case 'M':
        return(1000);
        break;
    default:
        printf("ERROR Invalid Input\n");
        break;
    }
    return 0;
}


int romanToInt(char * s)
{
    int output = 0;

    int previous_int = Return_Int_From_Single_Char(*(s));

    for (char current_char = *s; current_char; current_char =*++s)
    {
        int current_int = Return_Int_From_Single_Char(current_char);
        //printf("previous int = %d current int = %d\n", previous_int, current_int);
        if(current_int <= previous_int)
        {
            output += current_int;
        }
        else
        {
            output += current_int - 2 * previous_int;
        }
        //printf("%c = %d \n", *(s + i), Return_Int_From_Single_Char(*(s + i)));
        previous_int = current_int;
    }

    return(output);
}


int main()
{
    char *inputptr;
    inputptr = "MCMXCIV";

    printf("%d",romanToInt(inputptr));

    return(0);
}