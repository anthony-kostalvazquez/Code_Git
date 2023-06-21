//gcc -o binary_reader Binary_Reader.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char in_file_name[500];
int data[512];
int j = 0;

FILE *in_file;

int main(int argc, char * argv[])
{
    if (argc != 4)
    {
        printf("\nFormat ./binary_reader [folder] [a] [b]\n");
        return 2;
    }

    //as in Δ = A mod B
    const int A = atoi(argv[2]);
    const int B = atoi(argv[3]);

    //initialize
    int file_num = 0;

    sprintf(in_file_name, "%s/h%dmod%d/h%dmod%dPART1.%d",argv[1],A,B,A,B,file_num);

    //Open both in files
    in_file = fopen(in_file_name, "rb");

    while ((in_file != NULL))
    {
        printf("We are now reading from file %s\n", in_file_name);

        while ((fread(data, sizeof(data), 1, in_file) == 1))
        {
            for (int i = 0 ; i < 512; i++)
            {
                printf("class number = %d \t the discriminant is %d \n", data[i], -(A + B*(j)));
                j += 1;
            }
        }

        fclose(in_file);

        file_num += 1;

        sprintf(in_file_name, "%s/h%dmod%d/h%dmod%d.%d",argv[1],A,B,A,B,file_num);

        //Open both in files
        in_file = fopen(in_file_name, "rb");
    }

    return 0;

}