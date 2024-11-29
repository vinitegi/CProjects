#include <stdio.h>
#include <string.h>

struct st_contato {
    char nome[100];
    int ano_nascimento;
    char telefone[20];
    char email[100];
};

struct st_agenda {
    struct st_contato contatos[100];
}agenda;

int main() {

    for (int i = 0; i < 100; i++) {
        printf("Informe o nome %i: ", i + 1);
        fgets(agenda.contatos[i].nome, 100, stdin);

        printf("Informe ano de nascimento %i: ", i + 1);
        scanf("%i",agenda.contatos[i].ano_nascimento);

        getchar();

        printf("Informe o telefone %i: ", i + 1);
        fgets(agenda.contatos[i].telefone, 20, stdin);

        printf("Informe o email %i: ", i + 1);
        fgets(agenda.contatos[i].email, 100, stdin);

    }

    for (int i = 0; i < 100; i++){
        printf("============ Agenda de Contato - %i ============\n", i + 1);
        printf("Nome: %s\n", strtok(agenda.contatos[i].nome, "\n"));
        printf("Ano de Nascimento: %i\n", strtok(agenda.contatos[i].ano_nascimento, "\n"));
        printf("Telefone: %s\n", strtok(agenda.contatos[i].telefone, "\n"));
        printf("E-mail: %s\n", strtok(agenda.contatos[i].email, "\n"));
    }
    return 0;
}