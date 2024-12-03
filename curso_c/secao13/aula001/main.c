#include <stdio.h>
//recursividade
/*
 *recursividade eh o ato de uma funcao chamar a si msm
 */

int fib(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}
int main() {
    int qntd;

    printf("Informe o tamanho da sequencia de fibonacci: ");
    scanf("%i", &qntd);

    for (int i = 0; i < qntd; i++) {
        if (i == qntd - 1) {
            printf("%d. ", fib(i + 1));
        } else {
            printf("%d, ", fib(i + 1));
        }
    }
    return 0;
}

