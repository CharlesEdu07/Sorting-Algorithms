#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int v[], int n) {
    int pivot = v[n];
    int i = -1;
    int j = 0;
    
    while (j < n) {
        if (v[j] < pivot) {
            i++;
            swap(&v[i], &v[j]);
        }
        j++;
    }
    
    swap(&v[i + 1], &v[n]);
    
    return i + 1;
}

void quick_sort(int v[], int n) {
    if (n < 2)
        return;
    
    int pivot = partition(v, n - 1);
    
    quick_sort(v, pivot);
    quick_sort(v + pivot + 1, n - pivot - 1);
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
    quick_sort(v, n);
    clock_gettime(CLOCK_MONOTONIC, &a);

    t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);

    printf("%u\n", t);

    free(v);

    return 0;
}