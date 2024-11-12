#include <stdio.h>
 
int main() {
    int N, M, dif;
    do scanf("%d", &N);
    while (N < 1 || N > 40);
    do scanf("%d", &M);
    while (M < 1 || M > 40);
    dif = N - M;
    printf("%d\n", dif);
    return 0;
}
