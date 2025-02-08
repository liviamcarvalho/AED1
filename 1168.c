#include <stdio.h>
#include <string.h>

int leds_por_digito[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main(){
    int n;
    scanf("%d", &n);
    while (n--){
        char valor[102];
        scanf("%s", valor);
        int total_leds = 0;
        for(int i = 0; i < strlen(valor); i++){
            total_leds += leds_por_digito[valor[i] - '0'];
        }
        printf("%d leds\n", total_leds);
    }
    return 0;
}
