/* IMPLEMENTASI MODUL LIST POINT DIN */

#include "listpointdin.h"
#include <stdio.h>
#include <stdlib.h>

/* ***** KONSTRUKTOR ***** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListPointDin *l, int capacity){
    /* KAMUS LOKAL */
    /* ALGORITMA */
    CAPACITY(*l) = capacity;
    NEFF(*l) = 0;
    BUFFER(*l) = (ElType*) malloc (capacity * sizeof(ElType));
}

void dealocate(ListPointDin *l){
    /* KAMUS LOKAL */
    /* ALGORITMA */
    CAPACITY(*l) = 0;
    NEFF(*l) = IDX_UNDEF;
    free(BUFFER(*l));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListPointDin l){
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return NEFF(l) == 0;
}

boolean isFull(ListPointDin l){
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return NEFF(l) == CAPACITY(l);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListPointDin *l){
    /* KAMUS LOKAL */
    /* ALGORITMA */
}

void displayList(ListPointDin l){
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    if (isEmpty(l)){
        printf("[]");
    } else {
        printf("[");
        for (i = 0; i <= NEFF(l) - 1; i++) {
            if (i != 0) {
                printf(",");
            }
            printf("%c (%d,%d)", ELMTLABEL(l, i), ELMTX(l, i), ELMTY(l,i));
        }
        printf("]");
    }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListPointDin *l, ElType val){
    /* KAMUS LOKAL */
    /* ALGORITMA */
    ELMT(*l, NEFF(*l)) = val;
    NEFF(*l) += 1;
}
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListPointDin *l, ElType *val){
    /* KAMUS LOKAL */
    /* ALGORITMA */
    *val = ELMT(*l, NEFF(*l) - 1);
    NEFF(*l) -= 1;
}