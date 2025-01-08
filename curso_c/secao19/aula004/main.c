#include <stdio.h>

void shell_sort(int vetor[], int tam) {
    int grupo = 1;

    //gerar o tamanho do grupo de acordo com o tamanmho do vetor
    while (grupo < tam) {
        grupo = 3 * grupo + 1;
    }

        //varrer o vetor enquanto houver grupos para ordenar
        while (grupo > 1) {
            //dividir grupo em 3 partes
            grupo /= 3;
            //varremos cada grupo
            for (int i = grupo; i < tam; i++) {
                int troca = vetor[i];
                int j = i - grupo;
                //realiza a troca
                while (j >= 0 && troca < vetor[j]) {
                    vetor[j + grupo] = vetor[j];
                    j -= grupo;
                }
                //realiza a troca
                vetor[j + grupo] = troca;
            }
        }
    }



int main(void) {
    int vetor[6] = {8, 3, 1, 42, 12, 5};

    shell_sort(vetor, 6);

    for (int i = 0; i < 6; i++) {
        printf("%i\n", vetor[i]);
    }

    return 0;
}