#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning (disable:4996)

int main(int argc, char* argv[])
{
		unsigned int answer = 1, err,i, n, tmp1, tmp2, j, cur=0;
		if (argc >= 3)
		{
			FILE* fin = fopen(argv[1], "r"), * fout = fopen(argv[2], "w");
			if (fin != NULL && fout != NULL)
			{
				fscanf(fin, "%u", &n);
				for (i = 1; i <= n; i++)
				{

					if (i >= 256)
					{
						j = 0; tmp2 = i / 256; tmp1 = i % 256; cur = 0;
						while (tmp2 != 0)
						{
							cur |= (tmp2 % 2 << 24 + j);
							cur |= (tmp2 % 2 << 23 - j);
							tmp2 /= 2;
							j++;
						}
						j = 0;
						while (tmp1 != 0)
						{
							cur |= (tmp1 % 2 << 8 + j);
							cur |= (tmp1 % 2 << 7 - j);
							tmp1 /= 2;
							j++;
						}
					}
					else
					{
						j = 0; tmp1 = i; cur = 0;
						while (tmp1 != 0)
						{
							cur |= (tmp1 % 2 << 8 + j);
							cur |= (tmp1 % 2 << 7 - j);
							tmp1 /= 2;
							j++;
						}
					}
					fprintf(fout, "%u ", cur);
				}
				fclose(fin);
				fclose(fout);
			}
			return -2;
		}
		else
			return -1;

	return 0;
}