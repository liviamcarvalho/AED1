#include <stdio.h>
#include <stdlib.h>
#define MAX_C 200

typedef struct {
    int v, w, p;
} Aresta;

int comparar(const void *a, const void *b){
    return ((Aresta *)a)->p - ((Aresta *)b)->p;
}

int pai[61], rank[61];

int encontrar(int x){
    if(pai[x] != x){
        pai[x] = encontrar(pai[x]);
    }
    return pai[x];
}

void unir(int x, int y){
    int raizX = encontrar(x);
    int raizY = encontrar(y);
    if(raizX != raizY){
        if(rank[raizX] > rank[raizY]){
            pai[raizY] = raizX;
        } else if(rank[raizX] < rank[raizY]){
            pai[raizX] = raizY;
        } else {
            pai[raizY] = raizX;
            rank[raizX]++;
        }
    }
}

int main(){
    int R, C;
    scanf("%d %d", &R, &C);
    Aresta cabos[MAX_C];
    for(int i = 0; i < C; i++){
        scanf("%d %d %d", &cabos[i].v, &cabos[i].w, &cabos[i].p);
    }
    qsort(cabos, C, sizeof(Aresta), comparar);
    for(int i = 1; i <= R; i++){
        pai[i] = i;
        rank[i] = 0;
    }
    int custoTotal = 0, arestasSelecionadas = 0;
    for(int i = 0; i < C && arestasSelecionadas < R - 1; i++){
        int v = cabos[i].v, w = cabos[i].w, p = cabos[i].p;
        if(encontrar(v) != encontrar(w)){
            unir(v, w);
            custoTotal += p;
            arestasSelecionadas++;
        }
    }
    printf("%d\n", custoTotal);
    return 0;
}
