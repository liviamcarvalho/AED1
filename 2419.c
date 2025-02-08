#include <stdio.h>
#define MAX 1000

int main(){
    int M, N;
    char mapa[MAX][MAX];
    scanf("%d %d", &M, &N);
    for(int i = 0; i < M; i++){
        scanf("%s", mapa[i]);
    }
    int costa = 0;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(mapa[i][j] == '#'){
                if(i == 0 || i == M-1 || j == 0 || j == N-1 || mapa[i-1][j] == '.' || mapa[i+1][j] == '.' || mapa[i][j-1] == '.' || mapa[i][j+1] == '.'){
                    costa++;
                }
            }
        }
    }
    printf("%d\n", costa);
    return 0;
}
