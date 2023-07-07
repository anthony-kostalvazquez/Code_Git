#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int maxConsecutiveAnswers(char * answerKey, int k)
{
    char CurrentCharacter = '\0';
    int Changes = 0;
    int Record = 0;
    int InARow = 0;

    for (int i = 0; answerKey[i] != '\0' ; i++)
    {
        //printf("%c\n", answerKey[i]);

        CurrentCharacter = answerKey[i];
        InARow = 1;
        Changes = 0;

        while (Changes < k && answerKey[i+1] != '\0')
        {
            if(CurrentCharacter != answerKey[i+1])
            {
                i++;
                Changes++;
            }
            else
            {
                i++;
            }
            InARow++;
        }

        if (InARow > Record)
        {
            Record = InARow;
        }
        
        
    }
    

    return Record;
}

int main()
{
    char* answerKey = "TFFT";
    int k = 1;

    printf("Output is = %d\n", maxConsecutiveAnswers(answerKey, k));


    return 0;
}
