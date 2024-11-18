#include <stdio.h>

int main() {
    int i = 0;
    int p = 0;
    int numero;

        printf("Digite um numero positivo:\n");
            scanf("%i", &numero);

        if (numero % 2 == 0) {
            p = numero;
            printf("O numero eh par\n");
        } else {
            i = numero;
            printf("O numero eh impar\n");
        }

    printf("i = %i\n p = %i", i, p);
    return 0;
}
