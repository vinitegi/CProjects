#include <stdio.h>
#include <time.h>

/*============ Data e Tempo ============
 *
 *      clock() -> retorna o numero de clock decorridos desde que o programa foi inicado
 *      time() -> retorna o tempo atual do calendario
 *      localtime() -> converte o calor time para uma hr local
 *
 */


int main() {

    printf("============ clock() ============\n");
    clock_t inicio_t, fim_t;
    double total_t;

    // Obtendo o tempo de início
    inicio_t = clock();

    printf("Realizando um loop grande, inicio_t = %ld\n", inicio_t);

    for (int i = 0; i < 100000000; i++) {
        // Apenas para consumir tempo
    }

    // Obtendo o tempo de fim
    fim_t = clock();

    printf("Fim do loop, fim_t = %ld\n", fim_t);

    // Calculando o tempo total em segundos
    total_t = ((double)fim_t - (double)inicio_t) / (double)CLOCKS_PER_SEC;
    printf("Clocks por segundo: %ld\n", CLOCKS_PER_SEC);


    printf("O tempo total usado plela CPU foi: %.6lf segundos\n", total_t);
    printf("Finalizando o programa\n");

    printf("\n============ time() ============\n");

    time_t segundos;

    segundos = time(NULL);

    printf("Horas desde 1 de Janeiro de 1970: %lld\n", segundos / 3600);

    printf("\n============ localtime() ============\n");

    time_t tempobruto;
    struct tm *info;

    time(&tempobruto);
    info = localtime(&tempobruto);

    printf("Data e hora local: %s", asctime(info));
    return 0;
}
