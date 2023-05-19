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
#include <string.h>
#include <stdlib.h>




char Maze_Arr[50][50];
int j = 0;


int main(int argc, char * argv[])
{


    //Open both in files
    FILE *in_file;
    in_file = fopen(Mazes.txt, "r");

    printf("We are now reading from file %s\n", argv[1]);

    while ((fread(Maze_Arr, sizeof(Maze_Arr), 1, in_file) == 1))
    {
        for (int i = 0 ; i < 512; i++)
        {
            printf("class number = %d \t the discriminant is %d \n", Maze_Arr[i], -(A + B*(j)));
            j += 1;
        }
    }

    fclose(in_file);
    

    return(0);
}