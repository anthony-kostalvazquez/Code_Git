#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define ROWS 3
#define COLUMNS 3

//this defines how many in a row you need to win, change this and the board size to turn this game into connect 4
#define WIN_COND 3

char board[ROWS][COLUMNS];
const char PLAYER = 'X';
const char COMPUTER = 'O';

void reset_board();
void print_board();
int check_free_space();
void player_move();
void computer_move();
char check_winner();
void print_winner(char);

int main()
{
    char winner = ' ';
    char response = ' ';

    do
    {
        winner = ' ';
        response = ' ';

        reset_board();

        while(winner == ' ' && check_free_space() != 0)
        {
            print_board(); 

            player_move();

            winner = check_winner();
            if(winner != ' ' || check_free_space() == 0)
            {
                break;
            }
            

            computer_move();

            winner = check_winner();
            if(winner != ' ' || check_free_space() == 0)
            {
                break;
            }

        }

        print_board();
        print_winner(winner);  

        printf("\nWould you like to play again? (Y/N): ");
        scanf(" %c", &response);
        response = toupper(response);
    }
    while (response == 'Y');

    printf("\nthanks for playing!");

    return 0;
}


//resets the board to empty spaces
void reset_board()
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLUMNS; j++)
        {
            board[i][j] =' ';
        }

    }

}

//prints the board at the current state
void print_board()
{   
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLUMNS; j++)
        {   
            printf(" %c ", board[i][j]);
            if (j != (COLUMNS - 1) )
            {
                printf("|");
            }
        }
    if(i != (ROWS - 1))
    {
        printf("\n---|---|---\n");
    }
    }

}

//counts the number of empty spaces on the board
int check_free_space()
{
    int free_spaces = ROWS * COLUMNS;

    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLUMNS; j++)
        {
            if(board[i][j] != ' ')
            {
                free_spaces--;
            }
        }
    }

    return free_spaces;
}

//gets the players move and updates the board
void player_move()
{
    int x;
    int y;

    printf("\nplease enter the row and column number of your move\n");
    do
    {
        printf("ENTER ROW (1 - %d): ", ROWS);
        scanf("%d", &x);
        x--;
        
        printf("ENTER COLUMN (1 - %d): ", COLUMNS);
        scanf("%d", &y);
        y--;

        if(board[x][y] != ' ')
        {
            printf("INVALID MOVE");
        }
        else
        {
            board[x][y] = PLAYER;
            break;
        }
    }
    while(board[x][y] != ' ');
}

//randomly generates a player move 
void computer_move()
{
    //creates a seed based on current time
    srand(time(0));
    int x;
    int y;

    if(check_free_space() > 0)
    {
        do
        {
            x = rand() %3;
            y = rand() %3;
        } while (board[x][y] != ' ');

        board[x][y] = COMPUTER;
        
    }
    else
    {
        print_winner(' ');
    }
}

//checks the board at the current state for a winner
char check_winner()
{
    int in_a_row_count;
    char current_check;
    //check rows for win condition
    for(int i = 0; i < ROWS; i++)
    {
        //initialize
        in_a_row_count = 1;

        for(int j = 0; j < (COLUMNS -1); j++ )
        {   
            if(board[i][j] == board[i][j+1])
            {
                current_check = board[i][j];
                in_a_row_count++;
                
                //checks for the win
                if( (in_a_row_count == WIN_COND) && (current_check != ' '))
                {
                    return current_check;
                }

            }
            else
            {
                in_a_row_count = 1;
            }
        }
    }

    //checks columns for a win
    for(int i = 0; i < COLUMNS; i++)
    {
        //initialize
        in_a_row_count = 1;
        for(int j = 0; j < (ROWS - 1); j++ )
        {
            if(board[j][i] == board[j+1][i])
            {
                current_check = board[j][i];
                in_a_row_count++;
            
            //checks for the win
            if( (in_a_row_count == WIN_COND) && (current_check != ' '))
            {
                return current_check;
            }

            }
            else
            {
                in_a_row_count = 1;
            }
        }
    } 

    //checks diagonals
    if(board[0][0] == board [1][1] && board [0][0] == board[2][2])
    {
        return board[0][0];
    }
    if(board[0][2] == board [1][1] && board [0][2] == board[2][0])
    {
        return board[0][2];
    }

    return ' ';
}

//prints out who one or if the game was a draw
void print_winner(char winner)
{
    if (winner == PLAYER)
    {
        printf("\nYOU WIN");
    }
    else if (winner == COMPUTER)
    {
        printf("\nYOU LOSE");
    }
    else
    {
        printf("\nITS A DRAW");
    }
    
}