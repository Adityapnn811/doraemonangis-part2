/**
 * File: stack.c
 * Tanggal: 2021/10/21
 * NIM / Nama: 13520024 / Hilya Fadhilah Imania
 *
 * stack.c
 * Implementasi ADT Stack
 */
#include "stack.h"

/* *** Konstruktor/Kreator *** */
void CreateStack(Stack *s)
{
  /* I.S. sembarang; */
  /* F.S. Membuat sebuah stack S kosong dengan kondisi sbb: */
  /* - Index top bernilai IDX_UNDEF */
  /* Proses : Melakukan alokasi, membuat sebuah s kosong */
  /* ALGORITMA */
  IDX_TOP(*s) = IDX_UNDEF;
}

/* ************ Prototype ************ */
boolean isEmpty(Stack s)
{
  /* Mengirim true jika s kosong: lihat definisi di atas */
  /* ALGORITMA */
  return IDX_TOP(s) == IDX_UNDEF;
}
boolean isFull(Stack s)
{
  /* Mengirim true jika tabel penampung nilai s stack penuh */
  /* ALGORITMA */
  return IDX_TOP(s) == CAPACITY - 1;
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void push(Stack *s, ElType val)
{
  /* Menambahkan val sebagai elemen Stack s */
  /* I.S. s mungkin kosong, tabel penampung elemen stack TIDAK penuh */
  /* F.S. val menjadi TOP yang baru,IDX_TOP bertambah 1 */
  /* ALGORITMA */
  ++IDX_TOP(*s);
  TOP(*s) = val;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void pop(Stack *s, ElType *val)
{
  /* Menghapus val dari Stack s */
  /* I.S. s tidak mungkin kosong */
  /* F.S. val adalah nilai elemen TOP yang lama, IDX_TOP berkurang 1 */
  /* ALGORITMA */
  *val = TOP(*s);
  if (IDX_TOP(*s) == 0)
  {
    IDX_TOP(*s) = IDX_UNDEF;
  }
  else
  {
    --IDX_TOP(*s);
  }
}