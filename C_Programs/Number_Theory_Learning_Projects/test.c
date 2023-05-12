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

#include <liboptarith/primes.h>
#include <liboptarith/sqrtmodp_list.h>

#include "clgrp.h"
#include "sieve.h"
#include <pari/pari.h>



int main()
{


  return 0;
} 







void pari_verify(int * result, const long D)
{
	GEN g = stoi(D);
	GEN v = quadclassunit0(g, 0, 0, 0);
	GEN clgrp = compo(v, 2);

	for (int i = 1; i < lg(clgrp); i++)
	{
		if (result[i - 1] != gtolong(compo(clgrp, i)))
		{
			char err[100];
			sprintf(err, "D=%ld, Cl[%d] = %d, actual %ld\n", D, i - 1, result[i - 1], gtolong(compo(clgrp, i)));
			perror(err);
			exit(1);
		}
	}

	cgiv(clgrp);
	cgiv(v);
	cgiv(g);
}