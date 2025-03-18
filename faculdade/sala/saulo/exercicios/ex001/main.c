#include <stdio.h>

typedef struct {
    char nome[50];
    int idade;
    float media;
}Aluno;

void lerDados(Aluno *aluno);
void imprimirAlunos(Aluno alunos[], int quantidade);
void calcularMediaTurma(Aluno alunos[], int quantidade);

int main(void) {
    int quantidade;
    printf("Quantos alunos possuem na turma?");
    scanf("%d", &quantidade);
    getchar();

    //declarar o numero de structs do tipo aluno, ou seja, quantos alunos existem
    Aluno alunos[quantidade];

    for (int i = 0; i < quantidade; i++) {
        lerDados(&alunos[i]);//cada 'i' representa um aluno diferente dentro do programa
    }
    imprimirAlunos(alunos, quantidade);
    calcularMediaTurma(alunos, quantidade);


    return 0;
}

void lerDados(Aluno *aluno) {//passa um ponteiro (*aluno) pois tem que alterar o conteudo das variaveis
    //nome
    printf("Digite o nome do aluno: ");
    fgets(aluno->nome, sizeof(aluno->nome), stdin);
    //idade
    printf("Digite a idade do aluno: ");
    scanf("%d", &aluno->idade);
    //media
    printf("Digite a media do aluno: ");
    scanf("%f", &aluno->media);
    getchar();
}

void imprimirAlunos(Aluno alunos[], int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        printf("Nome: %s\n"
               "Idade: %.2d\n"
               "Media: %.2f\n", alunos[i].nome, alunos[i].idade, alunos[i].media);
    }
}

void calcularMediaTurma(Aluno alunos[], int quantidade) {
    float soma = 0;
    //somando todas as notas
    for (int i = 0; i < quantidade; i++) {
        soma += alunos[i].media;
    }
    float media = soma / quantidade;
    printf("Media geral da turma: %.2f\n", media);

}