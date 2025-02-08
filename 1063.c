#include <stdio.h>
#include <string.h>
#define TAM_MAX 1000

typedef struct {
    char dados[TAM_MAX];
    int topo;
} Pilha;

void inicializaPilha(Pilha *p){
    p->topo = -1;
}

void empilha(Pilha *p, char valor){
    p->dados[++(p->topo)] = valor;
}

char desempilha(Pilha *p){
    return p->dados[(p->topo)--];
}

char topoPilha(Pilha *p){
    return p->dados[p->topo];
}

int pilhaVazia(Pilha *p){
    return p->topo == -1;
}

void resolveManobras(char *entrada, char *saida_desejada, int n){
    Pilha estacao;
    char operacoes[TAM_MAX * 2];
    int pos_entrada = 0;
    int pos_saida = 0;
    int pos_operacoes = 0;
    int possivel = 1;
    inicializaPilha(&estacao);
    while(pos_saida < n && possivel){
        if(pos_entrada < n && entrada[pos_entrada] == saida_desejada[pos_saida]){
            operacoes[pos_operacoes++] = 'I';
            operacoes[pos_operacoes++] = 'R';
            pos_entrada++;
            pos_saida++;
        } else if(!pilhaVazia(&estacao) && topoPilha(&estacao) == saida_desejada[pos_saida]){
            operacoes[pos_operacoes++] = 'R';
            desempilha(&estacao);
            pos_saida++;
        } else if(pos_entrada < n){
            empilha(&estacao, entrada[pos_entrada]);
            operacoes[pos_operacoes++] = 'I';
            pos_entrada++;
        } else {
            possivel = 0;
        }
    }
    operacoes[pos_operacoes] = '\0';
    if(!possivel || pos_saida < n || !pilhaVazia(&estacao)){
        printf("%s Impossible\n", operacoes);
    } else {
        printf("%s\n", operacoes);
    }
}

int main(){
    int num_vagoes;
    char entrada[TAM_MAX], saida[TAM_MAX];
    while(1){
        scanf("%d", &num_vagoes);
        if(num_vagoes == 0) break;
        scanf(" %c", &entrada[0]);
        for(int i = 1; i < num_vagoes; i++){
            scanf(" %c", &entrada[i]);
        }
        scanf(" %c", &saida[0]);
        for(int i = 1; i < num_vagoes; i++){
            scanf(" %c", &saida[i]);
        }
        resolveManobras(entrada, saida, num_vagoes);
    }
    return 0;
}
