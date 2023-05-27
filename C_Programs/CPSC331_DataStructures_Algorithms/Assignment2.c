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

//struct for locating various things around the maze
struct MAZE_INFO
{
    int rows;
    int col;
    int cheese_row;
    int cheese_col;
    int mouse_row;
    int mouse_col;
};
typedef struct MAZE_INFO MAZE_T;


//finds the neighbors of a given cell
SLQUEUE_T *FindNeigbours(CELL_T **Maze, int CurRow, int CurCol)
{
    SLQUEUE_T *tmp = createQueue();

    /*MORE ELEGANT BUT HARD TO UNDERSTAND I THINK
    for(int i = 0; i <= 1; i++)
    {
        for (int j = 1; j >= 0 ; j--)
        {
            if(Maze[CurRow+(i-j)][CurCol+(i+j-1)].cell_type != '1')
            {
                CELL_T* tmpC = (CELL_T *)malloc(sizeof( CELL_T ));
                *tmpC = *(&Maze[CurRow+(i-j)][CurCol+(i+j-1)]);
                enqueue(tmpC, &tmp);
            }

            //printf("\n");

            //print_cell(&Maze[CurRow+(i-j)][CurCol+(i+j-1)]);
            //print_cell(&tmpC);
            //printf("\n");

        }
        
    }
    */

    
    //Checks the up move (^)
    if(Maze[CurRow-1][CurCol].cell_type != '1')
    {
        CELL_T* tmpC = (CELL_T *)malloc(sizeof( CELL_T ));
        *tmpC = *(&Maze[CurRow-1][CurCol]);
        tmpC->cell_type = '^';
        enqueue(tmpC, &tmp);
    }
    //Checks the right move (>)
    if(Maze[CurRow][CurCol+1].cell_type != '1')
    {
        CELL_T* tmpC = (CELL_T *)malloc(sizeof( CELL_T ));
        *tmpC = *(&Maze[CurRow][CurCol+1]);
        tmpC->cell_type = '>';
        enqueue(tmpC, &tmp);
    }
    //Checks the left move (<)
    if(Maze[CurRow][CurCol-1].cell_type != '1')
    {
        CELL_T* tmpC = (CELL_T *)malloc(sizeof( CELL_T ));
        *tmpC = *(&Maze[CurRow][CurCol-1]);
        tmpC->cell_type = '<';
        enqueue(tmpC, &tmp);
    }
    //Checks the down move (v)
    if(Maze[CurRow+1][CurCol].cell_type != '1')
    {
        CELL_T* tmpC = (CELL_T *)malloc(sizeof( CELL_T ));
        *tmpC = *(&Maze[CurRow+1][CurCol]);
        tmpC->cell_type = 'v';
        enqueue(tmpC, &tmp);
    }
    
    
    return(tmp);
}

//prints a maze out from a queue of cells
//NOW WITH COOL COLOURS//
void print_maze(int number_of_rows, int number_of_columns, CELL_T **MAZE)
{
    
    for (int i = 0; i < number_of_rows; i++)
    {
        for (int j = 0; j < number_of_columns; j++)
        {
            //prints the 0's black
            if((MAZE[i][j]).cell_type == '0')
            {
                printf(BLK "%c " RESET, (MAZE[i][j]).cell_type);
            }
            //prints the 1's white
            else if((MAZE[i][j]).cell_type == '1')
            {
                printf("%c ", (MAZE[i][j]).cell_type);
            }
            //prints the cheese yellow
            else if((MAZE[i][j]).cell_type == 'c')
            {
                printf(YEL "%c " RESET, (MAZE[i][j]).cell_type);
            }
            //prints the mouse white
            else if((MAZE[i][j]).cell_type == 'm')
            {
                printf(BLU "%c " RESET, (MAZE[i][j]).cell_type);
            }
            //prints the path taken green
            else
            {
                printf(GRN "%c " RESET, (MAZE[i][j]).cell_type);
            }
        }
    printf("\n");
    }
}

