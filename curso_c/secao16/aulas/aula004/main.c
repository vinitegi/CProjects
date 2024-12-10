#include <stdio.h>
#include <stdlib.h>

int main() {

    int *p, linhas = 3, colunas = 3;

    p = (int*)malloc(sizeof(int) * linhas * colunas);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            p[i * colunas + j] = 3 * i + j;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%i\n", p[i * colunas + j]);
        }
    }
    free(p);
    p = NULL;
    return 0;
}