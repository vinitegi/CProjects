#include <stdio.h>

int main() {
    FILE *arq;

    //fopen(nome-do-arquivo, forma-de-abertura)
    //w - abrir o arquivo para escrita (se o arquivo ja existir, sera sobrescrito)
    //r - abrir o arquivo para leitura (nao sera possivel escrever no arquivo)
    // - abrir o arquivo para adicao de conteudo novo (se o arquivo ja existir, sera adicionado um conteudo novo)
    arq = fopen("arquivo.txt", "w");

    //sempre que a gente finalizar a manipulacao de um arquivo, devemos fecha-lo
    fclose(arq);
    return 0;
}
