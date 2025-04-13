#include <stdio.h>
#include <string.h>
#define N 10

typedef struct {
    char nome[50];
    char telefone[20];
    char email[50];
} Contato;

Contato ListaDeContatos[N];

void adicionarContato(Contato *contato);
void listarContatos(Contato contatos[], int contador);
void buscarContato(Contato contatos[], int contador, char nomeBuscado[]);

int main(void) {
    int qntd;
    printf("Digite a quantidade de contatos (maximo %d): ", N);
    scanf("%d", &qntd);
    getchar();

    int opcao;
    int contador = 0;

    do {
        printf("-------------------------------------\n");
        printf("1 - Adicionar contato\n");
        printf("2 - Listar contatos\n");
        printf("3 - Buscar contato\n");
        printf("4 - Sair\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                if (contador < qntd) {
                    adicionarContato(&ListaDeContatos[contador]);
                    contador++;
                } else {
                    printf("Limite de contatos atingido!\n");
                }
            break;

            case 2:
                listarContatos(ListaDeContatos, contador);
            break;

            case 3: {
                char nomeBuscado[50];
                printf("Digite o nome a ser buscado: ");
                fgets(nomeBuscado, sizeof(nomeBuscado), stdin);
                nomeBuscado[strcspn(nomeBuscado, "\n")] = '\0';
                buscarContato(ListaDeContatos, contador, nomeBuscado);
                break;
            }

            case 4:
                printf("Encerrando programa...\n");
            break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 4);

    return 0;
}

void adicionarContato(Contato *contato){
    printf("\nDigite o nome do contato: \n");
    fgets(contato->nome, sizeof(contato->nome), stdin);
    contato->nome[strcspn(contato->nome, "\n")] = '\0';

    printf("\nDigite o telefone do contato: \n");
    fgets(contato->telefone, sizeof(contato->telefone), stdin);
    contato->telefone[strcspn(contato->telefone, "\n")] = '\0';

    printf("\nDigite o email do contato: \n");
    fgets(contato->email, sizeof(contato->email), stdin);
    contato->email[strcspn(contato->email, "\n")] = '\0';
}

void listarContatos(Contato contatos[], int contador){
    printf("\n\n--- Lista de Contatos ---:\n");
    for (int i = 0; i < contador; i++) {
    printf("Contato %d: \n", i + 1);
    printf("Nome: %s\n", contatos[i].nome);
    printf("Telefone: %s\n", contatos[i].telefone);
    printf("Email: %s\n", contatos[i].email);
    printf("-------------------------------------\n");
}

}
void buscarContato(Contato contatos[], int contador, char nomeBuscado[]){
    int encontrado = 0;
    for (int i = 0; i < contador; i++) {
    if (strcmp(contatos[i].nome, nomeBuscado) == 0) { //compara duas strings, se for igual retorna 0
        printf("\n--- Contato Encontrado ---\n");
        printf("Nome: %s\n", contatos[i].nome);
        printf("Telefone: %s\n", contatos[i].telefone);
        printf("Email: %s\n\n", contatos[i].email);
        encontrado = 1;
        break;
        }
    }
    if (!encontrado) { //se diferente de 0, nao encontrou
    printf("\nContato nao encontrado!\n");
    }
}
