#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int dificuldade;
    int valor1;
    int valor2;
    int operacao;
    int resultado;
} calcular;

void jogar();
void mostrarinfo(calcular calc);
int somar(int resposta, calcular calc);
int diminuir(int resposta, calcular calc);
int multiplicar(int resposta, calcular calc);

int pontos = 0;

int main(void) {
    // Deve ser chamado apenas uma vez
    srand(time(NULL));
    jogar();
    return 0;
}

void jogar() {
    calcular calc;

    printf("Informe o nivel de dificuldade desejado [1, 2, 3 ou 4]:\n");
    scanf("%d", &calc.dificuldade);

    // Gera um valor inteiro entre 0 e 2 (0: soma, 1: subtração, 2: multiplicação)
    calc.operacao = rand() % 3;

    if (calc.dificuldade == 1) {
        calc.valor1 = rand() % 11; // valores entre 0 a 10
        calc.valor2 = rand() % 11;
    } else if (calc.dificuldade == 2) {
        calc.valor1 = rand() % 101; // valores entre 0 a 100
        calc.valor2 = rand() % 101;
    } else if (calc.dificuldade == 3) {
        calc.valor1 = rand() % 1001; // valores entre 0 a 1000
        calc.valor2 = rand() % 1001;
    } else if (calc.dificuldade == 4) {
        calc.valor1 = rand() % 10001; // valores entre 0 a 10000
        calc.valor2 = rand() % 10001;
    } else {
        calc.valor1 = rand() % 100001; // valores entre 0 a 100000
        calc.valor2 = rand() % 100001;
    }

    int resposta;
    printf("Informe o resultado para a seguinte operacao: \n");

    if (calc.operacao == 0) { // Soma
        printf("%d + %d = ?\n", calc.valor1, calc.valor2);
        scanf("%d", &resposta);
        if (somar(resposta, calc)) {
            pontos++;
            printf("Voce tem %d ponto(s).\n", pontos);
        }
    } else if (calc.operacao == 1) { // Subtração
        printf("%d - %d = ?\n", calc.valor1, calc.valor2);
        scanf("%d", &resposta);
        if (diminuir(resposta, calc)) {
            pontos++;
            printf("Voce tem %d ponto(s).\n", pontos);
        }
    } else if (calc.operacao == 2) { // Multiplicação
        printf("%d * %d = ?\n", calc.valor1, calc.valor2);
        scanf("%d", &resposta);
        if (multiplicar(resposta, calc)) {
            pontos++;
            printf("Voce tem %d ponto(s).\n", pontos);
        }
    } else {
        printf("Operacao desconhecida!\n");
    }

    // Continuar o jogo?
    printf("Deseja continuar jogando? [1 - Sim, 0 - Nao]\n");
    int continuar;
    scanf("%d", &continuar);

    if (continuar == 1) {
        jogar();
    } else {
        printf("Voce finalizou com %d ponto(s).\n", pontos);
        printf("Ate a proxima!\n");
        exit(0);
    }
}

void mostrarinfo(calcular calc) {
    char opcao[25];

    if (calc.operacao == 0) {
        sprintf(opcao, "Somar");
    } else if (calc.operacao == 1) {
        sprintf(opcao, "Diminuir");
    } else if (calc.operacao == 2) {
        sprintf(opcao, "Multiplicar");
    } else {
        sprintf(opcao, "Operacao invalida");
    }
    printf("Valor 1: %d\n"
           "Valor 2: %d\n"
           "Dificuldade: %d\n"
           "Operacao: %s\n", calc.valor1, calc.valor2, calc.dificuldade, opcao);
}

int somar(int resposta, calcular calc) {
    calc.resultado = calc.valor1 + calc.valor2;
    int certo = resposta == calc.resultado;

    if (certo) {
        printf("Resposta correta!\n");
    } else {
        printf("Resposta incorreta!\n");
    }

    printf("%d + %d = %d\n", calc.valor1, calc.valor2, calc.resultado);
    return certo;
}

int diminuir(int resposta, calcular calc) {
    calc.resultado = calc.valor1 - calc.valor2;
    int certo = resposta == calc.resultado;

    if (certo) {
        printf("Resposta correta!\n");
    } else {
        printf("Resposta incorreta!\n");
    }

    printf("%d - %d = %d\n", calc.valor1, calc.valor2, calc.resultado);
    return certo;
}

int multiplicar(int resposta, calcular calc) {
    calc.resultado = calc.valor1 * calc.valor2;
    int certo = resposta == calc.resultado;

    if (certo) {
        printf("Resposta correta!\n");
    } else {
        printf("Resposta incorreta!\n");
    }

    printf("%d * %d = %d\n", calc.valor1, calc.valor2, calc.resultado);
    return certo;
}
