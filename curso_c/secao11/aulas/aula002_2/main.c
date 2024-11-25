#include <stdio.h>

int main() {
    FILE *arq;
    int num, soma = 0;

    arq = fopen("arquivo.txt", "r");

    if(arq) {
        while (!feof(arq)) {
            int resultado = fscanf(arq, "%d", &num);
            if (resultado == 1) {
            soma += num;
            }
        }
    }else {
        printf("Arquivo nao encontrado!\n");
    }
    printf("a soma dos numeros encontrados eh: %i", soma);
    fclose(arq);
    return 0;
}
