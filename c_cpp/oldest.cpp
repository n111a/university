#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning (disable:4996)
int solve(const char* sf, int* answer)
{
	FILE* f; int err = 0;
	int a;
	(*answer) = -1;
	f = fopen(sf, "r");
	if (f != NULL)
	{
		if (fscanf(f, "%d", &a) == 1)
		{
			while(a!=0)
			{
				a >>= 1;
				(*answer)++;
			}
		}
	}
	else
	{
		err = -1;
	}
	return 0;
}
int main(int argc, char* argv[])
{
	int answer = 1, err;
	if (argc >= 3) {
		FILE* f = fopen(argv[2], "w");
		fprintf(f, " ");
		fclose(f);
		err = solve(argv[1], &answer);
		if (err != -1)
		{
			FILE* f = fopen(argv[2], "w");
			fprintf(f, "%d", answer);
			fclose(f);
		}

	}

	return 0;
}