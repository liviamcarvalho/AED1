#include <stdio.h>
#include <math.h>

int main(){
    int N, M;
    int inscritos[30];
    int soma = 0, dias = 0;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < 30; i++){
        scanf("%d", &inscritos[i]);
        soma += inscritos[i];
    }
    while(N < M){
        int novo_inscrito = (int)ceil(soma / 30.0);
        N += novo_inscrito;
        soma -= inscritos[0];
        for (int i = 0; i < 29; i++){
            inscritos[i] = inscritos[i + 1];
        }
        inscritos[29] = novo_inscrito;
        soma += novo_inscrito;
        dias++;
    }
    printf("%d\n", dias);
    return 0;
}
