#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 10

typedef struct {
    int id;
    char nome[100];
    char tipo[50];
    double valor;
} Produto;

int total = 0;

void cadastrarProduto(Produto item[], int *total); //finalizada
void modificarProduto(Produto item[], int total);
void excluirProduto(Produto item[], int *total);
void listarProdutos(Produto item[], int total); //finalizada
void pesquisarPorId(Produto item[], int total, int id);
void salvarProdutos(Produto item[], int total); //finalizada
void carregarProdutos(Produto item[], int *total); //finalizada

int main(void) {
    Produto item[MAX_PRODUTOS];
    int id;
    int opcao;

    carregarProdutos(item, &total);

    do {
        printf("\n--- MENU ---\n");
        printf("1. Inserir produto\n");
        printf("2. Alterar produto\n");
        printf("3. Excluir produto\n");
        printf("4. Listar produtos\n");
        printf("5. Pesquisar por ID\n");
        printf("6. Salvar produtos\n");
        printf("7. Encerrar programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

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
                salvarProdutos(item, total);
                break;
            default:
                printf("Opcao inválida!\n");
                break;
        }
    } while(opcao != 7);
    printf("Encerrando o programa.\n");

    return 0;
}

void cadastrarProduto(Produto item[], int *total) {
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
        scanf("%lf", &item[*total].valor);
        getchar();

        (*total)++;
    }
}

void modificarProduto(Produto item[], int total) {
    if (total == 0) {
        printf("Nenhum produto cadastrado!\n");
    } else {
        int codigoBusca;
        printf("Digite o ID do produto que sera buscado: ");
        scanf("%i", &codigoBusca);
        getchar();

        int encontrado = 0;
        for (int i = 0; i < total; i++) {
            if (codigoBusca == item[i].id) {
                printf("Digite o novo nome do produto: ");
                fgets(item[i].nome, sizeof(item[i].nome), stdin);
                item[i].nome[strcspn(item[i].nome, "\n")] = 0;

                printf("Digite o novo tipo do produto: ");
                fgets(item[i].tipo, sizeof(item[i].tipo), stdin);
                item[i].tipo[strcspn(item[i].tipo, "\n")] = 0;

                printf("Digite o novo valor do produto: ");
                scanf("%lf", &item[i].valor);
                getchar();

                printf("Produto alterado com sucesso!\n");
                encontrado = 1;
                break;
            }
        }

        if (!encontrado) {
            printf("Produto com o ID %d nao encontrado!\n", codigoBusca);
        }
    }
}

void excluirProduto(Produto item[], int *total) {
    if (*total == 0) {
        printf("Nenhum produto cadastrado!\n");
    } else {
        int codigoBusca;

        printf("Digite o ID do produto que deseja excluir: ");
        scanf("%d", &codigoBusca);

        for (int i = 0; i < *total; i++) {
            if (item[i].id == codigoBusca) {
                for (int j = i; j < *total - 1; j++) {
                    item[j] = item[j + 1];
                }

                (*total)--;
                printf("Produto excluido com sucesso\n");
                return;
            }
        }
        printf("Produto com o ID %d nao encontrado!\n", codigoBusca);
    }
}

void pesquisarPorId(Produto item[], int total, int id) {
    if (total == 0) {
        printf("Nenhum produto cadastrado!\n");
    } else {
        for (int i = 0; i < total; i++) {
            if (id == item[i].id) {
                printf("Produto encontrado: %s - %s - R$ %.2lf\n",
                       item[i].nome, item[i].tipo, item[i].valor);
                return;
            }
        }
        printf("Produto com ID %d nao encontrado!\n", id);
    }
}

void listarProdutos(Produto item[], int total) {
    if (total == 0) {
        printf("Nenhum produto cadastrado!\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        printf("ID: %d\n"
            "Nome: %s\n"
            "Tipo: %s\n"
            "Valor: %.2f\n\n",
            item[i].id,
            item[i].nome,
            item[i].tipo,
            item[i].valor);
    }
}


void salvarProdutos(Produto item[], int total) { //salva os produtos no arquivo
    FILE *arq = fopen("produtos.txt", "w");
    if (arq == NULL) {
        printf("Erro ao salvar os produtos!\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        fprintf(arq, "%i;%s;%s;%.2lf\n",
                item[i].id,
                item[i].nome,
                item[i].tipo,
                item[i].valor);
    }

    fclose(arq);
    printf("Produtos salvos com sucesseco!\n");
}

void carregarProdutos(Produto item[], int *total) { //copia os produtos salvos no arquivo para o vetor
    FILE *arq = fopen("produtos.txt", "r");
    if (arq == NULL) return;

    while (fscanf(arq, "%d;%[^;];%[^;];%lf\n",
                  &item[*total].id,
                  item[*total].nome,
                  item[*total].tipo,
                  &item[*total].valor) == 4) {
        (*total)++;
    }

    fclose(arq);
}
