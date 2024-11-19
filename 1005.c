#include <stdio.h>

int main() {
    float A, B, pesoA, pesoB, soma, MEDIA;
    scanf("%f", &A);
    scanf("%f", &B);
    pesoA = 3.5 * A;
    pesoB = 7.5 * B;
    soma = pesoA + pesoB;
    MEDIA = soma / 11;
    printf("MEDIA = %.5f\n", MEDIA);
}
