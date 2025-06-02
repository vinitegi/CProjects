#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pss.h"

typedef struct {
    int dia, mes, ano;
    double litragem;
    char nome_arq[15];
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
    char lote[15]; //lote sera o nome do arquivo
    input_s("Digite o nome do lote que sera inserido (ex: 20_05_2025.txt): ", lote, sizeof(lote)); //ex: 02/04/2025

    FILE *arq_bin_checagem = fopen("dados.bin", "rb");
    if (arq_bin_checagem) {
        Registro r_check;
        while (fread(&r_check, sizeof(Registro), 1, arq_bin_checagem) == 1) {
            if (strcmp(r_check.nome_arq, lote) == 0) {
                printf("Lote '%s' ja foi inserido anteriormente.\n", lote);
                fclose(arq_bin_checagem);
                return;
            }
        }
        fclose(arq_bin_checagem);
    }

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
    strncpy(r.nome_arq, lote, sizeof(r.nome_arq) - 1);
    r.nome_arq[sizeof(r.nome_arq) - 1] = '\0';;

    while (fscanf(arq_txt, "%d/%d/%d %lf", &r.dia, &r.mes, &r.ano, &r.litragem) == 4) { //enquanto ler os quatro valores com sucesso, permanece no loop
        fwrite(&r, sizeof(Registro), 1, arq_bin); //uma linha por vez. struct -> arquivo
    }

    printf("Dados '%s' inseridos com sucesso!\n", r.nome_arq);

    fclose(arq_txt);
    fclose(arq_bin);

    gerarListagem();
    gerarSomatorioMensal();
}
void eliminarLote() {
    char lote[15];
    input_s("Digite o nome do lote que sera removido (ex: 20_05_2025.txt): ", lote, sizeof(lote));

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
    //le uma linha por vez do arq original 'dados.bin' e coloca no struct 'r'
        //cada vez q le um registro, oq houver em 'r' sera sobreposto

        if (strcmp(r.nome_arq, lote) != 0) {
        //se o nome no struct for diferente de 'lote'
            fwrite(&r, sizeof(Registro), 1, temp);
            //copia os registros que nao sao do lote informado
        } else {
            removidos++;
        }
    }
    //dd / mm / aa litragem nome_arq -> como esta no arquivo

    fclose(orig);
    fclose(temp);

    // Substitui o arquivo original pelo temporário
    remove("dados.bin");
    rename("temp.bin", "dados.bin");

    printf("Remocao concluida. %d registros do lote '%s' foram removidos.\n", removidos, lote);

    gerarListagem();
    gerarSomatorioMensal();
}

void gerarSomatorioMensal(){
    FILE *arq_bin = fopen("dados.bin", "rb");
    if (!arq_bin) {
        printf("Nao ha dados para gerar a listagem.\n");
        return;
    }

    typedef struct {
        int mes;
        double litragemTotal;
    }Agrupamento;

    Agrupamento grupoAnual[12];
    Registro r;

    for (int i = 0; i < 12; i++) {
        grupoAnual[i].mes = i + 1;
        grupoAnual[i].litragemTotal = 0.0;
    }

    while (fread(&r, sizeof(Registro), 1, arq_bin) == 1) {
        grupoAnual[r.mes - 1].litragemTotal += r.litragem;
    }
    fclose(arq_bin);

    FILE *csv = fopen("somatorio.csv", "w");
    if (!csv) {
        printf("Erro ao criar arquivo listagem.csv\n");
        fclose(arq_bin);
        return;
    }
    fprintf(csv, "Mes;Litragem\n");

    for (int i = 0; i < 12; i++) {
        fprintf(csv, "%02d;%.2lf\n", grupoAnual[i].mes, grupoAnual[i].litragemTotal);
    }

    fclose(csv);

    printf("Relatorio mensal gerado com sucesso: somatorio.csv\n");
}

void gerarListagem(){

    FILE *arq_bin = fopen("dados.bin", "rb");
    if (!arq_bin) {
        printf("Nao ha dados para gerar a listagem.\n");
        return;
    }

    FILE *csv = fopen("listagem.csv", "w");
    if (!csv) {
        printf("Erro ao criar arquivo listagem.csv\n");
        fclose(arq_bin);
        return;
    }

    //cabecalho do csv
    fprintf(csv, "Data;Litragem;Lote\n");

    Registro r;
    while (fread(&r, sizeof(Registro), 1, arq_bin) == 1) {
        fprintf(csv, "%02d/%02d/%04d;%.2lf;%s\n", r.dia, r.mes, r.ano, r.litragem, r.nome_arq);
    }

    fclose(arq_bin);
    fclose(csv);

    printf("Arquivo listagem.csv gerado com sucesso!\n");

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