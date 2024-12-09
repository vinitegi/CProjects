#include <stdio.h>
#include <ctype.h>


/*
 *=========== Testes para tipos de caracteres ===========
 *      isalnum() -> verifica se o caracter eh alfanumerico (abc749)
 *      isalpha() -> verifica se o caracter eh alfabetico
 *      isdigit() -> verifica se o caracter eh um digito decimal (0123...)
 *      ispunct() -> verifica se o caracter eh uma pontuacao (!?.,)
 *      isspace() -> verifica se o carater eh um espaco e
 *      isupper() -> verifica se o carater eh maiusculo
 *      tolower() -> converte para minusculo
 *      toupper() -> converte para maiusculo
 */

int main() {

    char teste = '4';

    if (isalnum(teste)) {
        printf("Eh alfanumerico!\n");
    } else {
        printf("Nao eh alfanumerico!\n");
    }

    if (isalpha(teste)) {
        printf("Eh alfabetico!\n");
    } else {
        printf("Nao eh alfabetico!\n");
    }

    if (isdigit(teste)) {
        printf("Eh um digito decimal!\n");
    } else {
        printf("Nao eh um digito decimal!\n");
    }

    return 0;
}