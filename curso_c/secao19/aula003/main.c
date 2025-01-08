#include <stdio.h>

void bubble_sort(int vetor[], int tam) {
    int proximo;

    //varrer todo o vetor externo
    for (int i = 0; i < tam; i++) {
        //trabalhar com os proximos elementos
        for (int j = 0; j < tam - 1; j++) {
            //ocorre a troca
            if (vetor[j] > vetor[j + 1]) {
                proximo = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = proximo;
            }

        }
    }
}


int main(void) {
    int vetor[6] = {8, 3, 1, 42, 12, 5};

    bubble_sort(vetor, 6);

    for (int i = 0; i < 6; i++) {
        printf("%i\n", vetor[i]);
    }


    return 0;
}