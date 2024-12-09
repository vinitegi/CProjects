#include <stdio.h>
#include <math.h>

/*
 *        =========== FUNCOES TRIGONOMETRICAS ===========
 *      cos() -> calcula o cosseno de um angulo em radianos
 *      sin() -> calcula o sen de um angulo em radianos
 *      tan() -> calcula a tangente de um angulo em radianos
 *
 *        =========== FUNCOES HIPERBOLICAS ===========
 *      cosh() -> calcula o cosseno hiperbolico de um angulo em radianos
 *      sinh() -> calcula o seno hiperbolico de um angulo em radianos
 *      tanh() -> calcula a tangente hiperbolico de um angulo em radianos
 *
 *        =========== FUNCOES EXPONENCIAL ===========
 *      exp() -> funcao exponencial
 *      log() -> log natural
 *      log10() -> log base 10
 *
 *        =========== FUNCOES DE POTENCIA ===========
 *      pow() -> retorna a base elevada ao expoente
 *      sqrt() -> raiz quadrada
 *
 *        =========== FUNCOES DE ARREDONDAMENTO, VALOR ABSOLUTO E OUTRAS ===========
 *     ceil() -> arredonda para cima do numero
 *     floor() -> arredonda para baixo do numero
 */

int main() {
    int angulo = 45;

    printf("=========== FUNCOES TRIGONOMETRICAS ===========\n\n");
    double res_c = cos(angulo);
    double res_s = sin(angulo);
    double res_t = tan(angulo);

    printf("O cosseno de %d vale %.6f\n", angulo, res_c);
    printf("O seno de %d vale %.6f\n", angulo, res_s);
    printf("O tangente de %d vale %.6f\n", angulo, res_t);

    printf("\n=========== FUNCOES HIPERBOLICAS ===========\n\n");
    double res_ch = cosh(angulo);
    double res_sh = sinh(angulo);
    double res_th = tanh(angulo);

    printf("O cosseno hiperbolico de %d vale %.6f\n", angulo, res_ch);
    printf("O seno hiperbolico de %d vale %.6f\n", angulo, res_sh);
    printf("O tangente hiperbolico de %d vale %.6f\n", angulo, res_th);

    printf("\n=========== FUNCOES EXPONENCIAL E LOGARITMICAS ===========\n\n");
    double a = 0;
    double b = 1;
    double c = 2;

    printf("O exponecial de %lf vale %lf\n", a, exp(a));
    printf("O exponecial de %lf vale %lf\n", b, exp(b));
    printf("O exponecial de %lf vale %lf\n", c, exp(c));

    printf("\n");

    printf("O logaritmo natural de %lf vale %lf\n", a, log(a));
    printf("O logaritmo natural de %lf vale %lf\n", b, log(b));
    printf("O logaritmo natural de %lf vale %lf\n", c, log(c));

    printf("\n");

    printf("O logaritmo na base 10 de %lf vale %lf\n", a, log10(a));
    printf("O logaritmo na base 10 de %lf vale %lf\n", b, log10(b));
    printf("O logaritmo na base 10 de %lf vale %lf\n", c, log10(c));

    printf("\n=========== FUNCOES DE POTENCIA ===========\n");

    int x = 3;
    int y = 2;
    int z = 9;

    printf("%i elevado a %i vale %lf\n", x, y, pow(x, y));

    printf("\n");

    printf("A raiz quadrade de %d vale %lf\n", z, sqrt(z));

    printf("\n=========== FUNCOES DE ARREDONDAMENTO, VALOR ABSOLUTO E OUTRAS ===========\n\n");
    double quebrado = 4.83735762;

    printf("O arredondamento para cima de %lf eh %lf\n\n", quebrado, ceil(quebrado));
    printf("O arredondamento para baixo de %lf eh %lf\n\n", quebrado, floor(quebrado));

    return 0;
}