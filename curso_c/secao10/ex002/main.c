#include <stdio.h>

int main() {
    int var1;
    int var2;

    printf("Digite um valor para a variavel 1: \n");
        scanf("%i", &var1);
    printf("Digite um valor para a variavel 2: \n");
        scanf("%i", &var2);

    printf("O endereco de memoria da variavel 1 eh %p\n", &var1);
    printf("O endereco de memoria da variavel 2 eh %p\n", &var2);

    if (&var1 > &var2) {
        printf("A variavel 1 possui o maior endereco de memoria");
    }
    else {
        printf("A variavel 2 possui o maior endereco de memoria");
    }
    return 0;
}
