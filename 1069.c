#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    char dado;
    struct No *prox;
} No;

typedef struct{
    No *topo;
} Pilha;

void inicializar(Pilha *p){
    p->topo = NULL;
}

void empilhar(Pilha *p, char c){
    No *novo = (No *)malloc(sizeof(No));
    if(!novo) return;
    novo->dado = c;
    novo->prox = p->topo;
    p->topo = novo;
}

char desempilhar(Pilha *p){
    if(p->topo == NULL) return 0;
    No *temp = p->topo;
    char dado = temp->dado;
    p->topo = temp->prox;
    free(temp);
    return dado;
}

int contar_diamantes(const char *linha){
    Pilha pilha;
    inicializar(&pilha);
    int diamantes = 0;
    for(int i = 0; linha[i] != '\0'; i++){
        if(linha[i] == '<'){
            empilhar(&pilha, '<');
        } else if(linha[i] == '>' && pilha.topo){
            desempilhar(&pilha);
            diamantes++;
        }
    }
    return diamantes;
}

int main(){
    int N;
    scanf("%d", &N);
    getchar();
    while(N--){
        char linha[1001];
        fgets(linha, sizeof(linha), stdin);
        printf("%d\n", contar_diamantes(linha));
    }
    return 0;
}
