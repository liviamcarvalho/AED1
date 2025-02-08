#include <stdio.h>
#include <stdlib.h>
#define MODULO 1000007

typedef struct No{
    int valor;
    struct No *proximo;
} No;

typedef struct {
    No *frente, *tras;
    int tamanho;
    int soma;
} Fila;

void inicializarFila(Fila *fila){
    fila->frente = fila->tras = NULL;
    fila->tamanho = 0;
    fila->soma = 0;
}

void enfileirar(Fila *fila, int valor){
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = NULL;
    if(fila->tras == NULL){
        fila->frente = fila->tras = novo;
    } else {
        fila->tras->proximo = novo;
        fila->tras = novo;
    }
    fila->soma = (fila->soma + valor) % MODULO;
    fila->tamanho++;
}

void desenfileirar(Fila *fila){
    if(fila->frente == NULL) return;
    No *temp = fila->frente;
    fila->frente = fila->frente->proximo;
    fila->soma = (fila->soma - temp->valor + MODULO) % MODULO;
    free(temp);
    fila->tamanho--;
    if(fila->frente == NULL) fila->tras = NULL;
}

int calcularFibonacki(int k, int N){
    if(N <= k) return N - 1;
    Fila fila;
    inicializarFila(&fila);
    for(int i = 0; i < k; i++){
        enfileirar(&fila, i);
    }
    int resultado;
    for(int i = k; i < N; i++){
        resultado = fila.soma;
        enfileirar(&fila, resultado);
        desenfileirar(&fila);
    }
    resultado = fila.tras->valor;
    return resultado;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int k, N;
        scanf("%d %d", &k, &N);
        printf("%d\n", calcularFibonacki(k, N));
    }
    return 0;
}
