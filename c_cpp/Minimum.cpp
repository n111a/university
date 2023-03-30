#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning (disable:4996)
int solve(const char* sf, int* answer)
{
	FILE* f; int err = 0, x, min = 0, index = 1, counter = 0;
	f = fopen(sf, "r");
	if (f != NULL)
	{
		if (fscanf(f, "%d", &min) == 1) {
			counter++;
			while (fscanf(f, "%d", &x) == 1)
			{
				x <= min ? min = x, index = ++counter : counter++;
			}
			(*answer) = index;
		}
		else
		{
			err = -1;
		}

		fclose(f);
	}
	else
	{
		err = -1;
	}
	return 0;
}
int main(int argc, char* argv[])
{
	int answer = 0, err;
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