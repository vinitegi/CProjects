/*Lista encadeada / lista ligada / Linked list
 *
 *A lista encadeada alem de possuir o seu valor, possui um ponteiro
 *para o proximo elemento.
 *
 *
 *
 */



#include <stdio.h>
#include <stdlib.h>

struct st_no{
    int valor;
    struct st_no *prox; //aponta para o proximo elemento da lista
};

typedef struct st_no no;

//verifica se a lista esta vazia
int vazia(no *le) { //le -> lista encadeada
    if (le->prox == NULL) {
        return 1; //lista vazia
    } else {
        return 0; //lista nao vazia
    }
}

//inicia a lista encadeada sem nenhum elemento
void inicia(no *le) {
    le->prox = NULL;
}

//
void libera(no *le) {
    if (!vazia(le)) {
        no *proxNo, *atual;
        atual = le->prox;
        while (atual != NULL) {
            proxNo = atual->prox;
            free(atual);
            atual = proxNo;
        }
    }
}

void exibe(no *le) {
    if (vazia(le)) {
        printf("A lista esta vazia!\n");
        return;
    }
    no *tmp;
    tmp = le->prox;

    while (tmp != NULL) {
        printf("|%d|", tmp->valor);
        tmp = tmp->prox;
    }
    printf("\n\n");
}

void insereInicio(no *le) {
    no *novo;
    novo = (no*) malloc(sizeof(no));
    if (!novo) {
        printf("Memoria Insuficiente!\n");
        exit(1);
    }
    printf("Informe um valor: ");
        scanf("%d", &novo->valor);

    no *oldHead = le->prox;

    le->prox = novo;
    novo->prox = oldHead;
}

void insereFinal(no *le) {
    no *novo;
    novo = (no*) malloc(sizeof(no));
    if (!novo) {
        printf("Memoria Insuficiente!\n");
        exit(1);
    }
    printf("Informe um valor: ");
        scanf("%d", &novo->valor);
    novo->prox = NULL;

    if (vazia(le)) {
        le->prox = novo;
    } else {
        no  *tmp = le->prox;

        while (tmp->prox != NULL) {
            tmp = tmp->prox;
        }
        tmp->prox = novo;
    }
}

void opcao(no *le, int op) {
    switch (op) {
        case 0:
            libera(le);
        break;

        case 1:
            exibe(le);
        break;

        case 2:
            insereInicio(le);
        break;

        case 3:
            insereFinal(le);
        break;

        case 4:
            inicia(le);
        break;

        default:
            printf("Comando invalido!\n");
    }
}

int menu() {
    int opt;
    printf("Escolha a opcao: \n"
           "0 - Liberar lista e sair;\n"
           "1 - Exibir lista;\n"
           "2 - Inserir elemento no incio;\n"
           "3 - Inserir elemento no final;\n"
           "4 - Iniciar;\n\n"
           "Digite aqui: ");
        scanf("%d", &opt);
    return opt;
}

int main() {
    no *le;
    le = (no *) malloc(sizeof(no));

    if (!le) {
        printf("Sem memoria disponivel!\n");
        exit(1);
    }
    inicia(le);
    int opt;

    do {
        opt = menu();
        opcao(le, opt);
    } while (opt);
    free(le);
    return 0;
}