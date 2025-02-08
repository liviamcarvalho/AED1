#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 1000

typedef struct {
    int dados[MAX];
    int topo;
} Pilha;

void inicializarPilha(Pilha *p){
  p->topo = -1;
}
bool pilhaVazia(Pilha *p){
  return p->topo == -1;
}
void empilhar(Pilha *p, int x){
  if (p->topo < MAX - 1) p->dados[++p->topo] = x;
}
int desempilhar(Pilha *p){
  return p->dados[p->topo--];
}

typedef struct {
    int dados[MAX];
    int frente, tras;
} Fila;

void inicializarFila(Fila *f){
  f->frente = f->tras = 0;
}
bool filaVazia(Fila *f){
  return f->frente == f->tras;
}
void enfileirar(Fila *f, int x){
  if (f->tras < MAX) f->dados[f->tras++] = x;
}
int desenfileirar(Fila *f){
  return f->dados[f->frente++];
}

typedef struct {
    int dados[MAX];
    int tamanho;
} FilaPrioridade;

void inicializarFilaPrioridade(FilaPrioridade *fp){
  fp->tamanho = 0;
}
bool filaPrioridadeVazia(FilaPrioridade *fp){
  return fp->tamanho == 0;
}
void inserir(FilaPrioridade *fp, int x){
  fp->dados[fp->tamanho++] = x;
}
int removerMax(FilaPrioridade *fp){
    int indiceMax = 0;
    for(int i = 1; i < fp->tamanho; i++){
        if(fp->dados[i] > fp->dados[indiceMax]) indiceMax = i;
    }
    int valorMax = fp->dados[indiceMax];
    fp->dados[indiceMax] = fp->dados[--fp->tamanho];
    return valorMax;
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        Pilha p; Fila f;
        FilaPrioridade fp;
        inicializarPilha(&p);
        inicializarFila(&f);
        inicializarFilaPrioridade(&fp);
        bool ehPilha = true, ehFila = true, ehFilaPrioridade = true;
        for(int i = 0; i < n; i++){
            int operacao, x;
            scanf("%d %d", &operacao, &x);
            if(operacao == 1){
                empilhar(&p, x);
                enfileirar(&f, x);
                inserir(&fp, x);
            } else {
                if(pilhaVazia(&p) || desempilhar(&p) != x) ehPilha = false;
                if(filaVazia(&f) || desenfileirar(&f) != x) ehFila = false;
                if(filaPrioridadeVazia(&fp) || removerMax(&fp) != x) ehFilaPrioridade = false;
            }
        }
        if(ehPilha + ehFila + ehFilaPrioridade > 1) printf("not sure\n");
        else if(ehPilha) printf("stack\n");
        else if(ehFila) printf("queue\n");
        else if(ehFilaPrioridade) printf("priority queue\n");
        else printf("impossible\n");
    }
    return 0;
}
