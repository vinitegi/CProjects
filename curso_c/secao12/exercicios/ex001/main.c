#include <stdio.h>
#include <string.h>

// Definição da struct com typedef
typedef struct {
    char nome[100];
    int idade;
    char endereco[200];
} pessoa;

int main() {
    pessoa pessoa1;

    printf("Informe o seu nome:\n");
    fgets(pessoa1.nome, sizeof(pessoa1.nome), stdin);
    pessoa1.nome[strcspn(pessoa1.nome, "\n")] = '\0'; // Remove o caractere de nova linha

    printf("Informe sua idade:\n");
    scanf("%d", &pessoa1.idade);

    getchar(); // Limpa o buffer do teclado após o scanf

    printf("Informe seu endereco:\n");
    fgets(pessoa1.endereco, sizeof(pessoa1.endereco), stdin);
    pessoa1.endereco[strcspn(pessoa1.endereco, "\n")] = '\0'; // Remove o caractere de nova linha

    printf("\n\n");

    printf("============ Informacoes ============\n");
    printf("Nome: %s\n", pessoa1.nome);
    printf("Idade: %d\n", pessoa1.idade);
    printf("Endereco: %s\n", pessoa1.endereco);

    return 0;
}
