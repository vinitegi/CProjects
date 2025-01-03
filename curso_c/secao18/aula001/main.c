/*Arvore Binaria | Binary Tree
 *
 *Sao estruturas de dados caracterizadas por"
 *  - ou, nao tem elemento algum (arvore vazia);
 *  - ou tem um elemento distindo, denominado raiz, com dois apontamentos para duas estruturas diferentes
 *  denominadas sub-arvore (esquerda e direita)
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct st_arvore{
    int valor;
    struct st_arvore *right; //sub-arvore direita
    struct st_arvore *left; //sub-arvore esquerda
}arvore;


arvore* criaArvore() {
    return NULL;
}

int vazia(arvore *t) { //verifica se a arvore esta vazia
    return t == NULL; //se t == NULL -> retorna 1 se estiver vazia, caso contrario, retorna 0
}

void mostraArvore(arvore *t) {
    printf("<");
    if (!vazia(t)) {
        printf("%d, ", t->valor);
        mostraArvore(t->right);
        mostraArvore(t -> left);
    }
    printf(">");
}

void inserir(arvore **t, int num) {
    if (*t == NULL) {
        *t = (arvore*)malloc(sizeof(arvore));
        (*t) -> left = NULL;
        (*t) -> right = NULL;
        (*t) -> valor = num;
    } else {
        if (num < (*t)->valor) {
            inserir(&(*t)->left, num);
        }
        if (num > (*t)->valor) {
            inserir(&(*t)->right, num);
        }
    }
}

int busca(arvore *t, int num) {
    if (vazia(t)) {
        return 0;
    }
        return t->valor == num || busca(t->left, num) || busca(t->right, num);
}

int main() {
    arvore *t = criaArvore();

    inserir(&t, 12);
    inserir(&t, 15);
    inserir(&t, 10);
    inserir(&t, 13);
    mostraArvore(t);

    if (vazia(t)) {
        printf("\n\nArvore vazia!");
    } else {
        printf("\n\nArvore nao esta vazia!");
    }

    if (busca(t, 15)) {
        printf("\n\nElemento '15' encontrado!");
    } else {
        printf("\n\nElemento '15' nao encontrado!");
    }

    if (busca(t, 94)) {
        printf("\n\nElemento '94' encontrado!");
    } else {
        printf("\n\nElemento '94' nao encontrado!");
    }

    if (busca(t, 25)) {
        printf("\n\nElemento '25' encontrado!");
    } else {
        printf("\n\nElemento '25' nao encontrado!");
    }

    if (busca(t, 13)) {
        printf("\n\nElemento '13' encontrado!");
    } else {
        printf("\n\nElemento '13' nao encontrado!");
    }

    free(t);
    return 0;
}