#include <stdio.h>
#include "../../game_header.h"

int main(){
    ListPointDin l;
    ListElType val; // list
    int i;
    CreateListPointDin(&l, 5);
    if (isEmptyListPoint(l)){
        printf("List masih kosong\n");
    }
    for (i = 0; i < 5; i++){
        LABEL(val) = 'A'+i;
        KOORX(val) = i;
        KOORY(val) = i+1;
        insertLastListPoint(&l, val);
    }
    if (isFullListPoint(l)){
        printf("List sudah full\n");
    }
    displayListPoint(l);
    printf("\n");
    deleteLastListPoint(&l, &val);
    displayListPoint(l);
    printf("\n");
    dealocateListPoint(&l);
    if (isEmptyListPoint(l)){
        printf("List masih kosong\n");
    }
    return 0;
}