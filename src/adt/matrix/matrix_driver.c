#include <stdio.h>
#include "matrix.h"

int main() {
    Matrix m;
    CreateMatrix(10,10,&m);
    if (isIdxValidMatrix(9,9)) {
        printf("Indeks Matriks Valid\n");
    }
    printf("Last Idx Row and Col: %c & %c\n", getLastIdxRow(m), getLastIdxRow(m));
    if (isIdxEffMatrix(m,5,5)) {
        printf("Indeks Matriks Efektif\n");
    }
    displayMatrix(m);
}