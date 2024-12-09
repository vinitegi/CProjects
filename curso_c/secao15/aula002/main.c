#include <stdio.h>
#include <stdlib.h> //<------ FOCO
#include <string.h>
#include <time.h>

/*  <STDLIB.H>
 *
 *=========== CONVERSAO DE STRINGS ===========
 *      atof() -> converte string para double
 *      atoi() -> converte string para inteiro
 *      atol() -> converte string para double longo
 *
 *=========== GERACAO DE SEQUENCIA PSEUDO-ALEATORIA ===========
 *      rand() -> gera numeros aleatorios
 *      srand() -> inicializa o gerador de numeros aleatorios
 *
 *=========== GERENCIAMENTO DE MEMORIA DINAMICA ===========
 *      malloc()
 *      calloc()
 *      free()
 *      realoc()
 *
 *=========== PESQUISA E ORDENACAO ===========
 *      qsort() -> ordena os elementos de um array
 *
 *=========== ARITMETICA DE INTEIROS ===========
 *      abs() -> valor absoluto
 *      div() -> divisao inteira
 *
 */


int compara(const int *x,  const *y) { //=========== PESQUISA E ORDENACAO ===========
    if (*x > *y) {
        return 1;
    } else if (*x == *y) {
        return 0;
    } else {
        return -1;
    }

}

int main() {

    printf("=========== CONVERSAO DE STRINGS ===========\n");

    char valor_s1[5];
    double valor_d;

    char valor_s2[5];
    int valor_i;

    char valor_s3[50];
    double valor_l;

    strcpy(valor_s1, "4.5");
    valor_d = atof(valor_s1);

    printf("O valor eh: %.2f", valor_d);

    printf("\n=============================================\n");

    strcpy(valor_s2, "4");
    valor_i = atoi(valor_s2);

    printf("O valor eh: %i", valor_i);

    printf("\n=============================================\n");

    strcpy(valor_s3, "281898103");
    valor_l = atol(valor_s3);

    printf("O valor eh: %lf", valor_l);

    printf("\n\n");

    printf("=========== GERACAO DE SEQUENCIA PSEUDO-ALEATORIA ===========\n");

    time_t t;

    //inicializando o gerador
    srand((unsigned) time(&t));

    for (int i = 0; i < 6; i++) { //gerar 6 numeros entre 0 e 60 -> rand()
        if (i == 5) {
            printf("%i. ", rand() % 61);
        } else {
            printf("%i, ", rand() % 61);
        }
    }

    printf("\n\n");

    printf("=========== PESQUISA E ORDENACAO ===========\n");

    int numeros[] = {6, 2, 9, 3, 7, 1, 5};

    qsort(numeros, 7, sizeof(int), (void *)compara);

    for (int i = 0; i < 7; i++) {
        if (i == 6){
            printf("%i. ", numeros[i]);
        } else {
        printf("%i, ", numeros[i]);

    }
    }

    printf("\n\n");

    printf("=========== ARITMETICA DE INTEIROS ===========\n");

    int valor_a, valor_b;

    valor_a = abs(5);
    valor_b = abs(-10);

    printf("O valor absoluto de 5 eh %i\n", valor_a);
    printf("O valor absoluto de -10 eh %i", valor_b);

    printf("\n=============================================\n");

    div_t saida;
    saida = div(27, 4);
    printf("O quociente de (27/4) vale %d\n", saida.quot);
    printf("O resto de (27/4) vale %d\n", saida.rem);

    printf("\n");

    saida = div(27, 3);
    printf("O quociente de (27/3) vale %d\n", saida.quot);
    printf("O resto de (27/3) vale %d\n", saida.rem);



    return 0;
}