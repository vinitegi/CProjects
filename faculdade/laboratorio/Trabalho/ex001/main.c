#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPROMISSO 100

typedef struct {
	int hora;
	int minutos;
	int segundos;
} Horario;

typedef struct {
	int dia;
	int mes;
	int ano;
} Data;

typedef struct {
	Data data; // o compromisso precisa ter uma data
	Horario horario; // o compromisso precisa ter um horario
	char Descricao[100];
} Compromisso;

Compromisso agenda[MAX_COMPROMISSO];
int total = 0; // contador de compromissos

void cadastrarCompromisso(Compromisso agenda[], int *total);
void excluirCompromisso(Compromisso agenda[], int *total);
void mostrarCompromisso(Compromisso agenda[], int total);
int existeCompromisso(Compromisso agenda[], int total, Data data, Horario horario);

int main(void) {
	int opcao;

	do {
		printf("\n==== MENU AGENDA ====\n");
		printf("1. Cadastrar compromisso\n");
		printf("2. Excluir compromisso\n");
		printf("3. Mostrar compromissos de um mês\n");
		printf("4. Sair\n");
		printf("Escolha uma opção: ");
		scanf("%d", &opcao);

		switch(opcao) {
			case 1:
				cadastrarCompromisso(agenda, &total);
				break;
			case 2:
				excluirCompromisso(agenda, &total);
				break;
			case 3:
				mostrarCompromisso(agenda, total);
				break;
			case 4:
				printf("Saindo...\n");
				break;
			default:
				printf("Opção inválida! Tente novamente.\n");
		}
	} while(opcao != 4);

	return 0;
}

void cadastrarCompromisso(Compromisso agenda[], int *total) {
	if (*total >= MAX_COMPROMISSO) {
		printf("Limite de compromissos atingido!");
		return;
	}

	printf("Digite a data (dd / mm / aaaa): ");
	scanf("%d %d %d", &agenda[*total].data.dia, &agenda[*total].data.mes, &agenda[*total].data.ano);

	printf("Digite a hora (hh : mm : ss): ");
	scanf("%d %d %d", &agenda[*total].horario.hora, &agenda[*total].horario.minutos, &agenda[*total].horario.segundos);

	if (existeCompromisso(agenda, *total, agenda[*total].data, agenda[*total].horario)) {
		printf("Compromisso existe!\n");
		return;
	}

	printf("Insira a descricao do compromisso: ");
	getchar(); //limpar buffer
	fgets(agenda[*total].Descricao, sizeof(agenda[*total].Descricao), stdin);
	agenda[*total].Descricao[strcspn(agenda[*total].Descricao, "\n")] = '\0';

	(*total)++;
	printf("Compromisso adicionado com sucesso!\n");
}

void excluirCompromisso(Compromisso agenda[], int *total) {
	Data dataVerificador;
	Horario horarioVerificador;
	int encontrado = 0;

	printf("Digite a data (dd / mm / aaaa): ");
	scanf("%d %d %d", &dataVerificador.dia, &dataVerificador.mes, &dataVerificador.ano);
	printf("Digite a hora (hh : mm : ss): ");
	scanf("%d %d %d", &horarioVerificador.hora, &horarioVerificador.minutos, &horarioVerificador.segundos);

	for (int i = 0; i < *total; i++) {
		if (dataVerificador.dia == agenda[i].data.dia &&
			dataVerificador.mes == agenda[i].data.mes &&
			dataVerificador.ano ==  agenda[i].data.ano &&
			horarioVerificador.hora == agenda[i].horario.hora &&
			horarioVerificador.minutos == agenda[i].horario.minutos &&
			horarioVerificador.segundos == agenda[i].horario.segundos) {

			for (int j = i; j < *total - 1; j++) {
				agenda[j] = agenda[j + 1];
				// remove o compromisso do índice 'i' movendo todos os compromissos que vem dps uma posição para trás
				// vai evitar buracos na agenda e mantem os compromissos organizados
			}
			(*total)--;
			printf("Compromisso removido!\n");
			encontrado = 1;
			break;
		}
	}
	if (!encontrado) {
		printf("Compromisso nao encontrado!\n");
	}
}

void mostrarCompromisso(Compromisso agenda[], int total) {
	int mes;
	printf("Digite o mes: ");
	scanf("%d", &mes);

	printf("\nCompromissos do mes\n");
	for (int i = 0; i < total; i++) {
		if (agenda[i].data.mes == mes) {
			printf("%02d/%02d/%04d - %02d:%02d:%02d - %s\n",
				   agenda[i].data.dia, agenda[i].data.mes, agenda[i].data.ano,
				   agenda[i].horario.hora, agenda[i].horario.minutos, agenda[i].horario.segundos,
				   agenda[i].Descricao);
		}
	}
}

int existeCompromisso(Compromisso agenda[], int total, Data data, Horario horario) {
	for (int i = 0; i < total; i++) {
		//verifica se ja existe algum compromisso na msm data inserida na função cadastrarCompromisso
		if (agenda[i].data.dia == data.dia && //data.dia é inserido na função cadastrarCompromisso
			agenda[i].data.mes == data.mes &&
			agenda[i].data.ano == data.ano &&
			agenda[i].horario.hora == horario.hora &&
			agenda[i].horario.minutos == horario.minutos &&
			agenda[i].horario.segundos == horario.segundos) {
			return 1;
		}
	}
	return 0;
}
