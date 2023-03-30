#include "lss_07_09.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#pragma warning (disable:4996)
int n;
double *A, *B, *X, *tmp;
int flag_print;
int flag_execution_time;
FILE *fin = NULL, *fout = NULL;
void debug_print(int flag, char* message)
{
    if (flag == 1)
        printf(message);
}
void error(int code)
{
    switch (code)
    {
    case -1:
        debug_print(1,"/home/ivk/lss$ ./lss -? \n\
              Usage: lss [input_file_name] [output_file_name] [options] \n\
              Where options include: \
                -d        print debug messages [default OFF] \n\
                -e        print errors [default OFF] \n\
                -p        print matrix [default OFF] \n\
                -t        print execution time [default OFF] \n\
                -h, -?    print this and exit \n\
              Default input_file_name value is lss_00_00_in.txt, default output_file_name value is lss_00_00_out.txt.\n");
        exit(-1);
        break;
    case -2:
        debug_print(1,"/home/ivk/lss$ ./lss -? \n\
              Usage: lss [input_file_name] [output_file_name] [options] \n\
              Where options include: \
                -d        print debug messages [default OFF] \n\
                -e        print errors [default OFF] \n\
                -p        print matrix [default OFF] \n\
                -t        print execution time [default OFF] \n\
                -h, -?    print this and exit \n\
              Default input_file_name value is lss_00_00_in.txt, default output_file_name value is lss_00_00_out.txt.\n");
        exit(-2);
        break;
    case -3:
        debug_print(flag_debug_output, "Another reading during parsing command line\n");
        exit(-3);
        break;
    case -4:
        debug_print(flag_debug_output, "Can't open read/write files \n");
        exit(-4);
        break;
    case -5:
        debug_print(flag_debug_output, "Can't read n\n");
        exit(-5);
        break;
    case -6:
        debug_print(flag_debug_output, "Can't read A \n");
        exit(-6);
        break;
    case -7:
        debug_print(flag_debug_output, "Can't read B \n");
        exit(-7);
        break;
    default:
        exit(-8);
}

}

void print_matrix(int n, double* a, double* d, double* c, double* B) {
  printf("A  B\n");
    for (int i = 0; i < n; i++) {
        printf("\n");
        for (int j = 0; j <= i-2; j++) {
          printf("0 ");
        }
        if (0 <= i-1) {
          printf("%lf   ", d[i-1]);
        }
        printf("%lf ", a[i]);
        if (i+1 < n) {
          printf("%lf   ", c[i]);
        }
        for (int j = i+2; j < n; j++) {
          printf("0 ");
        }
        printf("    %lf ", B[i]);
  }
}

size_t lss_memsize_07_09(int n, char param) {
    switch (param)
    {
    case 'A':
        return (3 * n - 2) * sizeof(double);
        break;
    case 'X' || 'B':
        return n * sizeof(double); break;
    case 't':
        return (4 * n - 2) * sizeof(double); break;
    default:
        return n * sizeof(double); break;
    }
}

void print_answer(int ans)
{
    if (ans == -1) {
        fprintf(fout, "0");
        return;
    }
    fprintf(fout, "%d\n", n);
   for (int i = 0; i < n; i++) 
        fprintf(fout, "%1.9lf\n", X[i]);
}
void allocating(int n)
{
    A = (double*)malloc(lss_memsize_07_09(n, 'A'));
    B = (double*)malloc(lss_memsize_07_09(n, 'B'));
    X = (double*)malloc(lss_memsize_07_09(n, 'X'));
    tmp = (double*)malloc(lss_memsize_07_09(n, 't'));

}
void reading(FILE *fin) {
  if (!fscanf(fin, "%d", &n)) 
      error(-5);
  allocating(n);
  for (int i = 0; i < n; i++) {
    int id1 = n + (n-1) + (i-1);
    int id2 = i;
    int id3 = n + i;
    if (0 <= i-1) {
      if (!fscanf(fin, "%lf", &A[id1])) error(-6);
    }
    if (!fscanf(fin, "%lf", &A[id2])) {
        error(-6);
    }
    if (i+1 < n) {
      if (!fscanf(fin, "%lf", &A[id3]))  error(-6);
    }
  }
  for (int i = 0; i < n; i++)
    if (!fscanf(fin, "%lf", &B[i])) 
        error(-7);
}

void free_mem()
{
    free(A); free(B); free(X); free(tmp);
}

void open_files(int argc, char* argv[])
{
    if (argc >= 2)
    {
        fin = fopen(argv[1], "r");
        if (argc >= 3)
            fout = fopen(argv[2], "w");
        else {
            fin = fopen("lss_07_09_in.txt", "r");
            fout = fopen("lss_07_09_out.txt", "w");
        }
    } 
    else
    {
        fin = fopen("lss_07_09_in.txt", "r");
        fout = fopen("lss_07_09_out.txt", "w");
    }
    
    if (!fin || !fout) error(-4);
}
void parsing(int argc, char *argv[]) {
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-' )
        switch (argv[i][1])    
        {
            case 'd':
                flag_debug_output = 1;
                break;
            case 'e':
                flag_errors = 1;
                break;
            case 'p':
                flag_print = 1;
                break;
            case 't':
                flag_execution_time = 1;
                break;
            case 'h':
                error(-1);      
                break;
            case '?':
                error(-2);
                break;
            default:
                exit(-3);   
        }
  }
  open_files(argc, argv);
}

int main(int argc, char *argv[]) {
  double time_start = 1.0 * clock() / 1000.0;
  parsing(argc, argv);
  reading(fin);
  double* a = A;
  double* c = A + n;
  double* d = A + 2 * n - 1;
  if (flag_print) {
    print_matrix(n, a,c,d,B);
  }
  int ans = lss_07_09(n, A, B, X, tmp);

  print_answer(ans);

  free_mem();
  if (flag_execution_time) {
    double time_now = 1.0 * clock() / 1000.0;
    printf("Execution time = %lf\n", time_now-time_start);
  }
  return ans;
}
