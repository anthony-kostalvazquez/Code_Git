#include <stdio.h>



//will print out a visual representation of how an array changed
void visualizer(int array[], int size)
{

    int rows = 10;
    int columns = size;


    char array_print[rows][columns];

    //building the 2d array out of the 1d input
    for(int i = 0; i < columns; i++)
    {
       for(int j = 0; j < rows; j++)
       {
           if(j < abs(array[i] - rows))
           {
               array_print[j][i] = ' ';
           }
    
           else
           {
               array_print[j][i] ='0';
           }
       }
   }

    //just formats to look nice
    printf("\n");

    for(int i = 0; i < rows; i++)
    {
       for(int j = 0; j < columns; j++)
       {
          printf("%c ", array_print[i][j]);
       }
       printf("\n");
   }
    
    //prints the original 1d array
    for(int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}



//bubble sort
void sort(int array[], int size)
{
    //prints out the first graph
    visualizer(array, size);

    //starts sorting
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - i - 1; j++)
        {
            if(array[j] > array[j+1])
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                visualizer(array, size);
            }
        }
    }



}



int main(){

    int array[] = {9,1,4,2,3,5,6,7,8};
    int size = sizeof(array)/sizeof(array[0]);

    sort(array, size);

    return 0;
}