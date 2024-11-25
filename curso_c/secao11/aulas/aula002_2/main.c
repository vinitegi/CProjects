#include <stdio.h>

int main() {
    FILE *arq;
    int num, resultado, soma = 0;

    arq = fopen("arquivo.txt", "r");

    if(arq) {
        while (!feof(arq)) {
            fscanf(arq, "%d", &num);
            soma += num;
        }
    }else {
        printf("Arquivo nao encontrado!");
    }
    printf("a soma dos numeros encontrados eh: %i", soma);
    fclose(arq);
    return 0;
}
