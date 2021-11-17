#include <stdio.h>
#include "todolist.h"
#include "../pesanan/pesanan.h"

int main() {
    Pesanan p;
    TDList td;
    CreatePesanan(&p, 20, 'B', 'G', 'P', 10);
    CreateListTD(&td);
    if (isEmptyTD(td)) {
        printf("To do list masih kosong\n");
    }

    return 0;
}