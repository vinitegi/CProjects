#include <stdio.h>

int main() {
    int array[5];

    for (int i = 0; i < 5; i++) {
        printf("Enter a value of the vector in position %d of 5 :", i + 1);
            scanf("%i", &array[i]);
    }
    for (int i = 0; i < 5; i++) {
        printf("Double %d is %d\n", *(array + i), *(array + i) * 2);
    }
    return 0;
}
