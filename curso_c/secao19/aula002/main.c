#include <stdio.h>

void insert_sort(int vetor[], int tam) {
    int troca;

    //para percorrer todo o vetor
    for (int i = 1; i < tam; i++) {
        int proximo = i;

        //responsavel pelas trocas
        while (proximo != 0 && (vetor[proximo] < vetor[proximo - 1])) {
            troca = vetor[proximo];
            vetor[proximo] = vetor[proximo - 1];
            vetor[proximo - 1] = troca;
            proximo--;
        }
    }
}



int main(void) {
    int vetor[6] = {8, 3, 1, 42, 12, 5};

    insert_sort(vetor, 6);

    for (int i = 0; i < 6; i++) {
        printf("%i\n", vetor[i]);
    }


    return 0;
}