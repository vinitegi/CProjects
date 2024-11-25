#include <stdio.h>

int main() {
    FILE *arq;
    char fruta[10];

    arq = fopen("frutas.txt", "w"); //write -> escritra

    if (arq) {
        printf("Informe uma fruta, ou pressione 0 para sair: \n");
        fgets(fruta, 10, stdin);
        while (fruta[0] != '0') {
            fputs(fruta, arq);
            printf("Informe uma fruta, ou pressione 0 para sair\n");
            fgets(fruta, 10, stdin);
        }
    } else {
        printf("arquivo nao encontrado");
    }

    fclose(arq);


    return 0;
}

/*PRINCIPAIS MODOs DE ABERTURA DOS ARQUIVOS
 * "r" -> leitura
 * "w" -> escrita com sobreposição de conteudo
 * "a" -> escrita com adição de conteudo
 */
