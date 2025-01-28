#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula{
    char conteudo;
    struct celula *proximo;
} celula;

typedef struct{
    celula *topo;
} Pilha;

void inicializaPilha(Pilha *pilha){
    pilha->topo = NULL;
}

int estaVazia(Pilha *pilha){
    return pilha->topo == NULL;
}

void empilha(Pilha *pilha, char conteudo){
    celula *novacelula = (celula*)malloc(sizeof(celula));
    if (novacelula == NULL){
        exit(1);
    }
    novacelula->conteudo = conteudo;
    novacelula->proximo = pilha->topo;
    pilha->topo = novacelula;
}

char desempilha(Pilha *pilha){
    if(estaVazia(pilha)){
        return '\0';
    }
    celula *noTemp = pilha->topo;
    char conteudo = noTemp->conteudo;
    pilha->topo = noTemp->proximo;
    free(noTemp);
    return conteudo;
}

void liberaPilha(Pilha *pilha){
    while(!estaVazia(pilha)){
        desempilha(pilha);
    }
}

int expressaoValida(const char *expressao){
    Pilha pilha;
    inicializaPilha(&pilha);
    for(int i = 0; expressao[i] != '\0'; i++){
        if(expressao[i] == '('){
            empilha(&pilha, '(');
        }
        else if(expressao[i] == ')'){
            if(estaVazia(&pilha)){
                liberaPilha(&pilha);
                return 0;
            }
            desempilha(&pilha);
        }
    }
    int resultado = estaVazia(&pilha);
    liberaPilha(&pilha);
    return resultado;
}

int main(){
    char expressao[1001];
    while(fgets(expressao, sizeof(expressao), stdin) != NULL){
        size_t tamanho = strlen(expressao);
        if(tamanho > 0 && expressao[tamanho-1] == '\n'){
            expressao[tamanho-1] = '\0';
        }
        if(strlen(expressao) == 0){
            continue;
        }
        if(expressaoValida(expressao)){
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }
    return 0;
}
