#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int identificador;
    struct celula *proximo;
} celula;

typedef struct{
    celula *inicio;
    celula *fim;
    int tamanho;
} Fila;

void inicializaFila(Fila *fila){
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

int estaVazia(Fila *fila){
    return fila->inicio == NULL;
}

void enfileira(Fila *fila, int identificador){
    celula *novacelula = (celula*)malloc(sizeof(celula));
    if(novacelula == NULL){
        exit(1);
    }
    novacelula->identificador = identificador;
    novacelula->proximo = NULL;
    if(estaVazia(fila)){
        fila->inicio = novacelula;
    } else {
        fila->fim->proximo = novacelula;
    }
    fila->fim = novacelula;
    fila->tamanho++;
}

void removePessoa(Fila *fila, int identificador){
    if(estaVazia(fila)){
        return;
    }
    celula *atual = fila->inicio;
    celula *anterior = NULL;
    while(atual != NULL && atual->identificador != identificador){
        anterior = atual;
        atual = atual->proximo;
    }
    if (atual != NULL){
        if(anterior == NULL){
            fila->inicio = atual->proximo;
        } else {
            anterior->proximo = atual->proximo;
        }
        if(atual->proximo == NULL){
            fila->fim = anterior;
        }
        free(atual);
        fila->tamanho--;
    }
}

void imprimeFila(Fila *fila){
    celula *atual = fila->inicio;
    while(atual != NULL){
        printf("%d", atual->identificador);
        if(atual->proximo != NULL){
            printf(" ");
        }
        atual = atual->proximo;
    }
    printf("\n");
}

void liberaFila(Fila *fila){
    celula *atual = fila->inicio;
    while(atual != NULL){
        celula *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

int main(){
    int N, M;
    Fila fila;
    inicializaFila(&fila);
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        int id;
        scanf("%d", &id);
        enfileira(&fila, id);
    }
    scanf("%d", &M);
    for(int i = 0; i < M; i++){
        int id;
        scanf("%d", &id);
        removePessoa(&fila, id);
    }
    imprimeFila(&fila);
    liberaFila(&fila);
    return 0;
}
