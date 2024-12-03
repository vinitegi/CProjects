#include <stdio.h>

/*1. Crie um programa que tenha uma função recursiva que receba um número inteiro positivo N e calcula e
apresente o somatório dos números de 1 a N.
*/

int somatorio(int n) {
    if (n <= 1) {
        return n;
    }
    return n + somatorio(n - 1);
}

int main() {
    int n = 5;
    printf("A soma dos %i primeiros numeros eh: %i", n, somatorio(n));
    return 0;
}