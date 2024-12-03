#include <stdio.h>

int fatorial(int n) {
    if (n == 1 || n == 0) {
        return 1;
    }
    return n * fatorial(n - 1);
}

int main() {
    int n;

    printf("Digite o seu fatorial: ");
        scanf("%i", &n);

    if (n < 0) {
        printf("O fatorial nao eh definido para numeros negativos.\n");
    } else {
        printf("%i! vale: %i\n", n, fatorial(n));
    }

    return 0;
}