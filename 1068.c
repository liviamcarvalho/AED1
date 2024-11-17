#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para a célula da pilha
typedef struct celula {
    char conteudo;
    struct celula *proximo;
} celula;

// Estrutura da pilha
typedef struct {
    celula *topo;
} Pilha;

// Inicializa a pilha
void inicializaPilha(Pilha *pilha) {
    pilha->topo = NULL;
}

// Verifica se a pilha está vazia
int estaVazia(Pilha *pilha) {
    return pilha->topo == NULL;
}

// Empilha um caractere
void empilha(Pilha *pilha, char conteudo) {
    celula *novacelula = (celula*)malloc(sizeof(celula));
    if (novacelula == NULL) {
        //Memoria insuficiente
        exit(1);
    }
    novacelula->conteudo = conteudo;
    novacelula->proximo = pilha->topo;
    pilha->topo = novacelula;
}

// Desempilha um caractere
char desempilha(Pilha *pilha) {
    if (estaVazia(pilha)) {
        return '\0';
    }
    celula *noTemp = pilha->topo;
    char conteudo = noTemp->conteudo;
    pilha->topo = noTemp->proximo;
    free(noTemp);
    return conteudo;
}

// Libera a memória da pilha
void liberaPilha(Pilha *pilha) {
    while (!estaVazia(pilha)) {
        desempilha(pilha);
    }
}

// Função que verifica se a expressão está correta
int expressaoValida(const char *expressao) {
    Pilha pilha;
    inicializaPilha(&pilha);

    for (int i = 0; expressao[i] != '\0'; i++) {
        if (expressao[i] == '(') {
            empilha(&pilha, '(');
        }
        else if (expressao[i] == ')') {
            if (estaVazia(&pilha)) {
                liberaPilha(&pilha);
                return 0; // Fecha parênteses sem correspondente aberto
            }
            desempilha(&pilha);
        }
    }

    int resultado = estaVazia(&pilha); // Verdadeiro se todos os parênteses foram fechados
    liberaPilha(&pilha);
    return resultado;
}

int main() {
    char expressao[1001]; // 1000 caracteres + '\0'

    // Lê as expressões até encontrar EOF
    while (fgets(expressao, sizeof(expressao), stdin) != NULL) {
        // Remove o '\n' do final da string, se existir
        size_t tamanho = strlen(expressao);
        if (tamanho > 0 && expressao[tamanho-1] == '\n') {
            expressao[tamanho-1] = '\0';
        }

        // Se a linha estiver vazia, pula
        if (strlen(expressao) == 0) {
            continue;
        }

        // Verifica a expressão e imprime o resultado
        if (expressaoValida(expressao)) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    return 0;
}
