#include <stdio.h>

int main()
{
    FILE *pF = fopen("test.6", "r");
    char buffer[255];

    if(pF == NULL)
    {
        printf("unable to locate the file\n");
    }
    else
    {
        // at the end of a file the fgets will return null
        while(fgets(buffer, 255, pF) != NULL) 
        {
        printf("%s", buffer);
        }
    }

    fclose(pF);
    return 0;
}