#include <stdio.h>
// #include "todolist.h"
// #include "../pesanan/pesanan.h"
#include "../../game_header.h"

int main() {
    Pesanan p, p3;
    TDList td;
    CreatePesanan(&p, 20, 'B', 'G', 'P', 10);
    CreateListTD(&td);
    if (isEmptyTD(td)) {
        printf("To do list masih kosong\n");
    }
    AddressTD add = allocate(p);
    AddressTD add1 = search(td, p);
    if (add == add1) {
        printf("add dan add1 sama gan\n");
    }
    if (searchPickUpTD(td, 'B')) {
        printf("Ada yang pickup nya di B\n");
    }
    if (searchDropOffTD(td, 'G')) {
        printf("Ada yang didrop off di G\n");
    }
    Pesanan p1 = searchPickUpTDLabel(td, 'B');
    Pesanan p2 = searchDropOffTDLabel(td, 'G');
    insertFirstTD(&td, p1);
    DisplayListToDo(td, 30);
    insertLastTD(&td, p2);
    DisplayListToDo(td, 30);

    deleteFirstTD(&td, &p3);
    DisplayListToDo(td, 30);
    deleteLastTD(&td, &p3);
    DisplayListToDo(td, 30);

    return 0;
}