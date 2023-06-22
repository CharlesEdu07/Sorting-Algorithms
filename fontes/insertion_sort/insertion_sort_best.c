#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *v, unsigned int n)
{
    int i, j, k;

    for (i = 1; i < n; i++)
    {
        k = v[i];
        j = i - 1;

        while (j >= 0 && v[j] > k)
        {
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = k;
    }
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
        v[i] = i;

    clock_gettime(CLOCK_MONOTONIC, &b);
    insertion_sort(v, n);
    clock_gettime(CLOCK_MONOTONIC, &a);

    t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);

    printf("%u\n", t);

    free(v);

    return 0;
}
