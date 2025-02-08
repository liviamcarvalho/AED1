#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_N 10000
#define MAX_C 100

typedef struct {
    int destino, peso;
} Aresta;

typedef struct {
    Aresta arestas[MAX_N];
    int tamanho;
} ListaAdjacencia;

ListaAdjacencia grafo[MAX_N + 1];
int impostos[MAX_N + 1];
int capacidade;
long long distancia_total = 0;

void adicionar_aresta(int a, int b, int c){
    grafo[a].arestas[grafo[a].tamanho].destino = b;
    grafo[a].arestas[grafo[a].tamanho].peso = c;
    grafo[a].tamanho++;
    grafo[b].arestas[grafo[b].tamanho].destino = a;
    grafo[b].arestas[grafo[b].tamanho].peso = c;
    grafo[b].tamanho++;
}

int dfs(int no, int pai){
    int carga_atual = impostos[no];
    for(int i = 0; i < grafo[no].tamanho; i++){
        int vizinho = grafo[no].arestas[i].destino;
        int peso = grafo[no].arestas[i].peso;
        if(vizinho == pai) continue;
        int carga_subarvore = dfs(vizinho, no);
        int viagens = (carga_subarvore + capacidade - 1) / capacidade;
        distancia_total += 2LL * viagens * peso;
        carga_atual += carga_subarvore;
    }
    return carga_atual;
}

int main(){
    int N;
    scanf("%d %d", &N, &capacidade);
    for(int i = 1; i <= N; i++){
        scanf("%d", &impostos[i]);
    }
    for(int i = 1; i < N; i++){
        int A, B, C;
        scanf("%d %d %d", &A, &B, &C);
        adicionar_aresta(A, B, C);
    }
    dfs(1, -1);
    printf("%lld\n", distancia_total);
    return 0;
}
