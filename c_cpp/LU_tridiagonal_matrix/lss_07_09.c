#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "lss_07_09.h"
int check_minor(double eps, double l)
{
    if (abs(l) < eps)
        return -1;
    else
        return 0;
}
int lss_07_09(int n, double* A, double* B, double* X, double* tmp) {
  double EPS = 1e-8;

  double time_start = 1.0 * clock() / 1000.0;

  double *a = A; // size n
  double *c = A + n; // size n-1
  double *d = A + 2*n-1; // size n-1

  double *l = tmp + 0; // size n
  double *lambda = tmp + n; // size n-1
  double *u = tmp + 2*n-1; // size n-1
  double *y = tmp + 3*n-2; // size n
  double ly;
  double lu;
  int last_index = n - 1;
  if (flag_debug_output) {
    printf("A = L*U\n");
    printf("Building matrix L and U\n");
    double time_now = 1.0 * clock() / 1000.0;
    printf("Time in function = %lf\n\n", time_now - time_start);
  }
  for (int i = 0; i <= last_index; i++) {
    l[i] = a[i];
    if (i > 0)
    {
        lu = lambda[i - 1] * u[i - 1];
        l[i] = l[i] - lu;
    }
    if (check_minor(EPS, l[i]))
      return -1;
    if (i < last_index) {
      u[i] = c[i] / l[i];
      lambda[i] = d[i];
    }
  }

  if (flag_debug_output) {
    printf("Building y = U*x, solving L*y = b to find y\n");
    double time_now = 1.0 * clock() / 1000.0;
    printf("Time in function = %lf\n\n", time_now - time_start);
  }
  y[0] = B[0] / l[0];
  for (int i = 1; i <= last_index; i++) {
      ly = lambda[i - 1] * y[i - 1];
      y[i] = (B[i] - ly) / l[i];
  }

  if (flag_debug_output) {
    printf("Solving U*x = y to find x\n");
    double time_now = 1.0 * clock() / 1000.0;
    printf("Time in function = %lf\n\n", time_now - time_start);
  }
  X[last_index] = y[last_index];
  for (int i = last_index -1; i >= 0; i--) {
    X[i] = y[i] - u[i] * X[i+1];
  }

  if (flag_debug_output) {
    printf("Done!\n");
    double time_now = 1.0 * clock() / 1000.0;
    printf("Time in function = %lf\n\n", time_now - time_start);
  }
  return 0;
}
