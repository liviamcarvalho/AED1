#include <stdio.h>
#include <stdlib.h>
#define MAX 40000

typedef struct {
  int x, y, z;
} Aresta;

int parent[MAX], rank[MAX];

int find(int v){
  if(parent[v] != v){
    parent[v] = find(parent[v]);
  return parent[v];
}

void union_sets(int a, int b){
  a = find(a);
  b = find(b);
  if(a != b){
    if(rank[a] < rank[b])
      parent[a] = b;
    else if(rank[a] > rank[b])
      parent[b] = a;
    else {
      parent[b] = a;
      rank[a]++;
    }
  }
}

int cmp(const void *a, const void *b){
  return ((Aresta *)a)->z - ((Aresta *)b)->z;
}

int main(){
  int M, N;
  while (1){
    scanf("%d %d", &M, &N);
    if(M == 0 && N == 0) break;
    Aresta arestas[N];
    for(int i = 0; i < M; i++){
        parent[i] = i;
        rank[i] = 0;
    }
    for(int i = 0; i < N; i++)
      scanf("%d %d %d", &arestas[i].x, &arestas[i].y, &arestas[i].z);
    qsort(arestas, N, sizeof(Aresta), cmp);
    int custo_total = 0, arestas_selecionadas = 0;
    for(int i = 0; i < N && arestas_selecionadas < M - 1; i++){
      int u = arestas[i].x;
      int v = arestas[i].y;
      int w = arestas[i].z;
      if(find(u) != find(v)){
        union_sets(u, v);
        custo_total += w;
        arestas_selecionadas++;
      }
    }
    printf("%d\n", custo_total);
  }
  return 0;
}
