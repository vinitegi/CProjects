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
    return 0;
}
