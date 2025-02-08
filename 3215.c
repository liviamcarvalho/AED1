#include <stdio.h>
#include <stdlib.h>
#define MAX_N 10000

int parent[MAX_N], balance[MAX_N];

int find(int x){
    if(parent[x] != x){
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unite(int x, int y){
    int rootX = find(x);
    int rootY = find(y);
    if(rootX != rootY){
        parent[rootY] = rootX;
        balance[rootX] += balance[rootY];
    }
}

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
        scanf("%d", &balance[i]);
        parent[i] = i;
    }
    for(int i = 0; i < M; i++){
        int X, Y;
        scanf("%d %d", &X, &Y);
        unite(X, Y);
    }
    for(int i = 0; i < N; i++){
        if(find(i) == i && balance[i] != 0){
            printf("IMPOSSIBLE\n");
            return 0;
        }
    }
    printf("POSSIBLE\n");
    return 0;
}
