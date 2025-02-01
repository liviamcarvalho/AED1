#include <stdio.h>

int main(){
    int hi, mi, hf, mf, tmi, tmf, dm, dh, dms;
    scanf("%d %d %d %d", &hi, &mi, &hf, &mf);
    tmi = hi * 60 + mi;
    tmf = hf * 60 + mf;
    if(tmf <= tmi){
        tmf += 24 * 60;
    }
    dm = tmf - tmi;
    dh = dm / 60;
    dms = dm % 60;
    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", dh, dms);
    return 0;
}
