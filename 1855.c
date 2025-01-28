#include <stdio.h>

int main(){
    int x, y, bauencontrado = 0, mapainvalido = 0;
    do scanf("%d", &x);
    while(x < 1 || x > 100);
    do scanf("%d", &y);
    while(y < 1 || y > 100);
    char mapa[y][x];
    int visitados[y][x];
    for(int i = 0; i < y; i++){
        for(int j = 0; j < x; j++){
            scanf(" %c", &mapa[i][j]);
        }
    }
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            visitados[i][j] = 0;
        }
    }
    int linha = 0, coluna = 0;
    char direcao = '.';
    while(!bauencontrado && !mapainvalido){
        if(linha < 0 || linha >= y || coluna < 0 || coluna >= x){
            mapainvalido = 1;
            break;
        }
        if(visitados[linha][coluna] > 0 && mapa[linha][coluna] != '.'){ 
            mapainvalido = 1;
            break;
        }
        visitados[linha][coluna]++;
        if(mapa[linha][coluna] == '*'){
            bauencontrado = 1;
            break;
        }
        if(mapa[linha][coluna] == '>') direcao = '>';
        if(mapa[linha][coluna] == 'v') direcao = 'v';
        if(mapa[linha][coluna] == '^') direcao = '^';
        if(mapa[linha][coluna] == '<') direcao = '<';
        if(direcao == '.'){
            mapainvalido = 1;
            break;
        }
        switch(direcao){
            case '>': coluna++; break;
            case 'v': linha++; break;
            case '^': linha--; break;
            case '<': coluna--; break;
        }
    }
    if(bauencontrado){
        printf("*\n");
    } else {
        printf("!\n");
    }
    return 0;
}
