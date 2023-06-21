// gcc -o polyadd_with_constant_2 Polyadd.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char in_file_1_name[500];
char in_file_2_name[500];
char out_file_name[500];

int in_data_1[512];
int in_data_2[512];
int out_data[512];

FILE *in_file_1;
FILE *in_file_2;
FILE *out_file;

int binAddition(int a, int b)
{
    int c; //carry
    while (b != 0) {
        //find carry and shift it left
        c = (a & b) << 1;
        //find the sum
        a = a ^ b;
        b = c;
    }
    return a;
}

int main(int argc, char * argv[])
{
    if (argc != 4)
    {
        printf("Format ./polyadd [folder] [a] [b]");
        return 2;
    }

    //as in Δ = A mod B
    const int A = atoi(argv[2]);
    const int B = atoi(argv[3]);

    //initialize
    int file_num = 0;

    sprintf(in_file_1_name, "%s/h%dmod%d/h%dmod%dPART1.%d",argv[1],A,B,A,B,file_num);
    sprintf(in_file_2_name, "%s/h%dmod%d/h%dmod%dPART2.%d",argv[1],A,B,A,B,file_num);
    sprintf(out_file_name, "%s/h%dmod%d/h%dmod%d.%d",argv[1],A,B,A,B,file_num);

    //Open both in files
    in_file_1 = fopen(in_file_1_name, "rb");
    in_file_2 = fopen(in_file_2_name, "rb");

    while ((in_file_1 != NULL) && (in_file_2 != NULL))
    {
        printf("\n\n-----We are now making file %s-----\n\n", out_file_name);
        //Create the out file
        out_file = fopen(out_file_name, "wb");

        while ((fread(in_data_1, sizeof(in_data_1), 1, in_file_1) == 1) && (fread(in_data_2, sizeof(in_data_2), 1, in_file_2) == 1))
        {
            //reading and adding to a buffer
            for (int i = 0; i < 512; i++)
            {
                out_data[i] = binAddition(2 * in_data_1[i],in_data_2[i]);
                printf("file 1 = %d, file 2 = %d \t 2*file1 + file 2 = %d \n", in_data_1[i], in_data_2[i], out_data[i]);
            }
            
            //writing the whole buffer to the new file
            fwrite(out_data, sizeof(out_data), 1, out_file);
        }

        
        fclose(in_file_1);
        fclose(in_file_2);
        fclose(out_file);

        file_num += 1;

        sprintf(in_file_1_name, "%s/h%dmod%d/h%dmod%dPART1.%d",argv[1],A,B,A,B,file_num);
        sprintf(in_file_2_name, "%s/h%dmod%d/h%dmod%dPART2.%d",argv[1],A,B,A,B,file_num);
        sprintf(out_file_name, "%s/h%dmod%d/h%dmod%d.%d",argv[1],A,B,A,B,file_num);

        //Open both in files
        in_file_1 = fopen(in_file_1_name, "rb");
        in_file_2 = fopen(in_file_2_name, "rb");

    }



    return 0;

}