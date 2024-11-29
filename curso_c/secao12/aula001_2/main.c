#include <stdio.h>
#include <string.h>

struct st_aluno {
    char matricula[10];
    char nome[100];
    char curso[50];
    int ano_nascimento;
}aluno[5];

int main() {

    for (int i = 0; i < 5; i++) {
        printf("Informe a matricula do aluno %i: ", i + 1);
        fgets(aluno[i].matricula, 10, stdin);

        printf("Informe o nome do aluno %i: ", i + 1);
        fgets(aluno[i].nome, 100, stdin);

        printf("Informe curso do aluno %i: ", i + 1);
        fgets(aluno[i].curso, 50, stdin);

        printf("Informe o ano de nascimento do aluno %i: ", i + 1);
        scanf("%d", &aluno[i].ano_nascimento);

        getchar();
    }

    for (int i = 0; i < 5; i++){
        printf("============ Dados do Aluno %i ============\n", i + 1);
        printf("Matricula: %s\n", aluno[i].matricula);
        printf("Nome: %s\n", aluno[i].nome);
        printf("Curso: %s\n", aluno[i].curso);
        printf("Ano de Nascimento: %i\n", aluno[i].ano_nascimento);
    }
    return 0;
}