#include <stdio.h>

void selec_sort(int vetor[], int tam) {
    int menor, troca;

    for (int i = 0; i < tam - 1; i++) {
        menor = i;
        for (int j = (i + 1); j < tam; j++) {
            if (vetor[j] < vetor[menor]) {
                menor = j;
            }
        }
        if (i != menor) {
            troca = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = troca;
        }
    }

}

int main(void) {
    int vetor[6] = {8, 3, 1, 42, 12, 5};

    selec_sort(vetor, 6);

    for (int i = 0; i < 6; i++) {
        printf("%i\n", vetor[i]);
    }


    return 0;
}
