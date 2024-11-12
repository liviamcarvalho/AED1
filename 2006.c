#include <stdio.h>
 
int main() {
    int T, A, B, C, D, E, corretos = 0;
    scanf("%d\n", &T);
    scanf("%d %d %d %d %d\n", &A, &B, &C, &D, &E);
    if(A == T) corretos++;
    if(B == T) corretos++;
    if(C == T) corretos++;
    if(D == T) corretos++;
    if(E == T) corretos++;
    printf("%d\n", corretos);
    return 0;
}
