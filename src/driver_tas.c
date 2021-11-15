#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "game_header.h"

void displayTas(Tas t);

int main() {
    /*KAMUS*/
    Item item1, item2, item3, item4, item5;
    Tas t;
    /* ALGORITMA */
    CreateTas(&t);
    printf("Kapasitas tas saat ini adalah %d\n", t.maxTas);
    t.maxTas += 1;
    printf("Kapasitas tas saat ini adalah %d\n", t.maxTas);
    CreateItem(&item1, 1, 'A', 'B', 'N', 2);
    CreateItem(&item2, 1, 'C', 'D', 'H', 5);
    CreateItem(&item3, 1, 'B', 'G', 'N', 4);
    CreateItem(&item4, 1, 'R', 'Z', 'H', 7);
    addItem(&t, item4);
    addItem(&t, item3);
    addItem(&t, item2);
    addItem(&t, item1);
    reduceAllPerishTime(&t);
    displayTas(t);
    reduceAllPerishTime(&t);
    displayTas(t);
}

void displayTas(Tas t) {
    Item val;
    if (isEmptyTas(t)) {
        printf("Tas kosong gan\n");
    } else {
        while (!isEmptyTas(t)) {
            printf("Item dengan tipe %c dari %c ke %c memiliki sisawaktu %d\n", TYPE(TOP(t)), PICKUP(TOP(t)), DROPOFF(TOP(t)), TIMEPERISH(TOP(t)));
            dropItemToVal(&t, &val);
        }
    }
}