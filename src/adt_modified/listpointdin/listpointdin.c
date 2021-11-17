/* IMPLEMENTASI MODUL LIST POINT DIN */

#include "listpointdin.h"
#include <stdio.h>
#include <stdlib.h>

/* ***** KONSTRUKTOR ***** */
/* Konstruktor : create list kosong  */
void CreateListPointDin(ListPointDin *l, int capacity){
    /* KAMUS LOKAL */
    /* ALGORITMA */
    CAPACITY(*l) = capacity;
    NEFF(*l) = 0;
    BUFFER(*l) = (ListElType*) malloc (capacity * sizeof(ListElType));
}

void dealocateListPoint(ListPointDin *l){
    /* KAMUS LOKAL */
    /* ALGORITMA */
    CAPACITY(*l) = 0;
    NEFF(*l) = IDX_UNDEF;
    free(BUFFER(*l));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmptyListPoint(ListPointDin l){
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return NEFF(l) == 0;
}

boolean isFullListPoint(ListPointDin l){
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return NEFF(l) == CAPACITY(l);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readListPoint(ListPointDin *l){
    /* KAMUS LOKAL */
    /* ALGORITMA */
}

void displayListPoint(ListPointDin l){
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    if (isEmptyListPoint(l)){
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
void insertLastListPoint(ListPointDin *l, ListElType val){
    /* KAMUS LOKAL */
    /* ALGORITMA */
    LISTELMT(*l, NEFF(*l)) = val;
    NEFF(*l) += 1;
}
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLastListPoint(ListPointDin *l, ListElType *val){
    /* KAMUS LOKAL */
    /* ALGORITMA */
    *val = LISTELMT(*l, NEFF(*l) - 1);
    NEFF(*l) -= 1;
}

// mendpatkan indeks point dari list of point
int getIdxPoint(ListPointDin l, POINT p)
{
    boolean found = false;
    int i=0;
    while (!(found) && (i<NEFF(l))) {
        if (Absis(p) == ELMTX(l, i) && (Ordinat(p) == ELMTY(l,i))) {
            return i;
        }
        i += 1;
    }
}