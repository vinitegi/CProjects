#include <stdio.h>
#define MAX 10

typedef struct {
    int ID;
    float saldo;
    float limite;
}Account;
Account c[MAX];
int contador = 0;

void criarConta(Account c[], int *contador);
void depositar(Account c[], float valor, int ID);
void sacar(Account c[], float valor, int ID);
void mostrarConta(Account c[], int ID);

int main() {
    criarConta(c, &contador);
    depositar(c, 500, 1);
    sacar(c, 500, 1);
    mostrarConta(c, 1);
    return 0;
}

void criarConta(Account c[], int *contador) {
    if (*contador >= MAX) {
        printf("Limite de contas atingido");
    } else {
        for (int i = 0; i < MAX; i++) {
            c[i].ID = i + 1;
            c[i].saldo = 0;
            c[i].limite = 1000;
            (*contador)++;
        }
    }
}
void depositar(Account c[], float valor, int ID) {
    printf("Digite a conta que deseja acessar: ");
    scanf("%f", &ID);
    for (int i = 0; i < MAX; i++) {
        if (c[i].ID == ID) {
            printf("Qual valor que sera depositado?");
            scanf("%f", &valor);
            c[i].saldo += valor;
            printf("Valor depositado com sucesso!\n"
                   "Conta: %d\n"
                   "Saldo: %.2f\n"
                   "Limite: %.2f\n", ID, c[i].saldo, c[i].limite);
            return;
        }
    }
}
void sacar(Account c[], float valor, int ID) {
    printf("Digite a conta que deseja acessar: ");
    scanf("%f", &ID);
    for (int i = 0; i < MAX; i++) {
        if (c[i].ID == ID) {
            printf("Qual valor que sera sacado?");
            scanf("%f", &valor);
            c[i].saldo -= valor;
            printf("Valor sacado com sucesso!\n"
                   "Conta: %d\n"
                   "Saldo: %.2f\n"
                   "Limite: %.2f\n", ID, c[i].saldo, c[i].limite);
            return;
        }
    }
}








// void criarConta(Contas conta[], int *totalContas);
// void depositarConta(Contas *conta, float valor, int ID);
// void sacarConta(Contas *conta, float valor, int ID);
// void imprimeConta(Contas *conta, int ID);
//
// int main(void) {
//     criarConta(conta, &totalContas);
//     depositarConta(conta, 500, 1);
//     sacarConta(conta, 100, 1);
//     imprimeConta(conta, 1);
//     return 0;
// }
//
//
// void criarConta(Contas conta[], int *totalContas){
//     if(*totalContas < MAX) {
//         conta[*totalContas].ID = *totalContas + 1;
//         conta[*totalContas].saldo = 0;
//         conta[*totalContas].limite = 1000;
//
//         printf("Conta criada com sucesso!\n "
//                "ID: %d\n"
//                "Saldo: %.2f\n"
//                "Limite: %.2f\n", conta[*totalContas].ID, conta[*totalContas].saldo, conta[*totalContas].limite);
//
//         (*totalContas)++;
//     } else {
//         printf("Limite de contas atingido");
//     }
// }
// void depositarConta(Contas *conta, float valor, int ID){
//     for (int i = 0; i < totalContas; i++) {
//         if (conta[i].ID == ID) {
//             if (valor > 0) {
//                 conta[i].saldo += valor;
//                 printf("Conta depositada com sucesso!\n ");
//                 printf("Valor atual da conta: %.2f\n", conta[i].saldo);
//             } else {
//                 printf("O valor de deposito deve ser maior do que R$ 0,00");
//             }
//         }
//     }
// }
// void sacarConta(Contas *conta, float valor, int ID){
//     for (int i = 0; i < totalContas; i++) {
//         if (conta[i].ID == ID) {
//             if (valor < conta[i].saldo) {
//                 conta[i].saldo -= valor;
//                 printf("Conta de sacar com sucesso!\n ");
//             } else {
//                 printf("Saldo insuficiente para o saque!");
//             }
//         }
//     }
// }
// void imprimeConta(Contas *conta, int ID){
//     for (int i = 0; i < totalContas; i++) {
//         if (conta[i].ID == ID) {
//             printf("Dados da conta:\n");
//             printf("Número da conta: %d\n", conta[i].ID);
//             printf("Saldo: %.2f\n", conta[i].saldo);
//             printf("Limite: %.2f\n\n", conta[i].limite);
//             return;
//         }
//     }
// }