#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pss.h"

typedef struct {
    int dia, mes, ano;
    double litragem;
    char nome_arq[14];
} Registro;

//como o usuario nao vai digitar nada, nao eh necessario passar parametros
void inserirLote(); //finalizada
void eliminarLote();
void gerarSomatorioMensal();
void gerarListagem();
void criarBinario(); //finalizada


int main(void) {
    int opcao;

    criarBinario();

    do {
        printf("\n******************************\n");
        printf("1 - Inserir lote\n");
        printf("2 - Eliminar lote\n");
        printf("3 - Somatorio mensal (CSV)\n");
        printf("4 - Listagem (CSV)\n");
        printf("5 - Encerrar\n");
        printf("******************************\n");
        opcao = input_d("Digite uma opcao: [1-5]: ");

        switch (opcao) {
            case 1:
                inserirLote();
                break;
            case 2:
                eliminarLote();
                break;
            case 3:
                gerarSomatorioMensal();
                break;
            case 4:
                gerarListagem();
                break;
            case 5:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}

void inserirLote(){
    char lote[14]; //lote sera o nome do arquivo
    input_s("Digite o nome do lote (ex: 20_05_2025.txt): ", lote, sizeof(lote)); //ex: 02/04/2025

    FILE *arq_txt = fopen(lote, "r");
    if (!arq_txt) {
        printf("Erro ao abrir o arquivo .txt\n");
        return;
    }

    FILE *arq_bin = fopen("dados.bin", "ab");
    if (!arq_bin) {
        printf("Erro ao abrir o arquivo binario\n");
        return;
    }

    Registro r;
    strncpy(r.nome_arq, lote, 13);
    r.nome_arq[13] = "\0";

    while (fscanf(arq_txt, "%d/%d/%d %lf", &r.dia, &r.mes, &r.ano, &r.litragem) == 4) { //enquanto ler os quatro valores com sucesso, permanece no loop
        fwrite(&r, sizeof(Registro), 1, arq_bin); //uma linha por vez. struct -> arquivo
    }

    printf("Dados '%s' inseridos com sucesso!\n", r.nome_arq);

    fclose(arq_txt);
    fclose(arq_bin);

    gerarListagem();
}
void eliminarLote() {
    char lote[14];
    input_s("Digite o nome do lote a ser removido (ex: 20_05_2025.txt): ", lote, sizeof(lote));

    FILE *orig = fopen("dados.bin", "rb");
    if (!orig) {
        printf("Arquivo dados.bin nao encontrado.\n");
        return;
    }

    FILE *temp = fopen("temp.bin", "wb");
    if (!temp) {
        printf("Erro ao criar arquivo temporario.\n");
        fclose(orig);
        return;
    }
    //cria um novo arquivo temporario 'temp.bin' para armazenar apenas os registros que nao correspondem ao lote.

    Registro r;
    int removidos = 0;

    while (fread(&r, sizeof(Registro), 1, orig) == 1) { //arq -> struct
    //le uma linha por vez do arq original 'dados.bin'
    //dd / mm / aa litragem nome_arq

        if (strcmp(r.nome_arq, lote) != 0) {
        //se o nome no struct for diferente de 'lote'
            fwrite(&r, sizeof(Registro), 1, temp);
            //copia os registros que nao sao do lote informado
        } else {
            removidos++;
        }
    }

    fclose(orig);
    fclose(temp);

    // Substitui o arquivo original pelo temporário
    remove("dados.bin");
    rename("temp.bin", "dados.bin");

    printf("Remocao concluida. %d registros do lote '%s' foram removidos.\n", removidos, lote);

    gerarListagem(); // Atualiza o CSV após remoção
}

void gerarSomatorioMensal(){

}
void gerarListagem(){

}
void criarBinario(){
    FILE *bin = fopen("dados.bin", "rb");// tenta abrir em modo leitura binária
    if (bin == NULL) {// se o arq nao existir
        bin = fopen("dados.bin", "wb");// cria um arq binario novo
        if (bin == NULL) {
           printf("Erro ao criar arquivo dados.bin\n");
            return;
        }
        printf("Arquivo dados.bin criado com sucesso.\n");
        fclose(bin); //dps de criar, fecha o arq binario
    } else {// ja existia um arq binario antes
        fclose(bin);
    }
}