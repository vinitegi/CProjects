#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 10

typedef struct {
    int id;
    char nome[100];
    char tipo[50];
    double valor;
} Produto;

void cadastrarProduto(Produto item[], int *total); //finalizada
void modificarProduto(Produto item[], int total);
void excluirProduto(Produto item[], int *total);
void listarProdutos(Produto item[], int total); //finalizada
void pesquisarPorId(Produto item[], int total);
void salvarProdutos(Produto item[], int total); //finalizada
void carregarProdutos(Produto item[], int *total); //finalizada

int main(void) {
    Produto item[MAX_PRODUTOS];
    int total = 0;
    int opcao;

    //qnd o programa iniciar, total sempre sera igual a 0, mas a função carregarProdutos muda isso
    carregarProdutos(item, &total);

    do {
        printf("\n--- MENU ---\n"
               "1. Inserir produto\n"
               "2. Alterar produto\n"
               "3. Excluir produto\n"
               "4. Listar produtos\n"
               "5. Pesquisar por ID\n"
               "6. Salvar produtos\n"
               "7. Encerrar programa\n"
               "Escolha uma opcao: ");
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
                pesquisarPorId(item, total);
                break;
            case 6:
                salvarProdutos(item, total);
                break;

            case 7:
                printf("Saindo do sistema...\n");

            default:
                printf("Opcao inválida!\n");
                break;
        }
    } while(opcao != 7);

    //pra salvar automaticamente, caso o usuario esqueca de salvar manualmente
    salvarProdutos(item, total);
    printf("Encerrando o programa.\n");

    return 0;
}

void cadastrarProduto(Produto item[], int *total) {
    if (*total >= MAX_PRODUTOS) {
        printf("Numero maximo de produtos atingido\n");
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
                break; //usa 'break' para encerrar o 'for', se usasse 'return' encerraria a função
            }
        }

        if (!encontrado) {
            printf("Produto com o ID %d nao encontrado!\n", codigoBusca);
        }
    }
}

void excluirProduto(Produto item[], int *total) {
    //nao vai apagar do arquivo, vai apagar na arrey de struct, eh necessario salvar dps
    if (*total == 0) {
        printf("Nenhum produto cadastrado!\n");
    } else {
        int codigoBusca;
        int encontrado = 0;

        printf("Digite o ID do produto que deseja excluir: ");
        scanf("%d", &codigoBusca);

        for (int i = 0; i < *total; i++) {
            if (item[i].id == codigoBusca) {
                for (int j = i; j < *total - 1; j++) {
                    item[j] = item[j + 1];
                }

                (*total)--;
                printf("Produto excluido com sucesso\n");
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            printf("Produto com o ID %d nao encontrado!\n", codigoBusca);
        }
    }
}

void pesquisarPorId(Produto item[], int total) {
    int codigoBusca;

    printf("Digite o ID do produto: ");
        scanf("%d", &codigoBusca);

    if (total == 0) {
        printf("Nenhum produto cadastrado!\n");
    } else {
        for (int i = 0; i < total; i++) {
            if (codigoBusca == item[i].id) {
                printf("Produto encontrado: %s - %s - R$ %.2lf\n",
                       item[i].nome, item[i].tipo, item[i].valor);
                return; //usando o o return, ele fecha a funcao e nao roda as proximas intrucoes da msm
            }
        }
        printf("Produto com ID %d nao encontrado!\n", codigoBusca);
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
    printf("Produtos salvos com sucesso!\n");
}

void carregarProdutos(Produto item[], int *total) { //copia os produtos salvos no arquivo para o vetor
    FILE *arq = fopen("produtos.txt", "r");
    if (arq == NULL) {
        return;
    }

    while (*total < MAX_PRODUTOS && //evita o limite de produtos seja atingido
        fscanf(arq, "%d;%[^;];%[^;];%lf\n",
                  &item[*total].id,
                  item[*total].nome,
                  item[*total].tipo,
                  &item[*total].valor) == 4){
        (*total)++;
        //se conseguir ler todos os 4 campos corretamente, salva os dados no vetor item[*total], e aumente *total
    }


    fclose(arq);
}
