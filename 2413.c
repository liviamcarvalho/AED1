#include <stdio.h>
 
int main() {
    int t, prim;
    do scanf("%d", &t);
    while(t < 1 || t > 1000);
    prim = 4 * t;
    printf("%d\n", prim);
    return 0;
}
