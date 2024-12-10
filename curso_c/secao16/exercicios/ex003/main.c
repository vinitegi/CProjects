#include <stdio.h>
#include <stdlib.h>

int main() {
    int tamanho;
    char *ptr;

    printf("Informe o tamanho da string: ");
    scanf("%i", &tamanho);
    getchar();

    ptr = (char *)calloc(tamanho + 1, sizeof(char));

    if (ptr == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    printf("Informe a string: ");
    fgets(ptr, tamanho + 1, stdin);

    printf("String sem vogais: ");
    for (int i = 0; i < tamanho; i++) {
        if (*(ptr + i) != 'a' && *(ptr + i) != 'A' &&
            *(ptr + i) != 'e' && *(ptr + i) != 'E' &&
            *(ptr + i) != 'i' && *(ptr + i) != 'I' &&
            *(ptr + i) != 'o' && *(ptr + i) != 'O' &&
            *(ptr + i) != 'u' && *(ptr + i) != 'U') {
            printf("%c", *(ptr + i));
            }
    }
    printf("\n");

    free(ptr);
    ptr = NULL;

    return 0;
}
