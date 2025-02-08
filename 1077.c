#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM_MAX 301
#define TAM_PILHA 301

typedef struct {
    char itens[TAM_PILHA];
    int topo;
} Pilha;

void inicializarPilha(Pilha *p){
    p->topo = -1;
}

void empilhar(Pilha *p, char valor){
    p->itens[++(p->topo)] = valor;
}

char desempilhar(Pilha *p){
    return p->itens[(p->topo)--];
}

char topoPilha(Pilha *p){
    return p->itens[p->topo];
}

int pilhaVazia(Pilha *p){
    return p->topo == -1;
}

int prioridade(char operador){
    switch(operador){
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

void converterParaPosfixa(char *expressaoInfixa, char *expressaoPosfixa){
    Pilha pilhaOperadores;
    inicializarPilha(&pilhaOperadores);
    int i, j = 0;
    int tamanho = strlen(expressaoInfixa);
    for(i = 0; i < tamanho; i++){
        char caractereAtual = expressaoInfixa[i];
        if(isalnum(caractereAtual)){
            expressaoPosfixa[j++] = caractereAtual;
        }
        else if(caractereAtual == '('){
            empilhar(&pilhaOperadores, caractereAtual);
        }
        else if(caractereAtual == ')'){
            while(!pilhaVazia(&pilhaOperadores) && topoPilha(&pilhaOperadores) != '('){
                expressaoPosfixa[j++] = desempilhar(&pilhaOperadores);
            }
            if(!pilhaVazia(&pilhaOperadores)){
                desempilhar(&pilhaOperadores);
            }
        }
        else if(strchr("+-*/^", caractereAtual)){
            while(!pilhaVazia(&pilhaOperadores) && topoPilha(&pilhaOperadores) != '(' && prioridade(topoPilha(&pilhaOperadores)) >= prioridade(caractereAtual)){
                expressaoPosfixa[j++] = desempilhar(&pilhaOperadores);
            }
            empilhar(&pilhaOperadores, caractereAtual);
        }
    }
    
    while(!pilhaVazia(&pilhaOperadores)){
        expressaoPosfixa[j++] = desempilhar(&pilhaOperadores);
    }
    expressaoPosfixa[j] = '\0';
}

int main(){
    int numCasos;
    char expressaoInfixa[TAM_MAX];
    char expressaoPosfixa[TAM_MAX];
    scanf("%d", &numCasos);
    getchar();
    while(numCasos--){
        scanf("%s", expressaoInfixa);
        converterParaPosfixa(expressaoInfixa, expressaoPosfixa);
        printf("%s\n", expressaoPosfixa);
    }
    return 0;
}
