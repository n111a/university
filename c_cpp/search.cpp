#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning (disable:4996)
int input(const char* sf, double** m, int* n, double *x)
{
	FILE* f; int i, err = 0;
	f = fopen(sf, "r");
	if (f != NULL)
	{
		if (fscanf(f, "%lf", x) == 1 && fscanf(f, "%d", n) == 1)
		{
			*m = (double*)malloc(*n * sizeof(double));
			if (*m == NULL || *n < 0)
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
int solve(double* m, int n, int *answer, double x)
{
	int i = 0, right=n-1, left=0, mid=0;
	if (x > m[n - 1])
		(*answer) = n+1;
	else
	{
		while (left < right)
		{
			mid = (left + right) / 2;
			if (x > m[mid])
				left = mid + 1;
			else
				right = mid;
		}

		(*answer) = mid + 1;
		if (x > m[mid])
			(*answer) += 1;
	}
	return 0;
}
int output(const char* sf, int answer)
{
	FILE* f; 
	f = fopen(sf, "w");
	fprintf(f, "%d ", answer);
	fclose(f);
	return 0;
}
int main(int argc, char* argv[])
{
	double* m, x;
	int n, err, answer=1;
	if (argc >= 3) {
		FILE* f = fopen(argv[2], "w");
		fprintf(f, " ");
		fclose(f);
		err = input(argv[1], &m, &n, &x);
		if (err != -1)
		{
			solve(m, n, &answer, x);
			output(argv[2], answer);
		}
	}

	return 0;
}