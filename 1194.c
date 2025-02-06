#include <stdio.h>
#include <string.h>

int encontrarIndice(char *infixo, char raiz, int inicio, int fim){
    for(int i = inicio; i <= fim; i++){
        if(infixo[i] == raiz){
            return i;
        }
    }
    return -1;
}

void gerarPosfixo(char *prefixo, char *infixo, int inicio, int fim, int *indiceRaiz){
    if(inicio > fim) return;
    char raiz = prefixo[(*indiceRaiz)++];
    int indice = encontrarIndice(infixo, raiz, inicio, fim);
    gerarPosfixo(prefixo, infixo, inicio, indice - 1, indiceRaiz);
    gerarPosfixo(prefixo, infixo, indice + 1, fim, indiceRaiz);
    putchar(raiz);
}

int main(){
    int casos;
    scanf("%d", &casos);
    while(casos--){
        int n, indiceRaiz = 0;
        char prefixo[53], infixo[53];
        scanf("%d %s %s", &n, prefixo, infixo);
        gerarPosfixo(prefixo, infixo, 0, n - 1, &indiceRaiz);
        putchar('\n');
    }
    return 0;
}
