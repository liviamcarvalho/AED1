#include <stdio.h>
int verificamatriz(int mat[9][9]){
    //verifica as linhas
    for(int i = 0; i < 9; i++){
        int usado[10] = {0};
        for(int j = 0; j < 9; j++){
            if(mat[i][j] < 1 || mat[i][j] > 9 || usado[mat[i][j]]) return 0;
            usado[mat[i][j]] = 1;
        }
    }
    //verifica as colunas
    for(int j = 0; j < 9; j++){
        int usado[10] = {0};
        for(int i = 0; i < 9; i++){
            if(mat[i][j] < 1 || mat[i][j] > 9 || usado[mat[i][j]]) return 0;
            usado[mat[i][j]] = 1;
        }
    }
    // verifica os blocos
    for(int blocoi = 0; blocoi <3; blocoi ++){
        for(int blocoj = 0; blocoj < 3; blocoj ++){
            int usado[10] = {0};
            for(int i = blocoi * 3; i < (blocoi * 3) + 3; i++){
                for(int j = blocoj * 3; j < (blocoj * 3) + 3; j++){
                    if(usado[mat[i][j]]) return 0;
                    usado[mat[i][j]] = 1;
                }
            }
        }
    }
}
int main(){
    int k, sudoku[9][9];
    do scanf("%d", &k);
    while(k < 1);
    for(int m = 0; m < k; m ++){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                scanf("%d", &sudoku[i][j]);
            }
        }
        printf("Instancia %d\n", m + 1);
        if(verificamatriz(sudoku) == 0) printf("NAO\n\n");
        else printf("SIM\n\n");
    }
    return 0;
}
