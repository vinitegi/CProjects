#include <stdio.h>

typedef struct {
    char nome[50];
    int idade;
    float nota;
} Aluno;

void lerDados(Aluno *aluno);
void imprimirAlunos(Aluno alunos[], int quantidade);
void calcularMediaTurma(Aluno alunos[], int quantidade);

int main(void) {
    int quantidade;
    printf("Quantos alunos possuem na turma?");
    scanf("%d", &quantidade);
    getchar();

    // Declarar o número de structs do tipo Aluno, ou seja, quantos alunos existem
    Aluno alunos[quantidade];

    for (int i = 0; i < quantidade; i++) {
        lerDados(&alunos[i]); // Cada 'i' representa um aluno diferente dentro do programa
    }
    imprimirAlunos(alunos, quantidade);
    calcularMediaTurma(alunos, quantidade);

    return 0;
}

void lerDados(Aluno *aluno) { // Passa um ponteiro (*aluno) pois tem que alterar o conteúdo das variáveis
    // Nome
    printf("Digite o nome do aluno: ");
    fgets(aluno->nome, sizeof(aluno->nome), stdin);
    // Idade
    printf("Digite a idade do aluno: ");
    scanf("%d", &aluno->idade);
    // Nota
    printf("Digite a nota do aluno: ");
    scanf("%f", &aluno->nota);
    getchar();
}

void imprimirAlunos(Aluno alunos[], int quantidade) {
    printf("\nLista de Alunos:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("\nAluno %d\n", i + 1); // Começando a contagem do aluno em 1
        printf("Nome: %s", alunos[i].nome);
        printf("Idade: %d\n", alunos[i].idade);
        printf("Nota: %.2f\n", alunos[i].nota);
    }
}

void calcularMediaTurma(Aluno alunos[], int quantidade) {
    float soma = 0;
    // Somando todas as notas
    for (int i = 0; i < quantidade; i++) {
        soma += alunos[i].nota;
    }
    float media = soma / quantidade;
    printf("\nMédia geral da turma: %.2f\n", media);
}