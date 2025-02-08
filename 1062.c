#include <stdio.h>
#define MAX_N 1000

int verifica_permutacao(int n, int saida[]){
    int pilha[MAX_N], topo = -1, proximo = 1;
    for(int i = 0; i < n; i++){
        while(proximo <= saida[i]){
            pilha[++topo] = proximo++;
        }
        if(pilha[topo] == saida[i]){
            topo--;
        } else {
            return 0;
        }
    }
    return 1;
}

int main(){
    int n;
    while(scanf("%d", &n) && n){
        while(1){
            int saida[MAX_N];
            scanf("%d", &saida[0]);
            if(saida[0] == 0){
                printf("\n");
                break;
            }
            for(int i = 1; i < n; i++){
                scanf("%d", &saida[i]);
            }
            printf(verifica_permutacao(n, saida) ? "Yes\n" : "No\n");
        }
    }
    return 0;
}
