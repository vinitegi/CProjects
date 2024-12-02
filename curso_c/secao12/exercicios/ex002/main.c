#include <stdio.h>
#include <string.h>


//pessoa1.endereco[strlen(pessoa1.endereco) - 1] = '\0';

typedef struct {
    char nome[100];
    int matricula;
    char curso[100];
} aluno;

int main() {
    aluno alunos[5];

    for (int i = 0; i < 5; i++) {
        printf("Informe os dados do aluno %d:\n", i + 1);

        printf("Nome: ");
        fgets(alunos[i].nome, 100, stdin);
        alunos[i].nome[strlen(alunos[i].nome) - 1] = '\0';

        printf("Matricula: ");
        scanf("%i", &alunos[i].matricula);

        printf("Curso: ");
        fgets(alunos[i].curso, 100, stdin);
        alunos[i].curso[strlen(alunos[i].curso) - 1] = '\0';
        printf("\n\n");
    }

    for (int i = 0; i < 5; i++) {
        printf("Aluno %d:\n", i + 1);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Matricula: %d\n", alunos[i].matricula);
        printf("Curso: %s\n", alunos[i].curso);
        printf("\n");
    }

    return 0;
}