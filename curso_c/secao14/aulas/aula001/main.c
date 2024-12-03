#include <stdio.h>

//ifndef - diretiva de compilacao

#ifndef PI//se a constante nao foi definida em nenhum lugar, defina ela
    #define PI 3.14159265 //constante
#endif



int main() {

    int valor = 5;

    printf("O valor eh: %i\n", valor);
    printf("O valor de PI eh: %.4f\n", PI);

    return 0;
}