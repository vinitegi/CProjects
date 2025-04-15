// Crie um programa em C que simule uma conta bancária. O programa deve ter uma struct
//
// Conta com os seguintes campos:
// - numero: número da conta
// - saldo: saldo da conta
// - limite: limite de crédito da conta
//
// O programa deve ter as seguintes funções:
//
// - criar_conta: cria uma nova conta com os parâmetros passados por valor
// - depositar: deposita um valor na conta, passando o valor por referência
// - sacar: saca um valor da conta, passando o valor por referência
// - imprimir_conta: imprime os dados da conta, passando a conta por referência
//
// O programa deve ter uma função main que crie uma conta, faça um depósito, um saque e imprima os dados da conta.
//
// # Restrições
// - A conta deve ser criada com um saldo inicial de 0.
// - O limite de crédito da conta deve ser de 1000.
// - O valor do depósito e do saque deve ser maior que 0.
// - O saque não deve exceder o saldo da conta

#include <stdio.h>
#define MAX 5 //maximo de 10 contas

//structs e contas
typedef struct {
    int ID;
    float saldo;
    float limite;
}Contas;
Contas conta[MAX];
int totalContas = 0;

void criarConta(Contas conta[], int *totalContas);
void depositarConta(Contas *conta, float valor, int ID);
void sacarConta(Contas *conta, float valor, int ID);
void imprimeConta(Contas *conta, int ID);

int main(void) {
    criarConta(conta, &totalContas);
    depositarConta(conta, 500, 1);
    sacarConta(conta, 100, 1);
    imprimeConta(conta, 1);
    return 0;
}


void criarConta(Contas conta[], int *totalContas){
    if(*totalContas < MAX) {
        conta[*totalContas].ID = *totalContas + 1;
        conta[*totalContas].saldo = 0;
        conta[*totalContas].limite = 1000;

        printf("Conta criada com sucesso!\n "
               "ID: %d\n"
               "Saldo: %.2f\n"
               "Limite: %.2f\n", conta[*totalContas].ID, conta[*totalContas].saldo, conta[*totalContas].limite);

        (*totalContas)++;
    } else {
        printf("Limite de contas atingido");
    }
}
void depositarConta(Contas *conta, float valor, int ID){
    for (int i = 0; i < totalContas; i++) {
        if (conta[i].ID == ID) {
            if (valor > 0) {
                conta[i].saldo += valor;
                printf("Conta depositada com sucesso!\n ");
                printf("Valor atual da conta: %.2f\n", conta[i].saldo);
            } else {
                printf("O valor de deposito deve ser maior do que R$ 0,00");
            }
        }
    }
}
void sacarConta(Contas *conta, float valor, int ID){
    for (int i = 0; i < totalContas; i++) {
        if (conta[i].ID == ID) {
            if (valor < conta[i].saldo) {
                conta[i].saldo -= valor;
                printf("Conta de sacar com sucesso!\n ");
            } else {
                printf("Saldo insuficiente para o saque!");
            }
        }
    }
}
void imprimeConta(Contas *conta, int ID){
    for (int i = 0; i < totalContas; i++) {
        if (conta[i].ID == ID) {
            printf("Dados da conta:\n");
            printf("Número da conta: %d\n", conta[i].ID);
            printf("Saldo: %.2f\n", conta[i].saldo);
            printf("Limite: %.2f\n\n", conta[i].limite);
            return;
        }
    }
}