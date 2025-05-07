#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 10

typedef struct {
    int id;
    char nome[100];
    char tipo[50];
    double valor;
}Produto;

int total = 0;

void cadastrarProduto(Produto item[], int *total); //finalizada
void modificarProduto(Produto item[], int total);
void excluirProduto(Produto item[], int *total);
void listarProdutos(Produto item[], int total); //finalizada
void pesquisarPorId(Produto item[], int total, int id);
void salvarProdutos(FILE *arq, Produto item[], int total); //finalizada
void carregarProdutos(FILE *arq, Produto item[], int *total); //finalizada

int main(void) {
    Produto item[MAX_PRODUTOS];
    int id;
    int opcao;

    FILE *arq = fopen("produtos.txt", "a+");
    if (arq != NULL) {
        carregarProdutos(arq, item, &total);
        fclose(arq);
    }

    do {
        printf("\n--- MENU ---\n");
        printf("1. Inserir produto\n");
        printf("2. Alterar produto\n");
        printf("3. Excluir produto\n");
        printf("4. Listar produtos\n");
        printf("5. Pesquisar por ID\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrarProduto(item, &total);
                break;
            case 2:
                modificarProduto(item, total);
                break;
            case 3:
                excluirProduto(item, &total);
                break;
            case 4:
                listarProdutos(item, total);
                break;
            case 5:
                printf("Digite o ID do produto: ");
                scanf("%d", &id);
                pesquisarPorId(item, total, id);
                break;
            case 6:
                salvarProdutos(arq, item, total);
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 6);

    return 0;
}

void cadastrarProduto(Produto item[], int *total){
    if (*total >= MAX_PRODUTOS) {
        printf("Numero maximo de produtos atingido");
    } else {
        printf("Informe o ID do produto: ");
            scanf("%d", &item[*total].id);
        getchar();

        printf("Informe o nome do produto: ");
            fgets(item[*total].nome, sizeof(item[*total].nome), stdin);
        item[*total].nome[strcspn(item[*total].nome, "\n")] = '\0';

        printf("Informe o tipo do produto: ");
            fgets(item[*total].tipo, sizeof(item[*total].tipo), stdin);
        item[*total].tipo[strcspn(item[*total].tipo, "\n")] = '\0';

        printf("Informe o valor do produto: ");
            scanf("%f", &item[*total].valor);

        (*total)++;
    }
}

void modificarProduto(Produto item[], int total){

}

void excluirProduto(Produto item[], int *total){

}

void listarProdutos(Produto item[], int total){
    if (total == 0) {
        printf("Nenhum produto cadastrado!\n");
        return;
    }

    for (int i = 0; i < total; i++){
        printf("ID: %d\n"
               "Nome: %s\n"
               "Tipo: %s\n"
               "Valor: %.2f\n", item[i].id, item[i].nome, item[i].tipo, item[i].valor);
    }
}

void pesquisarPorId(Produto item[], int total, int id){

}

void salvarProdutos(FILE *arq, Produto item[], int total){ //salva os produtos no arquivo
    for (int i = 0; i < total; i++) {
        fprintf(arq, "%i;%s;%s;%f\n",
            item[i].id,
            item[i].nome,
            item[i].tipo,
            item[i].valor);
    }
}

void carregarProdutos(FILE *arq, Produto item[], int *total){ //copia os produtos salvos no arquivo para o vetor
    while (fscanf(arq, "%d;%[^;];%[^;];%lf\n", //enquanto fscanf conseguir ler exatamente 4 itens por linha, vai continuar
                  &item[*total].id,
                  item[*total].nome,
                  item[*total].tipo,
                  &item[*total].valor) == 4) {
        (*total)++;
    }
}

