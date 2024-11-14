#include <stdio.h>

int main() {
    int valor_inteiro = 1;
    float valor_real = 1.10;
    char valor_char = 103;

    int* ponteiro_inteiro;
    float* ponteiro_real;
    char* ponteiro_char;

    printf("Valor inteiro antes: %i\n", valor_inteiro);
    printf("Valor real antes: %2.f\n", valor_real);
    printf("Valor char antes: %i ou %c\n", valor_char, valor_char);

    ponteiro_inteiro = &valor_inteiro;
    ponteiro_real = &valor_real;
    ponteiro_char = &valor_char;

    printf("Valor inteiro depois: %i\n", valor_inteiro);
    printf("Valor real depois: %2.f\n", valor_real);
    printf("Valor char depois: %i ou %c\n", valor_char, valor_char);

    printf("O endereco de memoria do valor inteiro eh: %p\n", ponteiro_inteiro);
    printf("O endereco de memoria do valor real eh: %p\n", ponteiro_real);
    printf("O endereco de memoria do valor char eh: %p\n", ponteiro_char);

    printf("O endereco de memoria do valor inteiro eh: %p\n", &valor_inteiro);
    printf("O endereco de memoria do valor real eh: %p\n", &valor_real);
    printf("O endereco de memoria do valor char eh: %p\n", &valor_char);


    return 0;
}