#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void merge(int *v, int n, int m)
{
    int i, j, k;
    int *aux = (int *)malloc(n * sizeof(int));

    for (i = 0, j = m, k = 0; k < n; k++)
    {
        if (j == n)
            aux[k] = v[i++];
        else if (i == m)
            aux[k] = v[j++];
        else if (v[j] < v[i])
            aux[k] = v[j++];
        else
            aux[k] = v[i++];
    }

    for (i = 0; i < n; i++)
        v[i] = aux[i];

    free(aux);
}

void merge_sort(int *v, int n)
{
    if (n < 2)
        return;

    int m = n / 2;

    merge_sort(v, m);
    merge_sort(v + m, n - m);
    merge(v, n, m);
}

int main(int argc, char **argv)
{
    struct timespec a, b;
    unsigned int t, n;
    int i, *v;

    n = atoi(argv[1]);
    v = (int *)malloc(n * sizeof(int));

    srand(time(NULL));

    for (i = 0; i < n; i++)
        v[i] = rand();

    clock_gettime(CLOCK_MONOTONIC, &b);
    merge_sort(v, n);
    clock_gettime(CLOCK_MONOTONIC, &a);

    t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);

    printf("%u\n", t);

    free(v);

    return 0;
}