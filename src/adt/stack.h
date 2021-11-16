/* File : stack.h */
/* Definisi ADT Stack dengan representasi array secara eksplisit dan alokasi statik */
/* TOPStack adalah alamat elemen puncak */

#ifndef STACK_H
#define STACK_H

#include "../modules/boolean.h"

#define IDX_UNDEF -1
#define CAPACITYStack 100

typedef int ElType;
typedef struct
{
  ElType buffer[CAPACITYStack]; /* tabel penyimpan elemen */
  int idxTop;              /* alamat TOPStack: elemen puncak */
} Stack;

/* ********* AKSES (Selektor) ********* */
/* Jika s adalah Stack, maka akses elemen : */
#define IDX_TOPStack(s) (s).idxTop
#define TOPStack(s) (s).buffer[(s).idxTop]

/* *** Konstruktor/Kreator *** */
void CreateStack(Stack *s);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S kosong dengan kondisi sbb: */
/* - Index top bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah s kosong */

/* ************ Prototype ************ */
boolean isEmptyStack(Stack s);
/* Mengirim true jika s kosong: lihat definisi di atas */
boolean isFullStack(Stack s);
/* Mengirim true jika tabel penampung nilai s stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void pushStack(Stack *s, ElType val);
/* Menambahkan val sebagai elemen Stack s */
/* I.S. s mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. val menjadi TOPStack yang baru,IDX_TOPStack bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void popStack(Stack *s, ElType *val);
/* Menghapus val dari Stack s */
/* I.S. s tidak mungkin kosong */
/* F.S. val adalah nilai elemen TOPStack yang lama, IDX_TOPStack berkurang 1 */

#endif
