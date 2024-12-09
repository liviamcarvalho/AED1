#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int const n = 400000;

int separa (int p, int r, int v[]) {
    int c, j, k, t;
    c = v[r]; j = p;
    for (k = p; k < r; k++){
        if (v[k] <= c) {
            t = v[j], v[j] = v[k], v[k] = t;
            j++;
        }
    }
    v[r] = v[j], v[j] = c;
    return j;
}

void quicksort (int p, int r, int v[]) {
    int j;
    if (p < r) {
        j = separa (p, r, v);
        quicksort (p, j - 1, v);
        quicksort (j + 1, r, v);
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
    quicksort(0, n-1, vetor);
    t = clock() - t;

    printf("Tempo de execucao: %lf ms\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

    return 0;
}
