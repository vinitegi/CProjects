#include <stdio.h>

void quick_sort(int vetor[], int tam) {
    int i, j, grupo, troca;

    //criterio de parada da recursividade
    if (tam < 2) {
        return;
    } else {
        grupo = vetor[tam/2];
    }

    //fznd um loop unico se comportar como dois
    for (i = 0, j = tam - 1;; i++, j--) {

        //fzr a movimentacao dos elementos no vetor
        while (vetor[i] < grupo) {
            i++;
        }
        while (grupo < vetor[j]) {
            j--;
        }
        //criterio de parada do loop
        if (i >= j) {
            break;
        }else {
            //trocas
            troca = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = troca;
        }
    }
    //usar a recursividade para ordenar os grupo
    quick_sort(vetor, i);
    quick_sort(vetor + i, tam - i);
}

int main(void) {
    int vetor[6] = {8, 3, 1, 42, 12, 5};

    quick_sort(vetor, 6);

    for (int i = 0; i < 6; i++) {
        printf("%i\n", vetor[i]);
    }
    return 0;
}