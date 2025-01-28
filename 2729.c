#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000
#define TAM_MAX 21

typedef struct Celula{
    char item[TAM_MAX];
    struct Celula *prox;
} Celula;

Celula* criaCelula(char *item){
    Celula *novaCelula = (Celula*)malloc(sizeof(Celula));
    strcpy(novaCelula->item, item);
    novaCelula->prox = NULL;
    return novaCelula;
}

void insereOrdenado(Celula **inicio, char *item){
    Celula *novaCelula = criaCelula(item);
    Celula *atual = *inicio;
    Celula *anterior = NULL;
    while(atual != NULL && strcmp(atual->item, item) < 0){
        anterior = atual;
        atual = atual->prox;
    }
    if(atual != NULL && strcmp(atual->item, item) == 0){
        free(novaCelula);
        return;
    }
    if(anterior == NULL){
        novaCelula->prox = *inicio;
        *inicio = novaCelula;
    } else {
        anterior->prox = novaCelula;
        novaCelula->prox = atual;
    }
}

void liberaLista(Celula *inicio){
    Celula *atual = inicio;
    while(atual != NULL){
        Celula *temp = atual;
        atual = atual->prox;
        free(temp);
    }
}

void imprimeLista(Celula *inicio){
    Celula *atual = inicio;
    int primeiro = 1;
    while(atual != NULL){
        if(!primeiro) printf(" ");
        printf("%s", atual->item);
        primeiro = 0;
        atual = atual->prox;
    }
    printf("\n");
}

int main(){
    int n;
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++){
        char entrada[MAX * TAM_MAX];
        fgets(entrada, sizeof(entrada), stdin);
        Celula *inicio = NULL;
        char *token = strtok(entrada, " \n");
        while(token != NULL){
            insereOrdenado(&inicio, token);
            token = strtok(NULL, " \n");
        }
        imprimeLista(inicio);
        liberaLista(inicio);
    }
    return 0;
}
