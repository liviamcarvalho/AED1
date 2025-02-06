#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define INFINITO 100000
#define MAX_CIDADES 250

typedef struct No{
    int cidade, custo;
    struct No *proximo;
} No;

typedef struct Grafo{
    No *adjacencias;
} Grafo;

Grafo *criar_grafo(int);
No *criar_no(int, int);
void dijkstra(Grafo *, int, int, int *);
void adicionar_aresta(Grafo *, int, int, int);

Grafo *criar_grafo(int tamanho){
    int i;
    Grafo *g = (Grafo *)malloc(sizeof(Grafo));
    g->adjacencias = (No *)malloc(sizeof(No) * (tamanho + 1));
    for(i = 0; i < tamanho; ++i){
        g->adjacencias[i].proximo = NULL;
    }
    return g;
}

No *criar_no(int cidade, int custo){
    No *novo_no = (No *)malloc(sizeof(No));
    novo_no->cidade = cidade;
    novo_no->custo = custo;
    novo_no->proximo = NULL;
    return novo_no;
}

void adicionar_aresta(Grafo *g, int origem, int destino, int custo){
    No *novo_no = criar_no(origem, custo);
    novo_no->proximo = g->adjacencias[destino].proximo;
    g->adjacencias[destino].proximo = novo_no;
}

void dijkstra(Grafo *g, int origem, int tamanho, int *distancias){
    No *atual;
    int i, j, cidade_atual;
    bool visitado[MAX_CIDADES] = {false};
    for(i = 0; i < tamanho; ++i){
        distancias[i] = INFINITO;
    }
    distancias[origem] = 0;
    for(i = 0; i < tamanho; ++i){
        cidade_atual = -1;
        for(j = 0; j < tamanho; ++j){
            if(!visitado[j] && (cidade_atual == -1 || distancias[j] < distancias[cidade_atual]))
                cidade_atual = j;
        }
        if(distancias[cidade_atual] == INFINITO){
            break;
        }
        visitado[cidade_atual] = true;
        for(atual = g->adjacencias[cidade_atual].proximo; atual != NULL; atual = atual->proximo){
            int destino = atual->cidade;
            int custo = atual->custo;
            if(distancias[cidade_atual] + custo < distancias[destino]){
                distancias[destino] = distancias[cidade_atual] + custo;
            }
        }
    }
}

int main(){
    int i, cidades, estradas, rota, inicio, origem, destino, custo, distancias[MAX_CIDADES];
    while(scanf("%d %d %d %d", &cidades, &estradas, &rota, &inicio), (cidades && estradas && rota && inicio)){
        Grafo *grafo = criar_grafo(cidades + 1);
        for(i = 0; i < estradas; ++i){
            scanf("%d %d %d", &origem, &destino, &custo);
            if(origem >= rota && destino >= rota || ((origem < rota) && (destino < rota) && (abs(origem - destino) == 1))){
                adicionar_aresta(grafo, origem, destino, custo), adicionar_aresta(grafo, destino, origem, custo);
            }
            if(origem >= rota && destino < rota){
                adicionar_aresta(grafo, destino, origem, custo);
            }
            if(destino >= rota && origem < rota){
                adicionar_aresta(grafo, origem, destino, custo);
            }
        }
        dijkstra(grafo, inicio, cidades, distancias);
        printf("%d\n", distancias[rota - 1]);
    }
    return 0;
}
