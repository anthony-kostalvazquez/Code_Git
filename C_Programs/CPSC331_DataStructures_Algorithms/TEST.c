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
void print_maze_queue(SLQUEUE_T *queue)
{
    //itterates through all of the nodes of queue
    for(SLQNODE_T *i = queue->rear; i != NULL; i = i->next)
    {
        printf("%c", (i->cell)->cell_type);
        //prints out a new line when the the row number is about to change
        
        if(((i->next)->cell)->row != (i->cell)->row)
        {
            printf("\n ");
        }
    }
}

//takes a maze from a plain text file and saves the info into a queue
CELL_T *input_maze_from_text(int num_of_rows,int num_of_col, char *file_in)
{
    //initalizing some values 
    SLQUEUE_T *return_queue = createQueue();
    int row_num = 0;
    CELL_T *temp_cell;
    char Maze_Arr[num_of_col * num_of_rows];

    //opening the file
    FILE *in_file = fopen(file_in, "r");
    CELL_T MAZE_ARRAY[num_of_col * num_of_rows];


    //row loop (reads the plain text file line by line)
    while(fgets(Maze_Arr, sizeof(Maze_Arr), in_file))
    {
        //column loop (splits the lines into individual chars)
        for (int column = 0; column < num_of_col; column++)
        {
            char temp = Maze_Arr[column];
            temp_cell = create_new_cell(row_num, column, temp, false);
            MAZE_ARRAY[row_num + column] = *temp_cell;
            enqueue(temp_cell, &return_queue);
        }
        row_num++;
    }

    fclose(in_file);
    return(MAZE_ARRAY);
}

//this is a program that will solve mazes
int main(int argc, char * argv[])
{
    //NEED TO CHANGE THIS TO GET USER INPUT
    int number_of_rows = 9;
    int number_of_columns = 12;
    char file_name[] = "Mazes.txt";
    //NEED TO CHANGE THIS TO GET USER INPUT

    SLQUEUE_T *MAZE_QUEUE;
    input_maze_from_text(number_of_rows, number_of_columns, file_name);
    

    return(0);
}