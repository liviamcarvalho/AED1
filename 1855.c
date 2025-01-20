#include <stdio.h>

int main() {
    int x, y, bauencontrado = 0, mapainvalido = 0;

    // Leitura das dimensões do mapa
    do scanf("%d", &x);
    while(x < 1 || x > 100);
    do scanf("%d", &y);
    while(y < 1 || y > 100);

    // Definindo o mapa e a matriz para marcar visitados
    char mapa[y][x];
    int visitados[y][x];

    // Leitura do mapa
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            scanf(" %c", &mapa[i][j]);
        }
    }

    // Inicialização de todas as posições como não visitadas
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            visitados[i][j] = 0;
        }
    }

    // Posição inicial (canto superior esquerdo)
    int linha = 0, coluna = 0;
    char direcao = '.';  // Direção inicial é inválida

    // Processamento da busca pelo baú
    while (!bauencontrado && !mapainvalido) {

        // Verifica se saiu dos limites do mapa
        if (linha < 0 || linha >= y || coluna < 0 || coluna >= x) {
            mapainvalido = 1;
            break;
        }

        // Verifica se a posição foi visitada mais de uma vez
        if (visitados[linha][coluna] > 0 && mapa[linha][coluna] != '.') {
            mapainvalido = 1;
            break;
        }

        // Marca a posição como visitada
        visitados[linha][coluna]++;

        // Verifica se encontrou o baú
        if (mapa[linha][coluna] == '*') {
            bauencontrado = 1;
            break;
        }

        // Atualiza a direção de movimento
        if (mapa[linha][coluna] == '>') direcao = '>';
        if (mapa[linha][coluna] == 'v') direcao = 'v';
        if (mapa[linha][coluna] == '^') direcao = '^';
        if (mapa[linha][coluna] == '<') direcao = '<';

        // Se a direção for inválida ou ponto (.), falha
        if (direcao == '.') {
            mapainvalido = 1;
            break;
        }

        // Atualiza a posição com base na direção
        switch (direcao) {
            case '>': coluna++; break;
            case 'v': linha++; break;
            case '^': linha--; break;
            case '<': coluna--; break;
        }
    }

    // Resultado final
    if (bauencontrado) {
        printf("*\n");  // Encontrou o baú
    } else {
        printf("!\n");  // Mapa inválido
    }

    return 0;
}
