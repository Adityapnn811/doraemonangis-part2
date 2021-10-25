/*MODUL LIST DINAMIS OF KOOR BANGUNAN*/

#ifndef LISTPOINTDIN_H
#define LISTPOINTDIN_H

#include "../models/boolean.h"
#include "../adt/point.h"

/*  Kamus Umum */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/

/* Definisi elemen dan tipe data */
typedef struct 
{
    char label;
    POINT p;
} ListElType;
typedef int IdxType;
typedef struct {
    ListElType *buffer;
    int Neff;
    int capacity;
} ListPointDin;

/* ***** SELEKTOR ***** */
#define NEFF(l) (l).Neff
#define BUFFER(l) (l).buffer
#define LISTELMT(l, i) (l).buffer[i]
#define ELMTX(l, i) (l).buffer[i].p.X
#define ELMTY(l, i) (l).buffer[i].p.Y
#define ELMTLABEL(l, i) (l).buffer[i].label
#define CAPACITY(l) (l).capacity
#define KOORX(val) (val).p.X
#define KOORY(val) (val).p.Y
#define LABEL(val) (val).label

/* ***** KONSTRUKTOR ***** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListPointDin *l, int capacity);
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

void dealocate(ListPointDin *l);
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListPointDin l);
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isFull(ListPointDin l);
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListPointDin *l);
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */

void displayList(ListPointDin l);
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListPointDin *l, ListElType val);
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListPointDin *l, ListElType *val);
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void growList(ListPointDin *l, int num);
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

void shrinkList(ListPointDin *l, int num);
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */

void compactList(ListPointDin *l);
/* Proses : Mengurangi capacity sehingga nEff = capacity */
/* I.S. List tidak kosong */
/* F.S. Ukuran nEff = capacity */



#endif