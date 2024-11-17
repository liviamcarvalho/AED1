#include <stdio.h>
#include <stdlib.h>

// Estrutura para a célula da fila
typedef struct celula {
    int identificador;
    struct celula *proximo;
} celula;

// Estrutura da fila
typedef struct {
    celula *inicio;
    celula *fim;
    int tamanho;
} Fila;

// Inicializa a fila
void inicializaFila(Fila *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

// Verifica se a fila está vazia
int estaVazia(Fila *fila) {
    return fila->inicio == NULL;
}

// Adiciona uma pessoa na fila
void enfileira(Fila *fila, int identificador) {
    celula *novacelula = (celula*)malloc(sizeof(celula));
    if (novacelula == NULL) {
        // Memória insuficiente
        exit(1);
    }

    novacelula->identificador = identificador;
    novacelula->proximo = NULL;

    if (estaVazia(fila)) {
        fila->inicio = novacelula;
    } else {
        fila->fim->proximo = novacelula;
    }

    fila->fim = novacelula;
    fila->tamanho++;
}

// Remove uma pessoa específica da fila
void removePessoa(Fila *fila, int identificador) {
    if (estaVazia(fila)) {
        return;
    }

    celula *atual = fila->inicio;
    celula *anterior = NULL;

    // Procura a pessoa na fila
    while (atual != NULL && atual->identificador != identificador) {
        anterior = atual;
        atual = atual->proximo;
    }

    // Se encontrou a pessoa
    if (atual != NULL) {
        // Se é o primeiro da fila
        if (anterior == NULL) {
            fila->inicio = atual->proximo;
        } else {
            anterior->proximo = atual->proximo;
        }

        // Se é o último da fila
        if (atual->proximo == NULL) {
            fila->fim = anterior;
        }

        free(atual);
        fila->tamanho--;
    }
}

// Imprime o estado atual da fila
void imprimeFila(Fila *fila) {
    celula *atual = fila->inicio;
    while (atual != NULL) {
        printf("%d", atual->identificador);
        if (atual->proximo != NULL) {
            printf(" ");
        }
        atual = atual->proximo;
    }
    printf("\n");
}

// Libera a memória utilizada pela fila
void liberaFila(Fila *fila) {
    celula *atual = fila->inicio;
    while (atual != NULL) {
        celula *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

int main() {
    int N, M;
    Fila fila;
    inicializaFila(&fila);

    // Lê o tamanho inicial da fila
    scanf("%d", &N);

    // Lê e adiciona as pessoas na fila inicial
    for (int i = 0; i < N; i++) {
        int id;
        scanf("%d", &id);
        enfileira(&fila, id);
    }

    // Lê o número de pessoas que vão sair
    scanf("%d", &M);

    // Lê e processa cada pessoa que sai
    for (int i = 0; i < M; i++) {
        int id;
        scanf("%d", &id);
        removePessoa(&fila, id);
    }

    // Imprime o estado final da fila
    imprimeFila(&fila);

    // Libera a memória
    liberaFila(&fila);

    return 0;
}
