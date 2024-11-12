#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para as células da lista encadeada
typedef struct celula {
    char nome[50];
    struct celula *seg;
} celula;

// Função para criar uma nova célula
celula *criarCelula(char *nome) {
    celula *novaCelula = (celula*)malloc(sizeof(celula));
    strcpy(novaCelula->nome, nome);
    novaCelula->seg = NULL;
    return novaCelula;
}

// Função para inserir no fim da lista
celula *inserirFim(celula *cabeca, char *nome) {
    celula *novaCelula = criarCelula(nome);

    if (cabeca == NULL) {
        return novaCelula;
    }

    celula *atual = cabeca;
    while (atual->seg != NULL) {
        atual = atual->seg;
    }
    atual->seg = novaCelula;
    return cabeca;
}

// Função para inserir antes de um amigo específico
celula *inserirAntes(celula *cabeca, char *nome, char *amigoAlvo) {
    celula *novaCelula = criarCelula(nome);

    // Se a lista estiver vazia ou a primeira célula é o alvo
    if (cabeca == NULL || strcmp(cabeca->nome, amigoAlvo) == 0) {
        novaCelula->seg = cabeca;
        return novaCelula;
    }

    celula *atual = cabeca;
    celula *anterior = NULL;

    while (atual != NULL && strcmp(atual->nome, amigoAlvo) != 0) {
        anterior = atual;
        atual = atual->seg;
    }

    if (atual != NULL) {
        anterior->seg = novaCelula;
        novaCelula->seg = atual;
    }

    return cabeca;
}

// Função para imprimir a lista
void imprimirLista(celula *cabeca) {
    celula *atual = cabeca;
    while (atual != NULL) {
        printf("%s", atual->nome);
        if (atual->seg != NULL) {
            printf(" ");
        }
        atual = atual->seg;
    }
    printf("\n");
}

int main() {
    celula *listaAmigos = NULL;
    char listaAtual[1000], novosAmigos[1000], amigoIndicado[50];
    char *token;

    // Lendo a lista atual de amigos
    fgets(listaAtual, sizeof(listaAtual), stdin);
    listaAtual[strcspn(listaAtual, "\n")] = 0;
    token = strtok(listaAtual, " ");
    while (token != NULL) {
        listaAmigos = inserirFim(listaAmigos, token);
        token = strtok(NULL, " ");
    }

    // Lendo a nova lista de amigos
    fgets(novosAmigos, sizeof(novosAmigos), stdin);
    novosAmigos[strcspn(novosAmigos, "\n")] = 0;

    // Lendo o amigo que receberá a indicação
    fgets(amigoIndicado, sizeof(amigoIndicado), stdin);
    amigoIndicado[strcspn(amigoIndicado, "\n")] = 0;

    // Processando a nova lista de amigos
    token = strtok(novosAmigos, " ");
    if (strcmp(amigoIndicado, "nao") == 0) {
        // Inserir no fim da lista
        while (token != NULL) {
            listaAmigos = inserirFim(listaAmigos, token);
            token = strtok(NULL, " ");
        }
    } else {
        // Inserir antes do amigo indicado
        while (token != NULL) {
            listaAmigos = inserirAntes(listaAmigos, token, amigoIndicado);
            token = strtok(NULL, " ");
        }
    }

    // Imprimindo a lista final
    imprimirLista(listaAmigos);

    // Liberando a memória
    celula *atual = listaAmigos;
    while (atual != NULL) {
        celula *temp = atual;
        atual = atual->seg;
        free(temp);
    }

    return 0;
}
