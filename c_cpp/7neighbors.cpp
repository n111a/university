#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning (disable:4996)
int input(const char* sf, double** m, int* n)
{
	FILE* f; int i, err = 0;
	f = fopen(sf, "r");
	if (f != NULL)
	{
		if (fscanf(f, "%d", n) == 1)
		{
			*m = (double*)malloc(*n * sizeof(double));
			if (*m == NULL || *n < 1)
				err = -1;
			else
			{
				for (i = 0; i < *n; i++)
					if (fscanf(f, "%lf", (*m) + i) != 1)
					{
						free(*m); *m = NULL;
						err = -1;
						break;
					}
			}
		}
		else
			err = -1;
		fclose(f);
	}
	else
		err = -1;
	return err;
}
int solve(double** m, int n)
{
	int i;
	double prev1, prev2=(*m)[0];
	for (i = 1; i < n - 1; i++)
	{
		prev1 =(*m)[i];
		(*m)[i] = (prev2 + (*m)[i + 1])/2;
		prev2 = prev1;
	}
	return 0;
}
int output(const char* sf, double** m, int n)
{
	FILE* f; int i, err = 0;
	f = fopen(sf, "w");
	fprintf(f, "%d ", n);
	for (i = 0; i < n; i++)
	{
		fprintf(f, "%lg ", (*m)[i]);
	}
	fclose(f);
	return 0;
}
int main(int argc, char *argv[])
{
	double *m;
	int n, err;
	if (argc >= 3) {
		FILE* f = fopen(argv[2], "w");
		fprintf(f, " ");
		fclose(f);
		err=input(argv[1],&m, &n);
		if (err != -1)
		{
			solve(&m, n);
			output(argv[2], &m, n);
		}
	}
	
	return 0;
}