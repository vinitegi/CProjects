#include <stdio.h>

int main(void) {
    int m[3][3];
    int soma = 0;

    // Entrada de dados
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Digite o valor de m[%i][%i]: ", i, j);
            scanf("%i", &m[i][j]);
        }
    }

    // Impressão da matriz
    printf("\nMatriz digitada:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("[%i] ", m[i][j]);
        }
        printf("\n");
    }

    // Cálculo da soma da diagonal principal
    for (int i = 0; i < 3; i++) {
        soma += m[i][i];
    }

    printf("\nA soma da diagonal principal é: %i\n", soma);
    return 0;
}
