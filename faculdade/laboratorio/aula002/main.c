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
    printf("Digite um numero: ");
    fflush(stdin);
    scanf("%i", &num);

    if (isPrimo(num) == 1) {
        printf("\nO numero eh primo");
    } else {
        printf("\nO numero nao eh primo");
    }
    return 0;
}
