#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *esquerda, *direita;
} No;

No *criar_no(int valor){
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->esquerda = novo->direita = NULL;
    return novo;
}

No *inserir(No *raiz, int valor){
    if(raiz == NULL) return criar_no(valor);
    if(valor < raiz->valor)
        raiz->esquerda = inserir(raiz->esquerda, valor);
    else
        raiz->direita = inserir(raiz->direita, valor);
    return raiz;
}

typedef struct FilaNo{
    No *no;
    struct FilaNo *proximo;
} FilaNo;

typedef struct {
    FilaNo *frente, *tras;
} Fila;

void inicializar_fila(Fila *fila){
    fila->frente = fila->tras = NULL;
}

void enfileirar(Fila *fila, No *no){
    FilaNo *novo = (FilaNo*)malloc(sizeof(FilaNo));
    novo->no = no;
    novo->proximo = NULL;
    if(fila->tras)
        fila->tras->proximo = novo;
    fila->tras = novo;
    if(!fila->frente)
        fila->frente = novo;
}

No *desenfileirar(Fila *fila){
    if(!fila->frente) return NULL;
    FilaNo *temp = fila->frente;
    No *no = temp->no;
    fila->frente = temp->proximo;
    if(!fila->frente)
        fila->tras = NULL;
    free(temp);
    return no;
}

int fila_vazia(Fila *fila){
    return fila->frente == NULL;
}

void bfs(No *raiz){
    if(!raiz) return;
    Fila fila;
    inicializar_fila(&fila);
    enfileirar(&fila, raiz);
    int primeiro = 1;
    while(!fila_vazia(&fila)){
        No *atual = desenfileirar(&fila);
        if(!primeiro) printf(" ");
        printf("%d", atual->valor);
        primeiro = 0;
        if(atual->esquerda) enfileirar(&fila, atual->esquerda);
        if(atual->direita) enfileirar(&fila, atual->direita);
    }
    printf("\n");
}

int main(){
    int C;
    scanf("%d", &C);
    for(int caso = 1; caso <= C; caso++){
        int N;
        scanf("%d", &N);
        No *raiz = NULL;
        for(int i = 0; i < N; i++){
            int valor;
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
        }
        printf("Case %d:\n", caso);
        bfs(raiz);
        printf("\n");
    }
    return 0;
}
