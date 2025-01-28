#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula{
    char nome[50];
    struct celula *seg;
} celula;

celula *criarCelula(char *nome){
    celula *novaCelula = (celula*)malloc(sizeof(celula));
    strcpy(novaCelula->nome, nome);
    novaCelula->seg = NULL;
    return novaCelula;
}

celula *inserirFim(celula *cabeca, char *nome){
    celula *novaCelula = criarCelula(nome);
    if(cabeca == NULL){
        return novaCelula;
    }
    celula *atual = cabeca;
    while(atual->seg != NULL){
        atual = atual->seg;
    }
    atual->seg = novaCelula;
    return cabeca;
}

celula *inserirAntes(celula *cabeca, char *nome, char *amigoAlvo){
    celula *novaCelula = criarCelula(nome);
    if(cabeca == NULL || strcmp(cabeca->nome, amigoAlvo) == 0){
        novaCelula->seg = cabeca;
        return novaCelula;
    }
    celula *atual = cabeca;
    celula *anterior = NULL;
    while(atual != NULL && strcmp(atual->nome, amigoAlvo) != 0){
        anterior = atual;
        atual = atual->seg;
    }
    if(atual != NULL){
        anterior->seg = novaCelula;
        novaCelula->seg = atual;
    }
    return cabeca;
}

void imprimirLista(celula *cabeca){
    celula *atual = cabeca;
    while(atual != NULL){
        printf("%s", atual->nome);
        if(atual->seg != NULL){
            printf(" ");
        }
        atual = atual->seg;
    }
    printf("\n");
}

int main(){
    celula *listaAmigos = NULL;
    char listaAtual[1000], novosAmigos[1000], amigoIndicado[50];
    char *token;
    fgets(listaAtual, sizeof(listaAtual), stdin);
    listaAtual[strcspn(listaAtual, "\n")] = 0;
    token = strtok(listaAtual, " ");
    while(token != NULL){
        listaAmigos = inserirFim(listaAmigos, token);
        token = strtok(NULL, " ");
    }
    fgets(novosAmigos, sizeof(novosAmigos), stdin);
    novosAmigos[strcspn(novosAmigos, "\n")] = 0;
    fgets(amigoIndicado, sizeof(amigoIndicado), stdin);
    amigoIndicado[strcspn(amigoIndicado, "\n")] = 0;
    token = strtok(novosAmigos, " ");
    if(strcmp(amigoIndicado, "nao") == 0){
        while(token != NULL){
            listaAmigos = inserirFim(listaAmigos, token);
            token = strtok(NULL, " ");
        }
    } else {
        while(token != NULL){
            listaAmigos = inserirAntes(listaAmigos, token, amigoIndicado);
            token = strtok(NULL, " ");
        }
    }
    imprimirLista(listaAmigos);
    celula *atual = listaAmigos;
    while(atual != NULL){
        celula *temp = atual;
        atual = atual->seg;
        free(temp);
    }
    return 0;
}
