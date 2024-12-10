#include <stdio.h>
#include <stdlib.h>

//Realoc -> realocacao de memoria

//Necessario um malloc ou calloc anteriormente

int main() {

    int qntd, *p;

    printf("Insira a quantidade de valores:");
    scanf("%i", &qntd);


    p = (int*)calloc(qntd, sizeof(int));

    if (p){
        printf("A variavel 'p' ocupa %lld bytes em memoria", qntd * sizeof(int));

        printf("Insira a quantidade de valores para ser realocado:");
        scanf("%i", &qntd);

        p = (int*)realloc(p, qntd * sizeof(int));

        if (p) {
            printf("A variavel 'p' ocupa %lld bytes em memoria", qntd * sizeof(int));
        } else {
            printf("Erro: Memoria insuficiente!");
        }

    } else {
        printf("Erro: Memoria insuficiente!");
    }


    //liberar a memoria (desalocar)
    free(p);
    p = NULL; //medida de seguranca
    return 0;
}