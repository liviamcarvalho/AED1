#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int chave;
    struct No *proximo;
} No;

No *criarNo(int chave){
    No *novoNo = (No*)malloc(sizeof(No));
    novoNo->chave = chave;
    novoNo->proximo = NULL;
    return novoNo;
}

void inserir(No *tabela[], int M, int chave){
    int indice = chave % M;
    No *novoNo = criarNo(chave);
    if(tabela[indice] == NULL){
        tabela[indice] = novoNo;
    } else {
        No *temp = tabela[indice];
        while(temp->proximo != NULL){
            temp = temp->proximo;
        }
        temp->proximo = novoNo;
    }
}

void imprimirTabela(No *tabela[], int M){
    for(int i = 0; i < M; i++){
        printf("%d ->", i);
        No *temp = tabela[i];
        while(temp != NULL){
            printf(" %d ->", temp->chave);
            temp = temp->proximo;
        }
        printf(" \\\n");
    }
}

void liberarTabela(No *tabela[], int M){
    for(int i = 0; i < M; i++){
        No *temp = tabela[i];
        while(temp != NULL){
            No *paraLiberar = temp;
            temp = temp->proximo;
            free(paraLiberar);
        }
    }
}

int main(){
    int N;
    scanf("%d", &N);
    for(int t = 0; t < N; t++){
        int M, C;
        scanf("%d %d", &M, &C);
        No *tabela[M];
        for(int i = 0; i < M; i++){
            tabela[i] = NULL;
        }
        for(int i = 0; i < C; i++){
            int chave;
            scanf("%d", &chave);
            inserir(tabela, M, chave);
        }
        imprimirTabela(tabela, M);
        liberarTabela(tabela, M);
        if(t < N - 1){
            printf("\n");
        }
    }
    return 0;
}
