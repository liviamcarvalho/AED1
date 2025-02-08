#include <stdio.h>
#include <stdlib.h>
#define MAX_N 500
#define MAX_M 124750

typedef struct {
    int cidade1, cidade2, custo;
} Rodovia;

int pai[MAX_N + 1], tamanho[MAX_N + 1];

int comparar(const void *a, const void *b){
    return ((Rodovia *)a)->custo - ((Rodovia *)b)->custo;
}

int encontrar(int cidade){
    if(pai[cidade] == cidade) return cidade;
    return pai[cidade] = encontrar(pai[cidade]);
}

void unir(int a, int b){
    a = encontrar(a);
    b = encontrar(b);
    if(a != b){
        if(tamanho[a] < tamanho[b]){
            pai[a] = b;
        } else if(tamanho[a] > tamanho[b]){
            pai[b] = a;
        } else {
            pai[b] = a;
            tamanho[a]++;
        }
    }
}

int main(){
    int cidades, rodovias, int custo_total = 0, arestas_usadas = 0;
    scanf("%d %d", &cidades, &rodovias);
    Rodovia lista[rodovias];
    for(int i = 0; i < rodovias; i++){
        scanf("%d %d %d", &lista[i].cidade1, &lista[i].cidade2, &lista[i].custo);
    }
    qsort(lista, rodovias, sizeof(Rodovia), comparar);
    for(int i = 1; i <= cidades; i++){
        pai[i] = i;
        tamanho[i] = 0;
    }
    for(int i = 0; i < rodovias; i++){
        int u = lista[i].cidade1;
        int v = lista[i].cidade2;
        int c = lista[i].custo;
        if(encontrar(u) != encontrar(v)){
            unir(u, v);
            custo_total += c;
            arestas_usadas++;
            if(arestas_usadas == cidades - 1) break;
        }
    }
    printf("%d\n", custo_total);
    return 0;
}
