#include <stdio.h>
#include <string.h>

union pessoa { //union sao uteis para economizar memoria alocada, visto que o valor anterior sempre sera sobrescrito pelo seguinte.
    char nome[100];
    int idade;
};

int main(){
    union pessoa pes;

    strcpy(pes.nome, "oTegi");
    printf("Dados de: %s \n", pes.nome);

    pes.idade = 39;
    printf("Ele tem: %i anos \n", pes.idade);

    printf("O tamanho da variavel 'pes' eh: %lld", sizeof(pes));
    return 0;
}
