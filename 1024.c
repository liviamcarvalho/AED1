#include <stdio.h>
#include <string.h>
#define MAX_M 1000

void passo1(char *linha){
    for(int i = 0; linha[i] != '\0'; i++){
        if((linha[i] >= 'A' && linha[i] <= 'Z') || (linha[i] >= 'a' && linha[i] <= 'z')){
            linha[i] += 3;
        }
    }
}

void passo2(char *linha){
    int len = strlen(linha);
    for(int i = 0; i < len / 2; i++){
        char temp = linha[i];
        linha[i] = linha[len - 1 - i];
        linha[len - 1 - i] = temp;
    }
}

void passo3(char *linha){
    int len = strlen(linha);
    for(int i = len / 2; i < len; i++){
        linha[i] -= 1;
    }
}

int main(){
    int N;
    char linha[MAX_M + 1];
    scanf("%d", &N);
    getchar();
    while(N--){
        fgets(linha, MAX_M, stdin);
        linha[strcspn(linha, "\n")] = '\0';
        passo1(linha);
        passo2(linha);
        passo3(linha);
        printf("%s\n", linha);
    }
    return 0;
}
