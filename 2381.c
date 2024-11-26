#include <stdio.h>
#include <string.h>
#define MAX_N 100
#define MAX_TAM_NOME 20

int main() {
    int N, K;
    char alunos[MAX_N][MAX_TAM_NOME + 1]; // Matriz para armazenar os nomes dos alunos
    char temp[MAX_TAM_NOME + 1]; // Vari�vel auxiliar para a troca na ordena��o
    // L� N e K
    scanf("%d %d", &N, &K);
    // L� os nomes dos alunos
    for (int i = 0; i < N; i++) {
        scanf("%s", alunos[i]);
    }
    // Ordena os nomes em ordem alfab�tica usando Bubble Sort
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (strcmp(alunos[j], alunos[j + 1]) > 0) {
                // Troca os nomes de posi��o
                strcpy(temp, alunos[j]);
                strcpy(alunos[j], alunos[j + 1]);
                strcpy(alunos[j + 1], temp);
            }
        }
    }
    // Imprime o K-�simo aluno
    printf("%s\n", alunos[K - 1]);
    return 0;
}
