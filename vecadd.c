#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100000
void assignRandomValues(int a[], int b[])
{
for (int i = 0; i < N; i++)
{
a[i] = rand() % 1000;
b[i] = rand() % 1000;
}
}
int main(int argc, char *argcv[])
{

int a[N], b[N], c[N];
assignRandomValues(a, b);
int p[] = {2, 4, 8, 16, 32, 100, 1000};
for (int i = 0; i < 7; i++)
{
clock_t begin = clock();
#pragma omp parallel private(i) shared(a, b, c)
{
#pragma omp for
for (int j = 0; j < N; j++)
{
c[j] = a[j] + b[j];
}
}
clock_t end = clock();
double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
printf("%d threads: %f miliseconds\n", p[i], time_spent);
}
return 0;
}