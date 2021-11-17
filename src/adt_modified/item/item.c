/* IMPLEMENTASI ITEM.H */

#include "item.h"
#include <stdio.h>

/* KONSTRUKTOR */
void CreateItem(Item *i, int TimeIn, char PickUp, char DropOff, char ItemType, int TimePerish){
    /* KAMUS LOKAL */
    /* ALGORITMA */
    TIMEIN(*i) = TimeIn;
    PICKUP(*i) = PickUp;
    DROPOFF(*i) = DropOff;
    TYPE(*i) = ItemType;
    if (TYPE(*i) == 'P') {
        TIMEPERISH(*i) = TimePerish;
    } else {
        TIMEPERISH(*i) = TIME_UNDEF;
    }
}

/* SETTER DAN GETTER PRIMITIF */
int getTimeIn(Item i){
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return TIMEIN(i);
}

char getPickUp(Item i){
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return PICKUP(i);
}

char getDropOff(Item i){
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return DROPOFF(i);
}

char getItemType(Item i){
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return TYPE(i);
}

int getTimePerish(Item i){
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return TIMEPERISH(i);
}

void setTimePerish(Item *i, int TimePerish){
    /* KAMUS LOKAL */
    /* ALGORITMA */
    TIMEPERISH(*i) = TimePerish;
}


// DRIVER
// int main(){
//     Item i, i1;
//     CreateItem(&i, 2, 'A', 'G', 'N', 100);
//     CreateItem(&i1, 2, 'B', 'H', 'P', 6);
//     printf("Waktu masuk i: %d\n", getTimeIn(i));
//     printf("Waktu masuk i1: %d\n", getTimeIn(i1));
//     printf("Tempat pickup i: %c\n", getPickUp(i));
//     printf("Tempat pickup i1: %c\n", getPickUp(i1));
//     printf("Tempat drop off i: %c\n", getDropOff(i));
//     printf("Tempat drop off i1: %c\n", getDropOff(i1));
//     printf("Tipe item i: %c\n", getItemType(i));
//     printf("Tipe item i1: %c\n", getItemType(i1));
//     printf("Time perish item i: %d\n", getTimePerish(i));
//     printf("Time perish item i1: %d\n", getTimePerish(i1));
//     return 0;
// }