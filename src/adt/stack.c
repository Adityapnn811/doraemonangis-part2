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
  IDX_TOPStack(*s) = IDX_UNDEF;
}

/* ************ Prototype ************ */
boolean isEmptyStack(Stack s)
{
  /* Mengirim true jika s kosong: lihat definisi di atas */
  /* ALGORITMA */
  return IDX_TOPStack(s) == IDX_UNDEF;
}
boolean isFullStack(Stack s)
{
  /* Mengirim true jika tabel penampung nilai s stack penuh */
  /* ALGORITMA */
  return IDX_TOPStack(s) == CAPACITYStack - 1;
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void pushStack(Stack *s, ElType val)
{
  /* Menambahkan val sebagai elemen Stack s */
  /* I.S. s mungkin kosong, tabel penampung elemen stack TIDAK penuh */
  /* F.S. val menjadi TOPStack yang baru,IDX_TOPStack bertambah 1 */
  /* ALGORITMA */
  ++IDX_TOPStack(*s);
  TOPStack(*s) = val;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void popStack(Stack *s, ElType *val)
{
  /* Menghapus val dari Stack s */
  /* I.S. s tidak mungkin kosong */
  /* F.S. val adalah nilai elemen TOPStack yang lama, IDX_TOPStack berkurang 1 */
  /* ALGORITMA */
  *val = TOPStack(*s);
  if (IDX_TOPStack(*s) == 0)
  {
    IDX_TOPStack(*s) = IDX_UNDEF;
  }
  else
  {
    --IDX_TOPStack(*s);
  }
}