#include <stdio.h>

#define N 10 // Defina o número de produtos a serem cadastrados

typedef struct {
    char nome[30];
    float preco;
    int quantidade;
} Produto;

void cadastrarProduto(Produto *produto);
void listarProdutos(Produto produtos[], int quantidade);
void atualizarPreco(Produto *produto);

int main() {
    Produto produtos[N];
    int opcao;
    int SKU;
    int cadastrados = 0;

    do {
        printf("\nMenu:\n");
        printf("1 - Cadastrar Produto\n");
        printf("2 - Listar Produtos\n");
        printf("3 - Atualizar Preco\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
            scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (cadastrados < N) {
                    cadastrarProduto(&produtos[cadastrados]);
                    cadastrados++;
                } else {
                    printf("\nLimite de produtos atingido!\n");
                }
                break;
            case 2:
                if (cadastrados > 0) {
                    listarProdutos(produtos, cadastrados);
                } else {
                    printf("\nNenhum produto cadastrado!\n");
                }
                break;
            case 3:
                if (cadastrados > 0) {
                    printf("\nDigite o SKU do produto para atualizar o preco (1 a %d): ", cadastrados);
                    scanf("%d", &SKU);
                    if (SKU >= 1 && SKU <= cadastrados) {
                        atualizarPreco(&produtos[SKU - 1]);
                    } else {
                        printf("SKU invalido!\n");
                    }
                } else {
                    printf("\nNenhum produto cadastrado para atualizar!\n");
                }
                break;
            case 0:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}

void cadastrarProduto(Produto *produto) {
    printf("\nDigite o nome do produto: ");
        scanf("%s", produto->nome);
    printf("Digite o preco do produto: ");
        scanf("%f", &produto->preco);
    printf("Digite a quantidade do produto: ");
        scanf("%d", &produto->quantidade);
    getchar();
}

void listarProdutos(Produto produtos[], int quantidade) {
    printf("\nLista de Produtos:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("Produto %d:\n", i + 1);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Preco: R$ %.2f\n", produtos[i].preco);
        printf("Quantidade: %d\n", produtos[i].quantidade);
        printf("-------------------------\n");
    }
}

void atualizarPreco(Produto *produto) {
    printf("\nDigite o novo preco para %s: ", produto->nome);
        scanf("%f", &produto->preco);
}
