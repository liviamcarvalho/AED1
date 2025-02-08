#include <stdio.h>
#include <string.h>

int main(){
    char d, numero[101];
    while (1){
        scanf(" %c %s", &d, numero);
        if(d == '0' && strcmp(numero, "0") == 0){
            break;
        }
        char resultado[101];
        int j = 0;
        for(int i = 0; numero[i] != '\0'; i++){
            if(numero[i] != d){
                resultado[j++] = numero[i];
            }
        }
        resultado[j] = '\0';
        if(j == 0){
            printf("0\n");
        } else {
            int inicio = 0;
            while(resultado[inicio] == '0'){
                inicio++;
            }
            if (inicio == j){
                printf("0\n");
            } else {
                printf("%s\n", resultado + inicio);
            }
        }
    }
    return 0;
}
