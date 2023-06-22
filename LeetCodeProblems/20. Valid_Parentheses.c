#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>


bool isValid(char * s)
{
    char Stack[10000] = {'\0'};
    int top = -1;

    for (int i = 0; s[i] != '\0' ; i++)
    {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{') //we push opening parenthesis to the top of the stack
        {
            top++;
            Stack[top] = s[i];
        }
        else //we pop the stack if the matching closed parenthesis are found at the top
        {
            if (top != -1)
            {
                if(s[i] == ')' && Stack[top] == '(')
                {
                    Stack[top] = '\0';
                    top--;
                }
                else if(s[i] == ']' && Stack[top] == '[')
                {
                    Stack[top] = '\0';
                    top--;
                }
                else if(s[i] == '}' && Stack[top] == '{')
                {
                    Stack[top] = '\0';
                    top--;
                }
                else
                {
                return(false);
                }
            }
            else
            {
                return(false);
            }
        }

    }

    if(top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    char input[6] = "{}()[]";
    printf("%d", isValid(input));
    return 0;
}