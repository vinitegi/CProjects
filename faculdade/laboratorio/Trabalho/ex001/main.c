#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPROMISSO	100

typedef struct {
	int hora;
	int minutos;
	int segundos;
}Horario;

typedef struct {
	int dia;
	int mes;
	int ano;
}Data;

typedef struct {
	Data data;
	Horario horario;
	char Descricao[100];
}Compromisso;

Compromisso agenda[MAX_COMPROMISSO];
int *total = 0;

void cadastrarCompromisso(Compromisso agenda[], int *total);
void excluirCompromisso(Compromisso agenda[], int *total);
void mostrarCompromisso(Compromisso agenda[], int total);
int existeCompromisso(Compromisso agenda[], int total, Data data, Horario horario);

int main(void) {
	printf("Hello, World!\n");
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
	getchar();
		fgets(agenda[*total].Descricao, sizeof(agenda[*total].Descricao), stdin);
		agenda[*total].Descricao[strcspn(agenda[*total].Descricao, "\n")] = '\0';

	(*total)++;
	printf("Compromisso adicionado com sucesso!\n");
}

void excluirCompromisso(Compromisso agenda[], int *total){
//total--;
}
void mostrarCompromisso(Compromisso agenda[], int total){
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
int existeCompromisso(Compromisso agenda[], int total, Data data, Horario horario){
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