#include <stdio.h>
#include <string.h>

typedef struct {
    float x;
    float y;
    float z;
}vetor;

int main() {
    vetor vetor1, vetor2, soma;

    printf("Digite o valor de 'x' para o vetor 1 e para o vetor 2: ");
    scanf("%f %f", &vetor1.x, &vetor2.x);
    soma.x = vetor1.x + vetor2.x;

    printf("Digite o valor de 'y' para o vetor 1 e para o vetor 2: ");
    scanf("%f %f", &vetor1.y, &vetor2.y);
    soma.y = vetor1.y + vetor2.y;

    printf("Digite o valor de 'z' para o vetor 1 e para o vetor 2: ");
    scanf("%f %f", &vetor1.z, &vetor2.z);
    soma.z = vetor1.z + vetor2.z;

    printf("\nResultado da soma dos vetores:\n");
    printf("x: %.2f\n", soma.x);
    printf("y: %.2f\n", soma.y);
    printf("z: %.2f\n", soma.z);

    return 0;
}