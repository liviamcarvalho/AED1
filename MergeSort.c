#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int const n = 400000;

void intercala (int p, int q, int r, int v[]) {
    int i, j, k, *w;
    w = malloc ((r-p) * sizeof (int));
    i = p; j = q; k = 0;
    while (i < q && j < r) {
        if (v[i] <= v[j]) w[k++] = v[i++];
        else w[k++] = v[j++];
    }
    while (i < q) w[k++] = v[i++];
    while (j < r) w[k++] = v[j++];
    for (i = p; i < r; i++) v[i] = w[i-p];
    free (w);
}

void mergesort (int p, int r, int v[]) {
    if (p < r - 1) {
        int q = (p + r)/2;
        mergesort (p, q, v);
        mergesort (q, r, v);
        intercala (p, q, r, v);
    }
}

int main(){
    clock_t t;
    int vetor[n];

    srand((unsigned)time(NULL));

    for(int k = 0; k < n; k++) {
        vetor[k] = rand() % n;
    }

    t = clock();
    mergesort(0, n, vetor);
    t = clock() - t;

    printf("Tempo de execucao: %lf ms\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

    return 0;
}
