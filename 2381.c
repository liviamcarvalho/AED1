#include <stdio.h>
#include <string.h>
#define MAX_N 100
#define MAX_TAM_NOME 20

int main(){
    int N, K;
    char alunos[MAX_N][MAX_TAM_NOME + 1];
    char temp[MAX_TAM_NOME + 1];
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++){
        scanf("%s", alunos[i]);
    }
    for(int i = 0; i < N - 1; i++){
        for(int j = 0; j < N - i - 1; j++){
            if(strcmp(alunos[j], alunos[j + 1]) > 0){
                strcpy(temp, alunos[j]);
                strcpy(alunos[j], alunos[j + 1]);
                strcpy(alunos[j + 1], temp);
            }
        }
    }
    printf("%s\n", alunos[K - 1]);
    return 0;
}
