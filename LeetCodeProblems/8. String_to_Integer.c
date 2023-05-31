#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//takes a char and returns the integer it represents or retuns -2
int Return_Int_From_Single_Char(char s)
{
    switch (s)
    {
    case '0':
        return(0);
        break;
    case '1':
        return(1);
        break;
    case '2':
        return(2);
        break;
    case '3':
        return(3);
        break;
    case '4':
        return(4);
        break;
    case '5':
        return(5);
        break;
    case '6':
        return(6);
        break;
    case '7':
        return(7);
        break;
    case '8':
        return(8);
        break;
    case '9':
        return(9);
        break;
    default:
        return(-1);
        break;
    }
}

int myAtoi(char * s)
{
    //initialize
    int neg_modifier = 1;
    int OutputInt = 0;
    int CurrentInt = 0;
    bool OnlySpaceBool = true;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if(s[i] != ' ' && Return_Int_From_Single_Char(s[i]) == -1)
        {
            OnlySpaceBool = false;
        }
        
        //will enter this statement if the char is -,1,2,3,4,5,6,7,8,9,0
        if((s[i] == '+' || s[i] == '-' || ((Return_Int_From_Single_Char(s[i]) != -1) && OnlySpaceBool)))
        {
            if(s[i] == '-')
            {
                neg_modifier = -1;
                i++;
            }
            else if(s[i] == '+')
            {
                i++;
            }


            while(Return_Int_From_Single_Char(s[i]) != -1)
            {
                if((OutputInt > 214748364 || (OutputInt == 214748364 && Return_Int_From_Single_Char(s[i]) > 7)))
                {
                    if(neg_modifier == -1)
                    {
                        return(2147483648 * neg_modifier);
                    }
                    else
                    {
                        return(2147483647);
                    }
                }
                
                CurrentInt = Return_Int_From_Single_Char(s[i]);

                printf("%d \n", CurrentInt);
                OutputInt = (OutputInt*10) + CurrentInt;
                i++;
            }
            return(OutputInt * neg_modifier);
        }

    }
    


    return(0);
}

int main()
{
    char input_string[1000] = " 0000001234";
    
    printf("%d \n", myAtoi(input_string));
    
    return 0; 
}

