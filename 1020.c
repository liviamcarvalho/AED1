#include <stdio.h>

int main(){
    int idadeemdias, anos = 0, meses = 0, dias = 0, i;
    scanf("%d", &idadeemdias);
    anos = idadeemdias / 365;
    idadeemdias %= 365;
    meses = idadeemdias / 30;
    idadeemdias %= 30;
    dias = idadeemdias;
    printf("%d ano(s)\n", anos);
    printf("%d mes(es)\n", meses);
    printf("%d dia(s)\n", dias);
    return 0;
}
