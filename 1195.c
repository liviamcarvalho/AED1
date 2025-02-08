#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esquerda, *direita;
} No;

No* criarNo(int valor){
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->esquerda = novoNo->direita = NULL;
    return novoNo;
}

No* inserir(No* raiz, int valor){
    if (raiz == NULL) return criarNo(valor);
    if(valor < raiz->valor){
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else {
        raiz->direita = inserir(raiz->direita, valor);
    }
    return raiz;
}

void preOrdem(No* raiz){
    if(raiz != NULL){
        printf("%d", raiz->valor);
        if(raiz->esquerda){
            printf(" ");
            preOrdem(raiz->esquerda);
        }
        if(raiz->direita){
            printf(" ");
            preOrdem(raiz->direita);
        }
    }
}

void emOrdem(No* raiz){
    if(raiz != NULL){
        emOrdem(raiz->esquerda);
        if(raiz->esquerda) printf(" ");
        printf("%d", raiz->valor);
        if(raiz->direita){
            printf(" ");
            emOrdem(raiz->direita);
        }
    }
}

void posOrdem(No* raiz){
    if(raiz != NULL){
        posOrdem(raiz->esquerda);
        if(raiz->esquerda) printf(" ");
        posOrdem(raiz->direita);
        if(raiz->direita) printf(" ");
        printf("%d", raiz->valor);
    }
}

void liberarArvore(No* raiz){
    if(raiz != NULL){
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}

int main(){
    int C, N, valor;
    scanf("%d", &C);
    for(int i = 1; i <= C; i++){
        No* raiz = NULL;
        scanf("%d", &N);
        for(int j = 0; j < N; j++){
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
        }
        printf("Case %d:\n", i);
        printf("Pre.: ");
        preOrdem(raiz);
        printf("\n");
        printf("In..: ");
        emOrdem(raiz);
        printf("\n");
        printf("Post: ");
        posOrdem(raiz);
        printf("\n\n");
        liberarArvore(raiz);
    }

    return 0;
}
