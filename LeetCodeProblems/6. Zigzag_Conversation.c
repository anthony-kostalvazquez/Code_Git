#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>



char * convert(char * s, int numRows)
{
    char *ReturnString = malloc(sizeof(char) * (strlen(s)));
    int JumpLength = (2 * numRows) - 2;
    
    printf("%ld \n", sizeof(char) * (strlen(s) + 1));

    int PositionInReturnString = 0;

    for(int i = 0; i < numRows; i++)
    {
        if(i ==0 || i == numRows-1)
        {
            for(int j = 0; i + JumpLength*j < strlen(s); j++)
            {
                ReturnString[PositionInReturnString] = s[i + JumpLength*j];
                printf("%d %c %d %d\n",i + JumpLength*j, s[i + JumpLength*j], i + JumpLength*j, PositionInReturnString);
                PositionInReturnString++;
            }
        }
        else
        {
            for(int j = 0; (i + JumpLength*j < strlen(s)) || ((-i + JumpLength) + JumpLength*j < strlen(s)) ; j++)
            {
                if(i + JumpLength*j < strlen(s))
                {
                    ReturnString[PositionInReturnString] = s[i + JumpLength*j];
                    PositionInReturnString++;
                    printf("%d %c %d %d\n",i + JumpLength*j, s[i + JumpLength*j], i + JumpLength*j, PositionInReturnString);
                }

                if((-i + JumpLength) + JumpLength*j < strlen(s))
                {
                    ReturnString[PositionInReturnString] = s[(-i + JumpLength) + JumpLength*j];
                    PositionInReturnString++;
                    printf("%d %c\n",(-i + JumpLength) + JumpLength*j, s[(-i + JumpLength) + JumpLength*j]);
                }

            }
        }
    }

    ReturnString[PositionInReturnString] = '\0';

    return(ReturnString);
}

int main()
{
    char input_string[1000] = "PAYPALISHIRING";
    int numRows = 3;


    char *outputarr = convert(input_string, numRows);
    
    for(int i = 0; outputarr[i] != '\0'; i++)
    {
        printf("%c", outputarr[i]);
    }
    printf("\n");

    return(0);
}