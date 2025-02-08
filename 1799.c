#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_PONTOS 4000
#define INF INT_MAX

typedef struct {
    char nome[21];
} Ponto;

int grafo[MAX_PONTOS][MAX_PONTOS];
Ponto pontos[MAX_PONTOS];
int num_pontos = 0;

int encontrarIndice(char *nome){
    for(int i = 0; i < num_pontos; i++){
        if(strcmp(pontos[i].nome, nome) == 0){
            return i;
        }
    }
    strcpy(pontos[num_pontos].nome, nome);
    return num_pontos++;
}

int dijkstra(int origem, int destino){
    int dist[MAX_PONTOS], visitado[MAX_PONTOS] = {0};
    for(int i = 0; i < num_pontos; i++){
        dist[i] = INF;
    }
    dist[origem] = 0;
    for(int i = 0; i < num_pontos; i++){
        int u = -1;
        for(int j = 0; j < num_pontos; j++){
            if(!visitado[j] && (u == -1 || dist[j] < dist[u])){
                u = j;
            }
        }
        if(dist[u] == INF) break;
        visitado[u] = 1;
        for(int v = 0; v < num_pontos; v++){
            if(grafo[u][v] && dist[u] + 1 < dist[v]){
                dist[v] = dist[u] + 1;
            }
        }
    }
    return dist[destino];
}

int main(){
    int P, L;
    scanf("%d %d", &P, &L);
    for(int i = 0; i < MAX_PONTOS; i++){
        for(int j = 0; j < MAX_PONTOS; j++){
            grafo[i][j] = 0;
        }
    }
    char ponto1[21], ponto2[21];
    for(int i = 0; i < L; i++){
        scanf("%s %s", ponto1, ponto2);
        int idx1 = encontrarIndice(ponto1);
        int idx2 = encontrarIndice(ponto2);
        grafo[idx1][idx2] = 1;
        grafo[idx2][idx1] = 1;
    }
    int entrada = encontrarIndice("Entrada");
    int saida = encontrarIndice("Saida");
    int queijo = encontrarIndice("*");
    int caminho1 = dijkstra(entrada, queijo);
    int caminho2 = dijkstra(queijo, saida);
    printf("%d\n", caminho1 + caminho2);
    return 0;
}
