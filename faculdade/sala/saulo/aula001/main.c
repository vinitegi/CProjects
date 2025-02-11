#include <stdio.h>

int main(void) {
    int m[3][3];
    int soma = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Digite o valor de m[%i][%i]:\n", i, j);
                scanf("%i", &m[i][j]);
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("[%i] ", m[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) {
                soma += m[i][j];
            }
        }
    }

    return 0;
}