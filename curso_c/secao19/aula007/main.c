#include <stdio.h>

void cria_heap(int vetor[], int inicio, int fim) {
    int pai = vetor[inicio];
    int filho = inicio * 2 + 1;

    //se o pai tem dois filhos, e qual eh o maior
    while (filho <= fim) {
        if (filho < fim) {
            if (vetor[filho] < vetor[filho + 1]) {
                filho++;
            }
        }

        //o filho eh maior que o pai?
        //se sim, o filho se torna o pai
        //repete o processo
        if (pai < vetor[filho]) {
            vetor[inicio] = vetor[filho];
            inicio = filho;
            filho = 2 * inicio + 1;
        } else {
            filho = fim + 1;
        }
    }
    //antigo pai ocupa o lugar do ultimo filho analisado
    vetor[inicio] = pai;
}

void heap_sort(int vetor[], int tam) {
    int troca;
    int meio = (tam - 1) / 2;

    //cria a heap apartir dos dados
    for (int i = meio; i >= 0; i--) {
        cria_heap(vetor, i, tam - 1);
    }

    for (int i = tam - 1; i >= 1; i--) {
        troca = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = troca;

        cria_heap(vetor, 0, i - 1);
    }
}

int main(void) {
    int vetor[6] = {8, 3, 1, 42, 12, 5};

    heap_sort(vetor, 6);

    for (int i = 0; i < 6; i++) {
        printf("%i\n", vetor[i]);
    }
    return 0;
}