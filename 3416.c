#include <stdio.h>

int main(){
    int N, L, D, total_cafe_necessario, capacidade_litros_ml, preparacoes;
    scanf("%d %d %d", &N, &L, &D);
    total_cafe_necessario = N * D;
    capacidade_litros_ml = L * 1000;
    preparacoes = (total_cafe_necessario + capacidade_litros_ml - 1) / capacidade_litros_ml;
    printf("%d\n", preparacoes * L);
    return 0;
}
