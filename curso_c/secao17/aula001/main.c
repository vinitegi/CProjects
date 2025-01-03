//fila -> queue
/*
 *fila de banco;
 *o elemento que entra primeiro, sai primeiro;
 *sempre que um elemento eh adicionado, ele vai para o final da fila;
 *sempre que removemos um elemento, o primeiro eh removido;
 *
 *FIFO -> first in / first out
 *
 *enqueue() -> adiciona o elemento na fila
 *dequeue() -> remove o elemento da fila
 *clear() -> limpar a fila
 *
 *======== ESTRUTURA ========
 *fila[10]
 *head -> indica quem eh o primeiro elemento da fila
 *tail -> quantos elementos tem elemento da fila
 *
 *
 *======== APLICACAO ========
 *em qlqr situacao que seja necessario organizar o atendimento de elementos
 */

#include <stdio.h>
#define TAMFILA 10

//fila / queue
int fila[TAMFILA] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int head = 0;
int tail = 0;

void lista_elementos() {
    printf("\n========== FILA ATUAL ==========\n");
    for (int i = 0; i < TAMFILA; i++) {
        printf(" - |%d|", fila[i]);
    }
    printf("\n\nHead: %i", head);
    printf("\nTail: %i\n", tail);
}

void enqueue() {
    int val;

    if (tail < TAMFILA) {
        printf("Informe o elemento para adicionar na fila");
        scanf("%i", &val);

        fila[tail] = val; //a posicao atual, que sempre sera a ultima, recebera o valor digitado
        tail++; //vai mover a posicao dentro do array, para que possa ser adicionado um novo numero em uma posicao diferente

        //lista_elementos(); //vai mostrar a fila atual

    }else {
        printf("A fila esta cheia");
    }

}

void dequeue() {
    if (head < tail) {
        fila[head] = 0;
        head++;
        lista_elementos();


    } else {
        printf("A lista esta vazia");
    }
}

void clear() {
    for (int i = 0; i < TAMFILA; i++) {
        fila[i] = 0;
    }
}

int main() {
    int opcao;
    lista_elementos();


    do {


        printf("\n1 - Adicionar um elemento;\n"
               "2 - Remover um elemento;\n"
               "3 - Mostar a fila atual;\n"
               "4 - Limpar a fila;\n"
               "5 - Sair\n"
               "Digite a opcao desejada: ");
            scanf("%i", &opcao);


        switch (opcao) {

            case 1:
                enqueue();
            break;

            case 2:
                dequeue();
            break;

            case 3:
                lista_elementos();
            break;

            case 4:
                clear();
            break;

            default:
                printf("Opcao invalida!");
            break;
        }
    } while (opcao != 5);


    return 0;
}