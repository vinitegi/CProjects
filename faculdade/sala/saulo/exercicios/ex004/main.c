#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pss.h"

#define MAX 1000

typedef struct {
   unsigned int id, lado1, lado2, lado3;
    char tipo[12];
}Triangulo;

const long TAM_TRIANGULO = sizeof(Triangulo);

//cadastros
void cadastrarTriangulos(Triangulo t[], int *total);
void classificarTriangulos(Triangulo *t);

//arquivos
void salvarNoArquivo (Triangulo t[], int total);
int carregarDoArquivo (Triangulo t[], int *total); //carrega os triangulos do arquivo para o programa

//listagem
void listarTodos(Triangulo t[], int total);
void listarEsquilateros(Triangulo t[], int total);
void listarIsosceles(Triangulo t[], int total);
void listarEscaleno(Triangulo t[], int total);

//mudanca
void alterarTriangulo(Triangulo t[], int total);

int main() {
    Triangulo t[MAX];
    int total = 0;
    int opcao;

    if (carregarDoArquivo(t, &total)) {
        printf("%ld registros carregados (%ld bytes).\n", total, TAM_TRIANGULO * total);
    } else {
        printf("Nenhum dado carregado!\n");
    }

    //menu

    do {
        printf("\n****************************************\n"
        "Menu:\n"
        "1 - Cadastrar triangulo\n"
        "2 - Listar todos os triangulos\n"
        "3 - Listar somente os equilateros\n"
        "4 - Listar somente os isosceles\n"
        "5 - Listar somente os escalenos\n"
        "6 - Alterar dados\n"
        "0 - Sair\n"
        "****************************************\n");

        opcao = input_d("Digite a acao desejada: ");

        if (opcao == 0) {
            printf("Encerrando o programa!\n");
            break;
        }

        switch (opcao) {
            case 1:
                cadastrarTriangulos(t, &total);
                salvarNoArquivo(t, total);
                break;

            case 2:
                listarTodos(t, total);
                break;

            case 3:
                listarEsquilateros(t, total);
                break;

            case 4:
                listarIsosceles(t, total);
                break;

            case 5:
                listarEscaleno(t, total);
                break;

            case 6:
                alterarTriangulo(t, total);
                salvarNoArquivo(t, total);
                break;

            default:
                printf("Opcao invalida!]\n");
        }
    } while (1); //enqunto for verdadeiro

    return 0;
}

//cadastros
void cadastrarTriangulos(Triangulo t[], int *total){
    if (*total >= MAX) {
        printf("Limite de triangulos atingidos!\n");
        return;
    }

    t[*total].lado1 = input_d("Digite o lado 1 do triangulo: ");
    t[*total].lado2 = input_d("Digite o lado 2 do triangulo: ");
    t[*total].lado3 = input_d("Digite o lado 3 do triangulo: ");
    t[*total].id = *total + 1;

    classificarTriangulos(&t[*total]);

    (*total)++;
    printf("Triangulo cadastrado com sucesso!\n");
} //finalizada
void classificarTriangulos(Triangulo *t){
    if (t->lado1 + t->lado2 <= t->lado3 ||
    t->lado1 + t->lado3 <= t->lado2 ||
    t->lado2 + t->lado3 <= t->lado1) {
        strcpy(t->tipo, "nao existe");
    } else if (t->lado1 == t->lado2 && t->lado2 == t->lado3) {
        strcpy(t->tipo, "equilatero");
    } else if (t->lado1 == t->lado2 || t->lado1 == t->lado3 || t->lado2 == t->lado3) {
        strcpy(t->tipo, "isosceles");
    } else {
        strcpy(t->tipo, "escaleno");
    }
} //finalizada

