#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p, qntd = 5;

    p = (int*)calloc(qntd, sizeof(int));

    for (int i = 0; i < 5; i++) {
        printf("Digite o valor de p[%i]: \n", i);
            scanf("%i", &p[i]);
    }

    for (int i = 0; i < 5; i++) {
        printf("O valor de p[%i]: %i \n", i, p[i]);
    }

    free(p);
    p = NULL;
    return 0;
}