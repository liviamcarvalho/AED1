#include <stdio.h>
#include <stdlib.h>
#define MAX_CARTAS 50

typedef struct {
    int dados[MAX_CARTAS];
    int inicio;
    int fim;
    int tamanho;
} Fila;

void inicializaFila(Fila *fila){
    fila->inicio = 0;
    fila->fim = 0;
    fila->tamanho = 0;
}

void enfileira(Fila *fila, int valor){
    fila->dados[fila->fim] = valor;
    fila->fim = (fila->fim + 1) % MAX_CARTAS;
    fila->tamanho++;
}

int desenfileira(Fila *fila){
    int valor = fila->dados[fila->inicio];
    fila->inicio = (fila->inicio + 1) % MAX_CARTAS;
    fila->tamanho--;
    return valor;
}

void processaCaso(int n){
    Fila fila;
    int cartasDescartadas[MAX_CARTAS];
    int numDescartadas = 0;
    inicializaFila(&fila);
    for(int i = 1; i <= n; i++){
        enfileira(&fila, i);
    }
    while(fila.tamanho >= 2){
        cartasDescartadas[numDescartadas++] = desenfileira(&fila);
        enfileira(&fila, desenfileira(&fila));
    }
    printf("Discarded cards: ");
    for(int i = 0; i < numDescartadas; i++){
        if(i > 0) printf(", ");
        printf("%d", cartasDescartadas[i]);
    }
    printf("\n");
    printf("Remaining card: %d\n", fila.dados[fila.inicio]);
}

int main(){
    int n;
    while(1){
        scanf("%d", &n);
        if(n == 0) break;
        processaCaso(n);
    }
    return 0;
}
