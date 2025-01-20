#include <stdio.h>

int main() {
    int x, y, bauencontrado = 0, mapainvalido = 0;

    // Leitura das dimens�es do mapa
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

    // Inicializa��o de todas as posi��es como n�o visitadas
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            visitados[i][j] = 0;
        }
    }

    // Posi��o inicial (canto superior esquerdo)
    int linha = 0, coluna = 0;
    char direcao = '.';  // Dire��o inicial � inv�lida

    // Processamento da busca pelo ba�
    while (!bauencontrado && !mapainvalido) {

        // Verifica se saiu dos limites do mapa
        if (linha < 0 || linha >= y || coluna < 0 || coluna >= x) {
            mapainvalido = 1;
            break;
        }

        // Verifica se a posi��o foi visitada mais de uma vez
        if (visitados[linha][coluna] > 0 && mapa[linha][coluna] != '.') {
            mapainvalido = 1;
            break;
        }

        // Marca a posi��o como visitada
        visitados[linha][coluna]++;

        // Verifica se encontrou o ba�
        if (mapa[linha][coluna] == '*') {
            bauencontrado = 1;
            break;
        }

        // Atualiza a dire��o de movimento
        if (mapa[linha][coluna] == '>') direcao = '>';
        if (mapa[linha][coluna] == 'v') direcao = 'v';
        if (mapa[linha][coluna] == '^') direcao = '^';
        if (mapa[linha][coluna] == '<') direcao = '<';

        // Se a dire��o for inv�lida ou ponto (.), falha
        if (direcao == '.') {
            mapainvalido = 1;
            break;
        }

        // Atualiza a posi��o com base na dire��o
        switch (direcao) {
            case '>': coluna++; break;
            case 'v': linha++; break;
            case '^': linha--; break;
            case '<': coluna--; break;
        }
    }

    // Resultado final
    if (bauencontrado) {
        printf("*\n");  // Encontrou o ba�
    } else {
        printf("!\n");  // Mapa inv�lido
    }

    return 0;
}
