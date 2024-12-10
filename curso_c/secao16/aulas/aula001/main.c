#include <stdio.h>
#include <stdlib.h>

int main() {

    int qntd, *p;

    printf("Insira a quantidade de valores:");
    scanf("%i", &qntd);

    int bytes = qntd * sizeof(int);

    p = (int*)malloc(bytes);


    for (int i = 0; i < qntd; i++) {
        printf("Informe  valor da posicao %i no vetor:\n", i);
        scanf("%i", &p[i]);
    }

    for (int j = 0; j < qntd; j++) {
        printf("A variavel 'numero[%i]' vale %i\n", j,p[j]);
    }

    printf("A variavel 'p' ocupa %ld bytes em memoria", bytes);

    //liberar a memoria (desalocar)
    free(p);
    p = NULL; //medida de seguranca
    return 0;
}