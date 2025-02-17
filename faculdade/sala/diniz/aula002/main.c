#include <stdio.h>

int main(void) {
    int vetor[11]= {10, 9, 5, 11, 7, 3, 4, 20, 0, 1, 10};
    int auxi;

    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j <= 10; j++) {
            if (vetor[i] > vetor[j] && i < j) {
                auxi = vetor[i];
                vetor [i] = vetor[j];
                vetor[j] = auxi;
            }
        }
    }

    return 0;
}