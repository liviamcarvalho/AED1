#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_VERTICES 26

int visitado[MAX_VERTICES], V, E, tam;
int grafo[MAX_VERTICES][MAX_VERTICES];
char vertices[MAX_VERTICES];

void dfs(int v){
    visitado[v] = 1;
    vertices[tam++] = v;
    for(int i = 0; i < V; i++){
        if(grafo[v][i] && !visitado[i]){
            dfs(i);
        }
    }
}

int compara(const void *a, const void *b){
    return (*(char *)a - *(char *)b);
}

int main(){
    int N;
    scanf("%d", &N);
    for(int caso = 1; caso <= N; caso++){
        scanf("%d %d", &V, &E);
        memset(grafo, 0, sizeof(grafo));
        memset(visitado, 0, sizeof(visitado));
        for(int i = 0; i < E; i++){
            char u, v;
            scanf(" %c %c", &u, &v);
            grafo[u - 'a'][v - 'a'] = 1;
            grafo[v - 'a'][u - 'a'] = 1;
        }
        printf("Case #%d:\n", caso);
        int componentes = 0;
        for(int i = 0; i < V; i++){
            if(!visitado[i]){
                tam = 0;
                dfs(i);
                qsort(vertices, tam, sizeof(char), compara);
                for(int j = 0; j < tam; j++){
                    printf("%c,", vertices[j] + 'a');
                }
                printf("\n");
                componentes++;
            }
        }
        printf("%d connected components\n\n", componentes);
    }
    return 0;
}
