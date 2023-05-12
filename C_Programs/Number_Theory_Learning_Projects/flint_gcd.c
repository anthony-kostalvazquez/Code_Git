//gcc -Wall -std=gnu99 -O3 -I/usr/local/lib flint_gcd.c -loptarith -lgmp -lflint -lm

#include <stdio.h>
#include <math.h>
#include <gmp.h>
#include <flint/flint.h>
#include <time.h>
#include <liboptarith/gcd/gcd_binary_l2r.h>
#include <flint/fmpz.h>

int brute_force_primality_test(int p)
{
    for(int i = 2; i <= ceil(sqrt(p)) ;i++)
    {
        if(p % i == 0)
        {
            return 0;
        }
    }
    return 1;
}


int main()
{
    srand(time(NULL));
    for(int i = 0; i < 100; i++)
    {
        int a = 0;
        int b = 7;
        int n = 16;
        int min = 0;
        int m = 479;
        //int m = rand() % 100000000;

        //generate random prime for m
        //while (gcd_binary_l2r_u32(m,n) != 1)
        //{
            //m += 1;
        //}

        printf("a = %d, m =  %d, b = %d, n = %d, min = %d\n",a,m,b,n,min);

        fmpz_t out,r1,m1,r2,m2;
        fmpz_init_set_ui(r1, a);
        fmpz_init_set_ui(m1, m);
        fmpz_init_set_ui(r2, b);
        fmpz_init_set_ui(m2, n);

        fmpz_CRT(out, r1, m1, r2, m2, 0);
        long output = fmpz_get_ui(out);
        long k_new = (long) ceil(((double) (min - output)) / (m * n));

        fmpz_clear(out);
        fmpz_clear(r1);
        fmpz_clear(m1);
        fmpz_clear(r2);
        fmpz_clear(m2);

        printf("this is my new functions ouput %ld\n",output + m * n * k_new);


        int c, d;

        xgcd_binary_l2r_s32(&c, &d, m, n);

        long x = a + (b - a) * c * m;

        long k = (long) ceil(((double) (min - x)) / (m * n));

        printf("this is the old functions output %ld\n", x + m * n * k);
    }
    return 1;
}