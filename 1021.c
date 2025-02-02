#include <stdio.h>

int main(){
    double N;
    int valor, moedas, notas[] = {100, 50, 20, 10, 5, 2}, valores_moedas[] = {100, 50, 25, 10, 5, 1};
    scanf("%lf", &N);
    valor = (int)N;
    moedas = (int)((N - valor) * 100 + 0.5);
    printf("NOTAS:\n");
    for (int i = 0; i < 6; i++) {
        printf("%d nota(s) de R$ %d.00\n", valor / notas[i], notas[i]);
        valor %= notas[i];
    }
    moedas += valor * 100;
    printf("MOEDAS:\n");
    for (int i = 0; i < 6; i++) {
        printf("%d moeda(s) de R$ %.2f\n", moedas / valores_moedas[i], valores_moedas[i] / 100.0);
        moedas %= valores_moedas[i];
    }
    return 0;
}
