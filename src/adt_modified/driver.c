#include <stdio.h>
#include "listpointdin.h"

int main(){
    ListPointDin l;
    ElType val;
    int i;
    CreateListDin(&l, 5);
    if (isEmpty(l)){
        printf("List masih kosong\n");
    }
    for (i = 0; i < 5; i++){
        LABEL(val) = 'A';
        KOORX(val) = i;
        KOORY(val) = i;
        insertLast(&l, val);
    }
    if (isFull(l)){
        printf("List sudah full\n");
    }
    displayList(l);
    printf("\n");
    deleteLast(&l, &val);
    displayList(l);
    printf("\n");
    dealocate(&l);
    if (isEmpty(l)){
        printf("List masih kosong\n");
    }
    return 0;
}