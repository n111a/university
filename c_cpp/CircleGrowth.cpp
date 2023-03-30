#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#pragma warning (disable: 4996)

typedef struct Scircle
{
	double x, y, radius;
	int status;
}circle;

void init(circle* circle, int len)
{
	for (int i = 0; i < len; i++)
	{
		circle[i].radius = 0;
		circle[i].status = 1;
	}
}

int main(int argc, char* argv[])
{
	if (argc == 3)
	{
		circle* circle;
		int num = 0, i1 = 0, j1 = 0, i, j, k;
		double dist = 0, min;
		FILE* fin, * fout;
		fin = fopen(argv[1], "r");
		fout = fopen(argv[2], "w");
		if ((fin != NULL) && (fout != NULL) && fscanf(fin, "%d", &num) == 1)
		{
				if (num == 1)
					fprintf(fout, "Infinity");
				else if (num > 1)
				{
					circle = new Scircle[num];
					for (i = 0; i < num; i++)
						fscanf(fin, "%lf %lf", &circle[i].x, &circle[i].y);
					init(circle, num);
					for (k = 0; k < num; k++)
					{
						min = 0;
						for (i = 0; i < num; i++)
						{
							if (circle[i].status == 1)
							{
								for (j = 0; j < num; j++)
								{
									if (i != j)
									{
										dist = sqrt(pow(circle[i].x - circle[j].x, 2) + pow(circle[i].y - circle[j].y, 2));
										if (circle[j].status == 0)
											dist = dist - circle[j].radius;
										else
											dist /= 2;
										if (min == 0)
										{
											min = dist;
											i1 = i;
										}
										else if (dist < min)
										{
											min = dist;
											i1 = i;
											j1 = j;
										}
									}
								}
							}
						}
						circle[i1].radius = min;
						circle[i1].status = 0;
						if (circle[j1].status == 1)
						{
							circle[j1].radius = min;
							circle[j1].status = 0;
						}
					}
					for (i = 0; i < num; i++)
						fprintf(fout, "%lf ", circle[i].radius);
					delete[] circle;
				}
				fclose(fin);
				fclose(fout);
		}
	}
	return 0;
}