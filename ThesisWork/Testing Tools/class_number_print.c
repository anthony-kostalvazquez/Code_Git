//gcc -o class_number_print class_number_print.c -lm -lpari

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>

#include <pari/pari.h>

char in_file_name[500];
int data[512];
int j = 0;

FILE *in_file;

//returns 1 if a is a fundemental discriminant and 0 if not
int fundemental_check(int a)
{

    unsigned long int j = 0;

    //printf("a is = %d \n", a);

    for(unsigned long int i = 3; j < a; i += 2)
    {
        j = i * i;
        //printf("this is j %ld\n", j);

        if(a % j == 0)
        {
            //its divisable by an odd square and thus not fundamental
            //printf("Deemed not fund when j = %ld \n", j);
            return 0;
        }

    }

    return 1;
}

int main(int argc, char * argv[])
{

    if (argc != 5)
    {
        printf("\nFormat ./polycheck [folder] [a] [b] [class number division factor]\n");
        return 2;
    }

    pari_init(1000000000, 0);

    //as in Δ = A mod B
    const int A = atoi(argv[2]);
    const int B = atoi(argv[3]);
    const int Class_Num_Division_Factor = atoi(argv[4]);

    //initialize
    int file_num = 0;

    sprintf(in_file_name, "%s/h%dmod%d/h%dmod%d.%d",argv[1],A,B,A,B,file_num);

    //Open both in files
    in_file = fopen(in_file_name, "rb");

    while ((in_file != NULL))
    {

        while ((fread(data, sizeof(data), 1, in_file) == 1))
        {

            for (int i = 0 ; i < 512; i++)
            {
                unsigned long int h = data[i] / Class_Num_Division_Factor;
                
                unsigned long int D = -(A + B*(j));


                if (fundemental_check((A + B*(j))) == 1)
                {

                    GEN g = stoi(D);
                    long int pari_h = gtolong(qfbclassno0(g,0));


                    
                    
                    printf("%ld\n",pari_h);

                    cgiv(g);

                }
                else
                {
                    printf("D = %ld is not fundemental\n",D);
                }

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