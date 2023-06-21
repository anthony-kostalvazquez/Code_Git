//gcc -o general_bin_read General_Bin_Read.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int data[512];
int j = 0;

FILE *in_file;

int main(int argc, char * argv[])
{
    if (argc != 4)
    {
        printf("\nFormat ./general_bin_read [location of file] [a] [b]\n");
        return 2;
    }

    //as in Δ = A mod B
    const int A = atoi(argv[2]);
    const int B = atoi(argv[3]);

    //Open both in files
    in_file = fopen(argv[1], "rb");

    printf("We are now reading from file %s\n", argv[1]);
    while ((fread(data, sizeof(data), 1, in_file) == 1))
    {
        for (int i = 0 ; i < 512; i++)
        {
            printf("class number = %d \t the discriminant is %d \n", data[i], -(A + B*(j)));
            j += 1;
        }
    }

    fclose(in_file);
    

    return 0;

}