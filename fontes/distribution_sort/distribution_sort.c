#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int max(int *v, int n) {
    int i, max = v[0];

    for (i = 1; i < n; i++)
        if (v[i] > max)
            max = v[i];

    return max;
}

int min(int *v, int n) {
    int i, min = v[0];

    for (i = 1; i < n; i++)
        if (v[i] < min)
            min = v[i];

    return min;
}

void distribution_sort(int *v, int n) {
    int s = min(v, n);
    int b = max(v, n);

    int *c = (int *) malloc((b - s + 2) * sizeof(int));
    int *w = (int *) malloc(n * sizeof(int));

    int d, i;

    for (i = 0; i < b - s + 2; i++)
        c[i] = 0;

    for (i = 0; i < n; i++)
        c[v[i] - s + 1]++;

    for (i = 1; i < b - s + 2; i++)
        c[i] += c[i - 1];

    for (i = 0; i < n; i++) {
        d = v[i] - s + 1;
        w[c[d] - 1] = v[i];
        c[d]--;
    }

    for (i = 0; i < n; i++)
        v[i] = w[i];    
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
        v[i] = rand() % (900 + 1 - 0) + 0;

    clock_gettime(CLOCK_MONOTONIC, &b);
    distribution_sort(v, n);
    clock_gettime(CLOCK_MONOTONIC, &a);

    t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);

    printf("%u\n", t);

    free(v);

    return 0;
}