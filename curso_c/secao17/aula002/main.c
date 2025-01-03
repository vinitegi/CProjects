/*PILHA / STACK
 *
 *FILO -> Firt in / Last out
 *LIFO -> Last in / First out
 *
 *os ultimos dados inseridos sempre estrarao no topo
 *e por consequencia, os primeiros a serem adicionados estarao na base
 *
 *so temos acesso ao elemento que esta no topo
 *
 *o processo de inserir um elemento eh chamado de "push"
 *
 *o processo de remover um elemento eh chamdo de "pop" -> pode remover apenas o elemento do topo
 *
 *APLICACAO
 *
 *CTRL + Z -> remove o ultimo comando
 */

#include <stdio.h>
#define TAMPILHA 10

int pilha[TAMPILHA] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int topo = 0;

void lista() {
     printf("========== PILHA ATUAL ==========\n");
    for (int i = 0; i < TAMPILHA; i++) {
        printf(" - |%i|", pilha[i]);
    }
    printf("Topo: %i \n\n", topo);
}

void push() {
    int valor;
    printf("Informe o valor: ");
        scanf("%i", &valor);

    if (topo < TAMPILHA) {
        pilha[topo] = valor;
        topo++;
    }else {
        printf("A pilha ja esta cheia");
    }
    lista();
}

void pop() {
    printf("Removendo um elemento");
    if (topo >= 0) {
        pilha[topo - 1] = 0;
        topo--;
        lista();
    }else {
        printf("A pilha ja esta vazia");
    }
}

int main() {
    printf("Hello, World!\n");
    return 0;
}