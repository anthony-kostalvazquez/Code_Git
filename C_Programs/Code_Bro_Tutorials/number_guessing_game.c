#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{   
    const int MIN = 1;
    const int MAX = 100;
    int guess;
    int guesses;
    int answer;

    //uses the current time as a seed to generate rand integers
    srand(time(0));

    //generates a number between min and max
    answer = (rand() % MAX) + MIN;

    do{
        printf("Enter a guess: ");
        scanf("%d", &guess);
        if(guess > answer)
        {
            printf("Too high!\n");
        }
        else if(guess < answer)
        {
            printf("Too low!\n");
        }
        else
        {
            printf("CORRECT!\n");
        }
        guesses++;
    }while(guess != answer);

    printf("Answer : %d", answer);
    printf("\nGuesses : %d", guesses);

    return 0;
}