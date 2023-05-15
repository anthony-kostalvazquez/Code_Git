#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char * longestCommonPrefix(char ** strs, int strsSize)
{

    for(int i = 1; i < strsSize; i++)
    {
        printf("%d \n", i);

        for(int j = 0; strs[i][j]; j++)
        {
            printf("%c \n", strs[i][j]);

            if(strs[0][j] != strs[i][j])
            {
                strs[0][j] = '\0';
            }
        }
    }

    return(strs[0]);
}


int main()
{
    char *strs[] = {"flower","flow","flight"};


    printf("%s", longestCommonPrefix(strs, 3));

    return(0);
}