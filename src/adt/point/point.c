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
  printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

/* *** Kelompok operasi relasional terhadap POINT *** */

boolean EQ(POINT P1, POINT P2)
{
  /* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
  /* ALGORITMA */
  return Absis(P1) == Absis(P2) && Ordinat(P1) == Ordinat(P2);
}

boolean NEQ(POINT P1, POINT P2)
{
  /* Mengirimkan true jika P1 tidak sama dengan P2 */
  /* ALGORITMA */
  return Absis(P1) != Absis(P2) || Ordinat(P1) != Ordinat(P2);
}

/* *** Kelompok menentukan di mana P berada *** */

boolean IsOrigin(POINT P)
{
  /* Menghasilkan true jika P adalah titik origin */
  /* ALGORITMA */
  return Absis(P) == 0.0 && Ordinat(P) == 0.0;
}

boolean IsOnSbX(POINT P)
{
  /* Menghasilkan true jika P terletak Pada sumbu X */
  /* ALGORITMA */
  return Ordinat(P) == 0.0;
}

boolean IsOnSbY(POINT P)
{
  /* Menghasilkan true jika P terletak pada sumbu Y */
  /* ALGORITMA */
  return Absis(P) == 0.0;
}

int Kuadran(POINT P)
{
  /* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
  /* Prekondisi : P bukan titik origin, */
  /*              dan P tidak terletak di salah satu sumbu */
  /* ALGORITMA */
  if (Ordinat(P) > 0.0)
  {
    if (Absis(P) > 0.0)
    {
      return 1;
    }
    else
    {
      return 2;
    }
  }
  else
  {
    if (Absis(P) > 0.0)
    {
      return 4;
    }
    else
    {
      return 3;
    }
  }
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */

POINT NextX(POINT P)
{
  /* Mengirim salinan P dengan absis ditambah satu */
  /* ALGORITMA */
  return MakePOINT(Absis(P) + 1.0, Ordinat(P));
}

POINT NextY(POINT P)
{
  /* Mengirim salinan P dengan ordinat ditambah satu */
  /* ALGORITMA */
  return MakePOINT(Absis(P), Ordinat(P) + 1.0);
}

POINT PlusDelta(POINT P, float deltaX, float deltaY)
{
  /* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
  /* ALGORITMA */
  return MakePOINT(Absis(P) + deltaX, Ordinat(P) + deltaY);
}

POINT MirrorOf(POINT P, boolean SbX)
{
  /* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
  /* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
  /* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
  /* ALGORTIMA */
  if (SbX)
  {
    return MakePOINT(Absis(P), -(Ordinat(P)));
  }
  else
  {
    return MakePOINT(-(Absis(P)), Ordinat(P));
  }
}

float Jarak0(POINT P)
{
  /* Menghitung jarak P ke (0,0) */
  /* ALGORITMA */
  return sqrt(pow(Absis(P), 2.0) + pow(Ordinat(P), 2.0));
}

float Panjang(POINT P1, POINT P2)
{
  /* Menghitung jarak antara titik P1 dan P2 */
  /* KAMUS */
  float x, y;

  /* ALGORITMA */
  x = Absis(P1) - Absis(P2);
  y = Ordinat(P1) - Ordinat(P2);
  return sqrt(pow(x, 2.0) + pow(y, 2.0));
}

void Geser(POINT *P, float deltaX, float deltaY)
{
  /* I.S. P terdefinisi */
  /* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
  /* ALGORITMA */
  Absis(*P) += deltaX;
  Ordinat(*P) += deltaY;
}

void GeserKeSbX(POINT *P)
{
  /* I.S. P terdefinisi */
  /* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
  /* Proses : P digeser ke sumbu X. */
  /* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
  /* ALGORITMA */
  Ordinat(*P) = 0.0;
}

void GeserKeSbY(POINT *P)
{
  /* I.S. P terdefinisi*/
  /* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
  /* Proses : P digeser ke sumbu Y. */
  /* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
  /* ALGORITMA */
  Absis(*P) = 0.0;
}

void Mirror(POINT *P, boolean SbX)
{
  /* I.S. P terdefinisi */
  /* F.S. P dicerminkan tergantung nilai SbX atau SbY */
  /* Jika SbX true maka dicerminkan terhadap sumbu X */
  /* Jika SbX false maka dicerminkan terhadap sumbu Y */
  if (SbX)
  {
    Ordinat(*P) = -(Ordinat(*P));
  }
  else
  {
    Absis(*P) = -(Absis(*P));
  }
}

void Putar(POINT *P, float Sudut)
{
  /* I.S. P terdefinisi */
  /* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) */
  /* KAMUS */
  float x, y;

  /* ALGORITMA */
  x = Absis(*P);
  y = Ordinat(*P);
  Sudut = (Sudut / 180) * 3.14159265359; /* konversi ke radian */
  Absis(*P) = cos(Sudut) * x + sin(Sudut) * y;
  Ordinat(*P) = -(sin(Sudut)) * x + cos(Sudut) * y;
}
