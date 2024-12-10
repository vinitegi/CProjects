#include <stdio.h>
#include <stdlib.h>


//malloc -> nao zera os espacos em memoria, ou seja, pode causar bugs
//passa um paramentros -> p = (int*)malloc(3 * sizeof(int));


//calloc -> zera os espacos em memoria
//passa dois parametros -> p = (int*)calloc(qntd, sizeof(int));

int main() {

    int qntd, *p;

    printf("Insira a quantidade de valores:");
    scanf("%i", &qntd);


    p = (int*)calloc(qntd, sizeof(int));

    if (p){
    printf("A variavel 'p' ocupa %lld bytes em memoria", qntd * sizeof(int));
    } else {
        printf("Erro: Memoria insuficiente!");
    }


    //liberar a memoria (desalocar)
    free(p);
    p = NULL; //medida de seguranca
    return 0;
}
