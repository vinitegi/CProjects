#include <stdio.h>
#include <string.h>

/*============ Operacoes em Strings ============
 *      strcpy() -> copia de string
 *      strcat() -> concatena strings
 *      strcmp() -> compara duas strings
 *
 *============ Busca ============
 *      strchr -> localiza a primeira ocorrencia de carater de uma string
 *      strtok() -> divide uma string em sub-strings com base em um caracter
 *      strlen() -> retorna o tamanho da string
 */

int main() {

    printf("============ Operacoes em Strings ============\n");

    char str1[20], str2[20];

    strcpy(str1, "Quinta - ");
    strcpy(str2,"feira");

    printf("Hoje eh: %s\n", strcat(str1, str2));

    strcpy(str1, "Laranja");
    strcpy(str2,"Laranja");

    if (strcmp(str1, str2)) { //compara se sao diferentes
        printf("Elas posuem conteudos diferentes!\n");
    } else {
        printf("Elas possuem o mesmo conteudo!\n");
    }

    printf("\n============ Busca ============\n");

    char str3[] = "viniciustegi1235@gmail.com";
    char car = '@';
    char *ret = strchr(str3, car);

    printf("A partir do %c, esta %s\n", car, ret);
    printf("Usuario: %s\n", strtok(str3, "@"));
    printf("Tamanho: %llu\n", strlen(str3));

    return 0;
}