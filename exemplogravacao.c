#include <stdio.h>
#include <stdlib.h>

    /**************************
    *                         *
    * Livia de Moura Carvalho *
    *                         *
    *    Exemplo gravação     *
    *                         *
    *   Descrição: Arquivos   *
    *                         *
    **************************/

int main(void) {
    FILE *arq; // cria variável ponteiro para o arquivo
    char palavra[20]; // variável do tipo string

    // abre o arquivo com tipo de abertura w
    arq = fopen("arquivo_palavra.txt", "w");

    // testa se o arquivo realmente foi criado
    if(arq == NULL){
        printf("Erro na abertura do arquivo!");
        return 1;
    }
    printf("Escreva uma palavra para gravar no arquivo: ");
    scanf("%s", palavra);

    // usa fprintf para armazenar a string no arquivo
    fprintf(arq, "%s", palavra);

    // usa fclose para fechar o arquivo
    fclose(arq);
    printf("Dados gravados com sucesso!");
    return 0;
}
