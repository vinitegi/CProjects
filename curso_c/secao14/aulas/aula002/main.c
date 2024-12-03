#include <stdio.h>

//ifndef - diretiva de compilacao

#ifndef PI//se a constante nao foi definida em nenhum lugar, defina ela
    #define PI 3.14159265 //constante
#endif



int main() {

    int valor = 5;

    printf("O valor eh: %i\n", valor);
    printf("O valor de PI x 2 eh: %.4f\n", 2 * PI);

#ifdef PI //so vai executar se a constante existir, caso contratrio, ser[a irrelevante
    printf("O valor de PI eh: %.4f\n", PI);
#endif


    return 0;
}