//arquivos
void salvarNoArquivo (Triangulo t[], int total){
    FILE *arq = fopen("triangulos.bin", "wb");
    if (arq == NULL) {
        printf("Erro ao salvar o arquivo!\n");
        return;
    }

    fwrite(t, sizeof(Triangulo), total, arq);
    /*t -> eh um ponteiro para o inicio do vetor de Triangulo, ou seja, &t[0]
     *sizeof(Triangulo) -> o tamanho de cada elemento a ser gravado
     *total -> quantidade de elementos que serao gravados
     *arq -> ponteiro do arquivo
    */

    fclose(arq);

}//finalizada
int carregarDoArquivo (Triangulo t[], int *total){
    FILE *arq = fopen("triangulos.bin", "rb");
    if (arq == NULL) {
        printf("Arquivo nao encontrado ou corrompido!\n");
        return 0;
    }

    while (fread(&t[*total], sizeof(Triangulo), 1, arq)) {
        (*total)++;
    }
    /*ptr → onde os dados vão ser armazenados (&t[*total])
     *size → tamanho de cada elemento a ser lido (sizeof(Triangulo))
     *count → quantos elementos desse tamanho você quer ler (aqui está o 1)
     *      vai ler um elemento por vez. Mas como na se sabe qnts triangulos existem, o while vai rodar ate o final do arquivo
     *stream → ponteiro para o arquivo
     */
    fclose(arq);
    return 1;
 }//finalizada

//listagem
void listarTodos(Triangulo t[], int total){
    if (total == 0) {
        printf("Nenhum triangulo cadastrado ate o momento!\n");
        return;
    }

    printf("-----------------------------------------------\n");
    printf("| %-3s | %-6s | %-6s | %-6s | %-10s |\n", "ID", "Lado1", "Lado2", "Lado3", "Tipo");
    printf("-----------------------------------------------\n");

    for (int i = 0; i < total; i++) {
    printf("| %-3d | %-6d | %-6d | %-6d | %-10s |\n",
           t[i].id, t[i].lado1, t[i].lado2, t[i].lado3, t[i].tipo);
}
    printf("-----------------------------------------------\n");


}
void listarEsquilateros(Triangulo t[], int total){
        if (total == 0) {
        printf("Nenhum triangulo cadastrado ate o momento!\n");
        return;
    }
        printf("Triangulos Equilateros:\n");
        for (int i = 0; i < total; i++) {
            if (strcmp(t[i].tipo, "equilatero") == 0) {
                printf("ID %d: %d %d %d\n", t[i].id, t[i].lado1, t[i].lado2, t[i].lado3);
            } else {
                printf("Nenhum triangulo Equilatero cadastrado no momento!\n");
            }
        }


}//finalizada
void listarIsosceles(Triangulo t[], int total){
    if (total == 0) {
        printf("Nenhum triangulo cadastrado ate o momento!\n");
        return;
    }
        printf("Triangulos Isosceles:\n");
        for (int i = 0; i < total; i++) {
            if (strcmp(t[i].tipo, "isosceles") == 0) {
                printf("ID %d: %d %d %d\n", t[i].id, t[i].lado1, t[i].lado2, t[i].lado3);
            } else {
                printf("Nenhum triangulo Isosceles cadastrado no momento!\n");
            }
        }


}//finalizada
void listarEscaleno(Triangulo t[], int total){
    if (total == 0) {
        printf("Nenhum triangulo cadastrado ate o momento!\n");
        return;
    }
        printf("Triangulos Escaleno:\n");
        for (int i = 0; i < total; i++) {
            if (strcmp(t[i].tipo, "escaleno") == 0) {
                printf("ID %d: %d %d %d\n", t[i].id, t[i].lado1, t[i].lado2, t[i].lado3);
            } else {
                printf("Nenhum triangulo Escaleno cadastrado no momento!\n");
            }
        }


}//finalizada

//mudanca
void alterarTriangulo(Triangulo t[], int total){
    int idBusca = input_d("Digite o ID do triangulo que sera modificado:");
    int encontrado = 0;

    if (total == 0) {
        printf("Nenhum triangulo cadastrado ate o momento!\n");
        return;
    }
        for (int i = 0; i < total; i++) {
            if (t[i].id == idBusca) {
                printf("Triangulo atual: %d %d %d\n", t[i].lado1, t[i].lado2, t[i].lado3);

                t[i].lado1 = input_d("Novo lado 1:");
                t[i].lado2 = input_d("Novo lado 2:");
                t[i].lado3 = input_d("Novo lado 3:");
                classificarTriangulos(&t[i]);

                printf("Triangulo alterado com sucesso.\n");
                encontrado = 1;
                break;
            }
        }

        if (!encontrado) {
            printf("Triangulo com ID %d nao encontrado.\n", idBusca);
        }
}//finalizada
