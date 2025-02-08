#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_N 2000

int grafo[MAX_N][MAX_N];
int grafoT[MAX_N][MAX_N];
int visitado[MAX_N];
int N, M;

void dfs(int v, int grafo[MAX_N][MAX_N]){
    visitado[v] = 1;
    for(int i = 1; i <= N; i++){
        if(grafo[v][i] && !visitado[i]){
            dfs(i, grafo);
        }
    }
}

int verifica_conectividade(){
    memset(visitado, 0, sizeof(visitado));
    dfs(1, grafo);
    for(int i = 1; i <= N; i++){
        if(!visitado[i]) return 0;
    }
    memset(visitado, 0, sizeof(visitado));
    dfs(1, grafoT);
    for(int i = 1; i <= N; i++){
        if(!visitado[i]) return 0;
    }
    return 1;
}

int main(){
    while(1){
        scanf("%d %d", &N, &M);
        if(N == 0 && M == 0) break;
        memset(grafo, 0, sizeof(grafo));
        memset(grafoT, 0, sizeof(grafoT));
        for(int i = 0; i < M; i++){
            int V, W, P;
            scanf("%d %d %d", &V, &W, &P);
            grafo[V][W] = 1;
            grafoT[W][V] = 1;
            if(P == 2){
                grafo[W][V] = 1;
                grafoT[V][W] = 1;
            }
        }
        printf("%d\n", verifica_conectividade());
    }
    return 0;
}
