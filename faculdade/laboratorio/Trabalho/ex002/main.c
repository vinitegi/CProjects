#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "windows.h"

#define MAX_VAGAS 50

typedef struct {
    char marca[30];
    char modelo[30];
    char cor[20];
    char placa[10]; // pode guardar placa no formato antigo ou novo
    char proprietario[50];
    char tipo; // 'P' para professor, 'F' para funcionário
    int está_no_estacionamento; // 1 para sim, 0 para não
} Veiculo;

Veiculo listaVeiculos[MAX_VAGAS];
int totalVeiculosCadastrados = 0;
int vagasOcupadas = 0;


int main(void) {
    printf("Hello, World!\n");
    return 0;
}