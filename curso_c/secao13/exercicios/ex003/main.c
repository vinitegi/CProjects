#include <stdio.h>

void binario(int n) {
    if (n > 1) {
        binario(n / 2); //chamada recursiva com o quociente da divisão por 2
    }
    printf("%d", n % 2); //o resto da divisao por 2 eh o resultado em binario
}

int main() {
    int numero;

    printf("Digite um numero inteiro para converter para binario: ");
    scanf("%d", &numero);

    if (numero < 0) {
        printf("Por favor, insira um numero nao negativo.\n");
    } else {
        printf("O numero %d em binario e: ", numero);
        binario(numero);
        printf("\n");
    }
    return 0;
}