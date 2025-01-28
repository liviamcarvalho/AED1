#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int n = 400000;

void insertionsort(int n, int v[]){
    int i, j, x;
    for(j = 1; j < n; j++){
        x = v[j];
        for(i = j - 1; i >= 0 && v[i] > x; i--){
            v[i + 1] = v[i];
        }
        v[i + 1] = x;
    }
}

int main(){
    clock_t t;
    int vetor[n];
    srand((unsigned)time(NULL));
    for(int k = 0; k < n; k++){
        vetor[k] = rand() % n;
    }
    t = clock();
    insertionsort(n, vetor);
    t = clock() - t;
    printf("Tempo de execucao: %lf ms\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
    return 0;
}
