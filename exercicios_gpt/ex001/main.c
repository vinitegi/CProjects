#include <stdio.h>

void trocar (int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a;
    int b;

    printf("Type 'a' value:\n");
        scanf("%i", &a);
    printf("Type 'b' value:\n");
        scanf("%i", &b);

    printf("\n\nantes da troca:\n a = %d\n b = %d\n", a, b);

    trocar(&a, &b);

    printf("\n\ndepois da troca:\n a = %d\n b = %d", a, b);



    return 0;
}