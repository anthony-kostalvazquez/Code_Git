#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/*
//checks if a substring contains only unique chars between start and end
bool IsUnique(char *string, int start, int end)
{
    printf("start = %d end = %d \n",start, end);

    for (int i = start; i < end; i++)
    {
        printf("testing i =  %c versus j = ", string[i]);

        for (int j = i + 1; j <= end; j++)
        {
            printf("%c", string[j]);

            if(string[i] == string[j])
            {
                printf("fails there is a copy of %c\n", string[j]);
                return(false);
            }
        }
        printf("\n");
        
    }
    return(true);
}

int lengthOfLongestSubstring(char * s)
{
    //gets the size of the list
    int size = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        size++;
    }
    printf("size = %d\n", size);

    //we check through all of the sub lists of length
    for (int length = size; length > 0; length--)
    {
        printf("testing all lengths = %d\n", length);

        for (int start = 0; s[start+length-1] != '\0'; start++)
        {
            int end = start+length-1;
            if(IsUnique(s, start, end))
            {
                return(length);
            }
        }
        
    }
    
    return(0);
}

int lengthOfLongestSubstring(char * s)
{

    char tmp[50000];
    int LengthCount = 1;
    int Record = 0;
    bool loop;

    for (int i = 0; s[i] != '\0'; i++)
    {
        LengthCount = 01
        printf("s[i] = %c \n", s[i]);
        printf("CHECKING s[j] ");
        loop = true;

        for (int j = i+1 ; loop && s[j] != '\0'; j++)
        {
            for(int n = 0; n < j; n++)
            {
                if(s[n] == s[j])
                {
                    loop = false;
                }
            }  

            printf("%c ", s[j]);
            LengthCount++;

            if(LengthCount > Record)
            {
                Record = LengthCount;
            }



        }
        printf("\n");
    }
    
    return(Record);
}
*/

//checks if the char test is already in a string
//checks if a substring contains only unique chars between start and end
bool IsUnique(char *string, int start, int end)
{
    printf("start = %d end = %d \n",start, end);

    for (int i = start; i < end; i++)
    {
        printf("testing i =  %c versus j = ", string[i]);

        for (int j = i + 1; j <= end; j++)
        {
            printf("%c", string[j]);

            if(string[i] == string[j])
            {
                printf("fails there is a copy of %c\n", string[j]);
                return(false);
            }
        }
        printf("\n");
        
    }
    return(true);
}

int lengthOfLongestSubstring(char * s)
{
    //this is our set that can only contain one of a char, since there are only 128 possible chars its 128 long

    int l = 0;
    int record = 0;

    for(int r = 0; r < strlen(s); r++)
    {
        while(!IsUnique(s, l, r))
        {
            l++;
        }
        if(record < r - l + 1)
        {
            record = r - l + 1;
        }
    }

    return(record);
}



int main()
{
    char input_string[] = "qiojfckyatryekijksvusokcyeavwufpctajxkixdbxjm";

    printf("Input: %s\n Output: %d\n",input_string, lengthOfLongestSubstring(input_string));


    return(0);
}