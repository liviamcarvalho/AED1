#include <stdio.h>
#include <math.h>
#define EPSILON 0.000001

int numerosIguais(double a, double b){
    return fabs(a - b) < EPSILON;
}

int verificarEquilibrio(double pesos[4]){
    for(int i = 0; i < (1 << 4); i++){
        double pesoEsquerda = 0.0;
        double pesoDireita = 0.0;
        for(int j = 0; j < 4; j++){
            if(i & (1 << j)){
                pesoEsquerda += pesos[j];
            } else {
                pesoDireita += pesos[j];
            }
        }
        if(numerosIguais(pesoEsquerda, pesoDireita)){
            return 1;
        }
    }
    return 0;
}

int main(){
    double pesos[4];
    for(int i = 0; i < 4; i++){
        scanf("%lf", &pesos[i]);
    }
    if(verificarEquilibrio(pesos)){
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
