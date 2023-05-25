/* ASSIGNMENT DETAILS
In this assignment, you will write an application that searches a maze to help a trapped mouse
find the hidden cheese. The maze can be represented using 4 symbols as follows:
    • 1 represents a wall
    • 0 represents space
    • m represents the mouse’s initial position
    • c represents the cheese position
The following is an example input maze:

111111111111
101000001001
1c0000100001
101111111111
100111100001
110111111001
110000000m11
111110111101
111111111111

Your application must search the maze, starting at the m position, and stops when it reaches the c
position or if c is not reachable from m. Not all mazes have solutions. So, the application must
also stop if the maze has no solution.

For simplicity, you may assume the following:
    • the maze is surrounded by 1’s
    • the cheese (c position) can be found anywhere in the maze, except at the border (surrounding 1’s)

Create your own larger mazes to test your code. Your mazes must have a size of at least 50x50
characters, but they should not exceed a size that cannot fit on one screen without breaking lines.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Assignment2.h"


//prints a maze out from a queue of cells
void print_maze(int number_of_rows, int number_of_columns, CELL_T **MAZE)
{
    
    for (int i = 0; i < number_of_rows; i++)
    {
        for (int j = 0; j < number_of_columns; j++)
        {
            printf("%c ", (MAZE[i][j]).cell_type);
        }
    printf("\n");
    }
}

//takes a maze from a plain text file and saves the info into a 2D array
CELL_T **input_maze_from_text(int num_of_rows,int num_of_col, char *file_in)
{
    //initalizing some values 
    int row_num = 0;
    char buffer[num_of_col * num_of_rows];
    CELL_T *temp_cell;
    CELL_T **output_array;

    //allocating the memory for the array
    output_array = malloc(sizeof(CELL_T *)* num_of_rows);
    for (int i = 0; i < num_of_rows; i++)
    {
        output_array[i] = malloc(sizeof(CELL_T) * num_of_col);
    }

    //opening the file
    FILE *in_file = fopen(file_in, "r");

    //row loop (reads the plain text file line by line)
    while(fgets(buffer, sizeof(buffer), in_file))
    {
        //column loop (splits the lines into individual chars)
        for (int column = 0; column < num_of_col; column++)
        {
            char temp = buffer[column];
            temp_cell = create_new_cell(row_num, column, temp, false);
            output_array[row_num][column] = *temp_cell;
        }
        row_num++;
    }

    fclose(in_file);
    return(output_array);
}

//this is a program that will solve mazes from plain text files
int main(int argc, char * argv[])
{
    //NEED TO CHANGE THIS TO GET USER INPUT
    int number_of_rows = 9;
    int number_of_columns = 12;
    char file_name[] = "Mazes.txt";
    //NEED TO CHANGE THIS TO GET USER INPUT

    //Puts the plain text file into a 2D array called MAZE
    CELL_T **MAZE_ARRAY;
    MAZE_ARRAY = input_maze_from_text(number_of_rows, number_of_columns, file_name);
    print_maze(number_of_rows, number_of_columns, MAZE_ARRAY);





    // Free the memory that was allocated for each row in the 2D array
    for (int i = 0; i < number_of_rows; i++)
    {
        free(MAZE_ARRAY[i]);
    }

    // Free the memory that was allocated for the array of pointers to each
    // row in our 2D array
    free(MAZE_ARRAY);

    return(0);
}

