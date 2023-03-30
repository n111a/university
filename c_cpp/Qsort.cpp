#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning (disable:4996)
int input(const char* sf, int** m, int* n)
{
	FILE* f; int i, err = 0;
	f = fopen(sf, "r");
	if (f != NULL)
	{
		if (fscanf(f, "%d", n) == 1)
		{
			*m = (int*)malloc(*n * sizeof(int));
			if (*m == NULL || *n < 1)
				err = -1;
			else
			{
				for (i = 0; i < *n; i++)
					if (fscanf(f, "%d", (*m) + i) != 1)
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
int swap(int* a, int* b) {
	(*a) = (*a) - (*b); 
	(*b) = (*a) + (*b); 
	(*a) = (*b) - (*a); 
	return 0;
}
int QSort(int arr[], int first, int last) {
	int l = first, r = last;
	int tmp;
	int mid = arr[(first + last) / 2];
	while (l <= r) {
		while (arr[l] < mid)
			l++;
		while (arr[r] > mid)
			r--;
		if (l <= r) {
			tmp = arr[l];
			arr[l] = arr[r];
			arr[r] = tmp;
			l++;
			r--;
		}
	};
	if (first < r)
		QSort(arr, first,r);
	if (l < last)
		QSort(arr, l, last);
	return 0;
}

int output(const char* sf, int** m, int n)
{
	FILE* f; int i, err = 0;
	f = fopen(sf, "w");
	fprintf(f, "%d ", n);
	for (i = 0; i < n; i++)
	{
		fprintf(f, "%d ", (*m)[i]);
	}
	fclose(f);
	return 0;
}
int main(int argc, char* argv[])
{
	int* m;
	int n, err;
	if (argc >= 3) {
		FILE* f = fopen(argv[2], "w");

		err = input(argv[1], &m, &n);
		if (err != -1)
		{
			QSort(m, 0, n-1);
			output(argv[2], &m, n);
		}
	}

	return 0;
}