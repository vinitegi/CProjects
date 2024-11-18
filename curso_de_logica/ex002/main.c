#include <stdio.h>

int main() {
    float altura;
    char sexo;
    float peso_ideal;

    printf("Digite sua altura:\n");
    scanf("%f", &altura);

    getchar();

    printf("Digite o seu sexo. M para masculilo, e F para feminino:\n");
    scanf("%c", &sexo);

    if (sexo == 'M' || sexo == 'm') {
        peso_ideal = (72.7 * altura) - 58;
    } else if (sexo == 'F' || sexo == 'f') {
        peso_ideal = (62.1 * altura) - 44.7;
    } else {
        printf("Sexo inválido. Use M ou F.\n");
        return 1;
    }
    printf("Seu peso ideal eh %2.fKg", peso_ideal);
}