//prints the maze with the path without destroying the original maze
void PrintPath(int num_of_rows, int num_of_col, CELL_T **MAZE, SLQUEUE_T *TrailQueue)
{
    for( CELL_T *tmpC = dequeue(&TrailQueue); !isEmptyQueue(TrailQueue); tmpC = dequeue(&TrailQueue))
    {
        printf("Current State of the Maze: \n");
        MAZE[tmpC->row][tmpC->column].cell_type = tmpC->cell_type;
        print_maze(num_of_rows, num_of_col, MAZE);
        printf("\n");
    }
    
}

//takes a maze from a plain text file and saves the info into a 2D array
//Also fills out the MazeInfo (i.e finds the mouse position and cheese)
CELL_T **input_maze_from_text(int num_of_rows,int num_of_col, char *file_in, MAZE_T *maze_info)
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

            //locates the mouse and the cheese
            if(temp == 'c')
            {
                maze_info->cheese_col = column;
                maze_info->cheese_row = row_num;
            }
            else if(temp == 'm')
            {
                maze_info->mouse_col = column;
                maze_info->mouse_row= row_num;
            }

        }
        row_num++;
    }

    fclose(in_file);
    return(output_array);
}

//this is a program that will solve mazes from plain text files
int main(int argc, char * argv[])
{
    //hardcoded in the name of the in file
    char file_name[] = "Mazes.txt";
    
    //initializing the maze_info struct
    MAZE_T MazeInfo;
    
    //taking user input
    printf("Enter the number of rows: ");
    scanf("%d", &MazeInfo.rows);
    printf("Enter the number of cols: ");
    scanf("%d", &MazeInfo.col);

    //Puts the plain text file into a 2D array called MAZE
    CELL_T **MAZE_ARRAY;
    MAZE_ARRAY = input_maze_from_text(MazeInfo.rows, MazeInfo.col, file_name, &MazeInfo);

    //DEPTH-FIRST SEARCH (STACK IMPLEMENTATION)
    //print statements
    printf("Depth First Search \n");




    //BREADTH-FIRST SEARCH (QUEUE IMPLEMENTATION)
    SLQUEUE_T *SearchQueue = createQueue();
    SLQUEUE_T *TrailQueue = createQueue();
    CELL_T *StartingCell = &MAZE_ARRAY[MazeInfo.mouse_row][MazeInfo.mouse_col];

    enqueue(StartingCell, &SearchQueue);
    bool MoreToSearch = true;

    while(!isEmptyQueue(SearchQueue) && MoreToSearch)
    {
        print_maze(MazeInfo.rows, MazeInfo.col, MAZE_ARRAY);
        printf("\n");


        CELL_T *checking = dequeue(&SearchQueue);
        MAZE_ARRAY[checking->row][checking->column].visited = true;
        enqueue(checking, &TrailQueue);

        if (checking->row == MazeInfo.cheese_row && checking->column == MazeInfo.cheese_col)
        {
            MoreToSearch = false;
        }
        else
        {
            //itterates through the eligible Neighbors of the current cell
            for(SLQNODE_T *i = FindNeigbours(MAZE_ARRAY, checking->row, checking->column)->rear; i != NULL; i = i->next)
            {
                if(!(i->cell)->visited)
                {
                    enqueue(i->cell, &SearchQueue);
                }
            }
            
        }
    }

    //print statements
    printf("Breadth First Search \n");
    printQueue(TrailQueue);
    printf("The mouse moved %d\n", SizeQueue(TrailQueue));
    PrintPath(MazeInfo.rows, MazeInfo.col, MAZE_ARRAY, TrailQueue);




    //printf("Mouse moved %d Times");

    // Free the memory that was allocated for each row in the 2D array
    for (int i = 0; i < MazeInfo.rows; i++)
    {
        free(MAZE_ARRAY[i]);
    }

    // Free the memory that was allocated for the array of pointers to each
    // row in our 2D array
    free(MAZE_ARRAY);

    return(0);
}


/*
DEBUG STATEMENTS
printf("the mouse is at row: %d col: %d\n", MazeInfo.mouse_row, MazeInfo.mouse_col);
printf("the mouse is at row: %d col: %d\n", MazeInfo.cheese_row, MazeInfo.cheese_col);
print_maze(MazeInfo.rows, MazeInfo.col, MAZE_ARRAY);
*/
