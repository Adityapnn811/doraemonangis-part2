#include <stdio.h>
#include "../../game_header.h"

int main() {
    Pesanan p, p1, p2;
    DaftarPesanan dp;
    CreatePesanan(&p, 2, 'B', 'G', 'H', -1);
    CreateDaftar(&dp);
    if (isEmptyDftr(dp)) {
        printf("Memang harusnya kosong\n");
    }
    enqueuePsn(&dp, p);
    if (isEmptyDftr(dp)) {
        printf("Harusnya engga kosong\n");
    }
    dequeuePsn(&dp);
    if (isEmptyDftr(dp)) {
        printf("Memang harusnya kosong\n");
    }
    enqueuePsn(&dp, p);
    dequeuePsntoVal(&dp, &p2);
    if (CmpPesanan(p, p2)) {
        printf("Memang harusnya sama\n");
    }
    printf("Panjang dp harusnya sih 1, coba panjang = %d", lengthDftr(dp));
    return 0;
}