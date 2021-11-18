/**
 * File: point.c
 * Tanggal: 2021/09/02
 * NIM / Nama: 13520024 / Hilya Fadhilah Imania
 */
#include <stdio.h>
#include <math.h>
#include "point.h"

/* *** Konstruktor membentuk POINT *** */

POINT MakePOINT(float X, float Y)
{
  /* Membentuk sebuah POINT dari komponen-komponennya */
  /* KAMUS */
  POINT p;

  /* ALGORITMA */
  Absis(p) = X;
  Ordinat(p) = Y;
  return p;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */

void BacaPOINT(POINT *P)
{
  /* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
  /* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
  /* Contoh: 1 2 
   akan membentuk POINT <1,2> */
  /* I.S. Sembarang */
  /* F.S. P terdefinisi */
  /* KAMUS */
  float x, y;

  /* ALGORITMA */
  scanf("%f %f", &x, &y);
  *P = MakePOINT(x, y);
}

void TulisPOINT(POINT P)
{
  /* Nilai P ditulis ke layar dengan format "(X,Y)" 
    tanpa spasi, enter, atau karakter lain di depan, belakang, 
    atau di antaranya 
    Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
  */
  /* I.S. P terdefinisi */
  /* F.S. P tertulis di layar dengan format "(X,Y)" */
  /* ALGORITMA */
  printf("(%.2f,%.2f)", (float)Absis(P), (float)Ordinat(P));
}
