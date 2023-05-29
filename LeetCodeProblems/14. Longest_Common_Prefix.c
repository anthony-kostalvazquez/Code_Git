#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


char * longestCommonPrefix(char ** strs, int strsSize)
{
    char *BaseWord = strs[0];

    //iterates through all the characters of the base word 
    for(int i = 0; BaseWord[i] != '\0'; i++)
    {
        char CurrentCharacter = BaseWord[i];
        printf("%c \n", CurrentCharacter);
        
        //compare the ith letter of the base word to every other sting in the list
        for(int j = 1; j < strsSize; j++)
        {
            printf("comapir to %c\n", strs[j][i]);
            if(strs[0][i] != strs[j][i])
            {
                printf("in here");
                strs[0][j] = '\0';
                return(strs[0]);
            }
        }

    }
}


int main()
{
    char *strs[] = {"flower","flow","flight","peepee"};


    printf("%s", longestCommonPrefix(strs, 3));

    return(0);
}