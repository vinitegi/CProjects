#include <stdio.h>

int main() {
    FILE *arq;
    char c;

    arq = fopen("arquivo", "r");

    if (arq) {
        while ((c = getc(arq)) != EOF) { //EOF -> END OF FILE
            printf("%c", c);

        }
    } else {
        printf("nao achei o arquivo");
    }
    fclose(arq);
    printf("teste");
    return 0;
}
