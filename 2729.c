#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000
#define TAM_MAX 21

// Estrutura para os nós da lista encadeada
typedef struct Celula {
    char item[TAM_MAX];
    struct Celula *prox;
} Celula;

// Função para criar uma nova célula
Celula* criaCelula(char *item) {
    Celula *novaCelula = (Celula*)malloc(sizeof(Celula));
    strcpy(novaCelula->item, item);
    novaCelula->prox = NULL;
    return novaCelula;
}

// Função para inserir um item em ordem alfabética na lista encadeada, evitando duplicatas
void insereOrdenado(Celula **inicio, char *item) {
    Celula *novaCelula = criaCelula(item);
    Celula *atual = *inicio;
    Celula *anterior = NULL;

    // Verifica se o item já está na lista
    while (atual != NULL && strcmp(atual->item, item) < 0) {
        anterior = atual;
        atual = atual->prox;
    }
    if (atual != NULL && strcmp(atual->item, item) == 0) {
        free(novaCelula); // Item duplicado, não adiciona
        return;
    }

    // Inserir o item no local apropriado
    if (anterior == NULL) {
        novaCelula->prox = *inicio;
        *inicio = novaCelula;
    } else {
        anterior->prox = novaCelula;
        novaCelula->prox = atual;
    }
}

// Função para liberar a lista encadeada
void liberaLista(Celula *inicio) {
    Celula *atual = inicio;
    while (atual != NULL) {
        Celula *temp = atual;
        atual = atual->prox;
        free(temp);
    }
}

// Função para imprimir a lista de compras formatada
void imprimeLista(Celula *inicio) {
    Celula *atual = inicio;
    int primeiro = 1;
    while (atual != NULL) {
        if (!primeiro) printf(" ");
        printf("%s", atual->item);
        primeiro = 0;
        atual = atual->prox;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    getchar(); // Limpa o buffer

    for (int i = 0; i < n; i++) {
        char entrada[MAX * TAM_MAX];
        fgets(entrada, sizeof(entrada), stdin);
        
        Celula *inicio = NULL;
        
        char *token = strtok(entrada, " \n");
        while (token != NULL) {
            insereOrdenado(&inicio, token);
            token = strtok(NULL, " \n");
        }

        imprimeLista(inicio);
        liberaLista(inicio);
    }

    return 0;
}
