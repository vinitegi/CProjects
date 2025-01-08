#include <stdio.h>

void merge(int vetor[], int inicio1 ,int fim1, int inicio2, int fim2) {
    //vetor temporario para realizar o merge
    int temp[50];
    //variaveis auxiliares
    int i, j, k;
    //inicio do primeiro grupo
    i = inicio1;
    //inicio do segundo grupo
    j = inicio2;
    k = 0;

    //enquanto tiver elementos em amos s grupo
    while (i <= fim1 && j <= fim2) {
        //fasz a ordenacao de acordo com cada grupo
        if (vetor[i] < vetor[j]) {
            temp[k++] = vetor[i++];
        }else {
            temp[k++] = vetor[j++];
        }
    }
    //copia os elementos restantes do primeiro grupo
    while (i <= fim1) {
        temp[k++] = vetor[i++];
    }

    //copia os elementos restantes do segundo grupo
    while (j <= fim2) {
        temp[k++] = vetor[j++];
    }

    //transfere os elementos do vetor temporario para op original

    for (i = inicio1, j = 0; i <= fim2; i++, j++) {
        vetor[i] = temp[j];

    }
}

void merge_sort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        //calcular o meio do vetor
        int meio = (inicio + fim) / 2;

        //recursao esquerda
        merge_sort(vetor, inicio, meio);

        //recursao direita
        merge_sort(vetor, meio+1, fim);

        //faz o merge
        merge(vetor, inicio, meio, meio + 1, fim);
    }
}

int main(void) {
    int vetor[6] = {8, 3, 1, 42, 12, 5};

    merge_sort(vetor, 0, 6 - 1);

    for (int i = 0; i < 6; i++) {
        printf("%i\n", vetor[i]);
    }
    return 0;
}