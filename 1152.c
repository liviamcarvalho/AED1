#include <stdio.h>
#include <stdlib.h>
#define MAXN 200000

typedef struct{
    int origem, destino, peso;
} Aresta;

int pai[MAXN], rank[MAXN];
Aresta arestas[MAXN];

int comparar(const void *a, const void *b){
    return ((Aresta*)a)->peso - ((Aresta*)b)->peso;
}

int encontrar(int x){
    if(pai[x] != x){
        pai[x] = encontrar(pai[x]);
    }
    return pai[x];
}

void unir_conjuntos(int x, int y){
    int raizX = encontrar(x), raizY = encontrar(y);
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
    int m, n, arestas_usadas = 0;
    while(scanf("%d %d", &m, &n) && (m || n)){
        long long custo_total = 0, custo_mst = 0;
        for(int i = 0; i < m; i++){
            pai[i] = i;
            rank[i] = 0;
        }
        for(int i = 0; i < n; i++){
            scanf("%d %d %d", &arestas[i].origem, &arestas[i].destino, &arestas[i].peso);
            custo_total += arestas[i].peso;
        }
        qsort(arestas, n, sizeof(Aresta), comparar);
        for(int i = 0; i < n && arestas_usadas < m - 1; i++){
            if(encontrar(arestas[i].origem) != encontrar(arestas[i].destino)){
                unir_conjuntos(arestas[i].origem, arestas[i].destino);
                custo_mst += arestas[i].peso;
                arestas_usadas++;
            }
        }
        printf("%lld\n", custo_total - custo_mst);
    }
    return 0;
}
