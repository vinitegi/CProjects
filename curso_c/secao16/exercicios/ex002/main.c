#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p, qntd = 3, qntd_novo;

    p = (int *)calloc(qntd, sizeof(int));
    if (p == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    printf("Quantos numeros serao inseridos? ");
    scanf("%i", &qntd_novo);

    if (qntd_novo > qntd) {
        p = (int *)realloc(p, qntd_novo * sizeof(int));
        if (p == NULL) {
            printf("Erro ao redimensionar memoria!\n");
            return 1;
        }
    }

    for (int i = 0; i < qntd_novo; i++) {
        printf("Digite o valor de p[%i]: ", i);
        scanf("%i", &p[i]);
    }

    printf("\nValores armazenados:\n");
    for (int i = 0; i < qntd_novo; i++) {
        printf("p[%i] = %i\n", i, p[i]);
    }

    free(p);
    p = NULL;

    return 0;
}
