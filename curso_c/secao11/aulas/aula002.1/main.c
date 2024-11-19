#include <stdio.h>

int main() {
    FILE *arq;
    char nomes[10], *resultado;

    arq = fopen("arquivo.txt", "r");

    if (arq) {
        while (!feof(arq)) { //feof - file end of file
            resultado = fgets(nomes, 10, arq);
            printf("Resultado:%d\n", *resultado);
            if (resultado) {
                printf("%s\n", nomes);
            }
        }
    } else {
        printf("Nao encontrei o arquivo");
    }
    fclose(arq);
    return 0;
}
