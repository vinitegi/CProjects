#include <stdio.h>

int busca_linear(int vetor[], int chave, int tam) {
    int contador = 0;
    for(int i = 0; i < tam; i++) {
        if (vetor[i] == chave) {
            return i;
        }
        contador++;
    }

    return -1;
}

int main(void) {
    //vetor ordenado
    int vetor[6] = {1, 3, 5, 8, 12, 42};

    //elemento que sera buscado
    int chave = 12;


    //aplicando a busca binaria
    int ret = busca_linear(vetor, chave, 6);
    printf("O elemento %d esta na posicao %d", chave, ret);
    return 0;
}
