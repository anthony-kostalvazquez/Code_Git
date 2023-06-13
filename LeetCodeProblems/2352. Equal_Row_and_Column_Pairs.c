#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int equalPairs(int** grid, int gridSize, int* gridColSize)
{
    int NumofEqual = 0;
    int j =0;


    



    //itterates through the rows
    for (int row = 0; row < gridSize; row++)
    {
        //iterates through every column for each row
        for (int col = 0; col < *gridColSize; col++)
        {
            printf("\ncolumn %d = ", col);

            for (j = 0; (j < gridSize) && (grid[row][j] == grid[j][col]); j++)
            {
                printf("%d ", grid[j][col]);
            }
            printf("\nj is = %d\n", j);
            
            if(j == (*gridColSize))
            {
                NumofEqual++;
            }
        }

            
    }
        
    



    return(NumofEqual);
}



int main()
{
    int in_array[3][3] = {{3,2,1},{1,7,6},{2,7,7}};

    //grid size here refers to the number of rows
    int grid_size = 3;
    int grid_col_size = 3;

    //allocates the mem for the array
    int **grid = (int **)malloc(sizeof(int*) * grid_size);
    for (int i = 0; i < grid_size; i++)
    {
        grid[i] = malloc(sizeof(int*) * grid_col_size);
        grid[i] = in_array[i];
    }

    

    


    printf("the output is %d \n", equalPairs(grid, grid_size, &grid_col_size));


    return 0;
}