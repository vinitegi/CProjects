#include <stdio.h>

int isPrimo(int num) {
    for (int i = 2; i < num / 2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    int num;
    int primos[10];
    int contaPrimos = 0;

    while (contaPrimos < 10) {
        printf("Digite um numero: ");
        fflush(stdin);
        scanf("%i", &num);

        if (isPrimo(num) == 1) {
            primos[contaPrimos] = num;
            contaPrimos++;
            printf("\nNumero adicionado com sucesso!");
        }
        printf("\nExistem %i numeros no vetor", contaPrimos);
    }

    return 0;
}
