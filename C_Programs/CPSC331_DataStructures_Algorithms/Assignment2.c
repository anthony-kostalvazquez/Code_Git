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

#include "Assignment2DLS.h"
#include "Assignment2SLQ.h"



DLSNODE_T *input_maze_from_text(int num_of_rows,int num_of_col)
{
    DLSNODE_T *return_stack_top;

    char Maze_Arr[num_of_col * num_of_rows];
    FILE *in_file = fopen("Mazes.txt", "r");


    int row_num = 0;
    DLSNODE_T *temp_node;
    CELL_T *temp_cell;

    //row loop
    while(fgets(Maze_Arr, sizeof(Maze_Arr), in_file))
    {
        for (int column = 0; column < num_of_col; column++)
        {
            char temp = Maze_Arr[column];
            //printf("what it should be %c \n", Maze_Arr[column]);
            //printf("What temp is %c \n", temp);
            //printf("%c ", Maze_Arr[column]);
            
            temp_cell = create_new_cell(row_num, column, temp, false);

            //printf("%s \n", temp_cell->cell_type);
            //printf("%c \n", temp);
            push(&return_stack_top, temp_cell);
            //printf(        "%c",peek(return_stack_top).cell_type);

            //print_cell(temp_cell);

        }
        printf("\n");
        row_num++;
    }


    
    printStack(return_stack_top);

    /*
    DLSNODE_T *tmp = return_stack_top;
    CELL_T current_cell;
    
    printf("TOP--> ");
    
    
    while(tmp != NULL)
    {
        current_cell = tmp->cell;
        printf("%c ", current_cell.cell_type);
        tmp = tmp->next;
    }
    */
    
    fclose(in_file);
    return(return_stack_top);
}


int main(int argc, char * argv[])
{
    //NEED TO CHANGE THIS TO GET USER INPUT
    int number_of_rows = 9;
    int number_of_columns = 12;


    input_maze_from_text(number_of_rows, number_of_columns);
    

    return(0);
}