#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char valor;
    struct No* esquerda;
    struct No* direita;
} No;

No* criarNo(char valor){
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

No* inserir(No* raiz, char valor){
    if (raiz == NULL) {
        return criarNo(valor);
    }
    if(valor < raiz->valor){
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else if(valor > raiz->valor){
        raiz->direita = inserir(raiz->direita, valor);
    }
    return raiz;
}

void percursoInfixo(No* raiz, int* primeiro){
    if(raiz != NULL){
        percursoInfixo(raiz->esquerda, primeiro);
        if(*primeiro){
            printf("%c", raiz->valor);
            *primeiro = 0;
        } else {
            printf(" %c", raiz->valor);
        }
        percursoInfixo(raiz->direita, primeiro);
    }
}

void percursoPrefixo(No* raiz, int* primeiro){
    if(raiz != NULL){
        if(*primeiro){
            printf("%c", raiz->valor);
            *primeiro = 0;
        } else {
            printf(" %c", raiz->valor);
        }
        percursoPrefixo(raiz->esquerda, primeiro);
        percursoPrefixo(raiz->direita, primeiro);
    }
}

void percursoPosfixo(No* raiz, int* primeiro){
    if(raiz != NULL){
        percursoPosfixo(raiz->esquerda, primeiro);
        percursoPosfixo(raiz->direita, primeiro);
        if(*primeiro){
            printf("%c", raiz->valor);
            *primeiro = 0;
        } else {
            printf(" %c", raiz->valor);
        }
    }
}

void pesquisar(No* raiz, char valor){
    No* atual = raiz;
    while(atual != NULL){
        if(valor == atual->valor){
            printf("%c existe\n", valor);
            return;
        }
        if(valor < atual->valor){
            atual = atual->esquerda;
        } else {
            atual = atual->direita;
        }
    }
    printf("%c nao existe\n", valor);
}

void liberarArvore(No* raiz){
    if(raiz != NULL){
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}

int main(){
    No* raiz = NULL;
    char comando[10];
    char valor;
    int primeiro;
    while(scanf("%s", comando) != EOF){
        if(strcmp(comando, "I") == 0){
            scanf(" %c", &valor);
            raiz = inserir(raiz, valor);
        }
        else if(strcmp(comando, "INFIXA") == 0){
            primeiro = 1;
            percursoInfixo(raiz, &primeiro);
            printf("\n");
        }
        else if(strcmp(comando, "PREFIXA") == 0){
            primeiro = 1;
            percursoPrefixo(raiz, &primeiro);
            printf("\n");
        }
        else if(strcmp(comando, "POSFIXA") == 0){
            primeiro = 1;
            percursoPosfixo(raiz, &primeiro);
            printf("\n");
        }
        else if(strcmp(comando, "P") == 0){
            scanf(" %c", &valor);
            pesquisar(raiz, valor);
        }
    }
    liberarArvore(raiz);
    return 0;
}
