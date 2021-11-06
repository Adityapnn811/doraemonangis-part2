/**
 * File: listpos.c
 * Tanggal: 2021/09/08
 * NIM / Nama: 13520024 / Hilya Fadhilah Imania
 *
 * listpos.c
 * Implementasi ADT List int dengan array statik implisit
 */
#include <stdio.h>
#include "listpos.h"

/* ********** KONSTRUKTOR ********** */

/* Konstruktor : create List kosong  */
void CreateListPos(ListPos *l)
{
  /* I.S. l sembarang */
  /* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
  /* Proses: Inisialisasi semua elemen List l dengan VAL_UNDEF */
  /* KAMUS */
  int i;

  /* ALGORITMA */
  for (i = 0; i < CAPACITY; i++)
  {
    ELMT(*l, i) = VAL_UNDEF;
  }
}

/* ********** SELEKTOR (TAMBAHAN) ********** */

/* *** Banyaknya elemen *** */
int lengthListPos(ListPos l)
{
  /* Mengirimkan banyaknya elemen efektif List */
  /* Mengirimkan nol jika List kosong */
  /* KAMUS */
  int i;

  /* ALGORITMA */
  for (i = 0; ELMT(l, i) != VAL_UNDEF && i < CAPACITY; i++)
    continue;

  return i;
}

/* ********** Test Indeks yang valid ********** */

boolean isIdxValidListPos(ListPos l, int i)
{
  /* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
  /* yaitu antara indeks yang terdefinisi utk container*/
  /* ALGORITMA */
  return (i > 0) && (i < CAPACITY);
}

boolean isIdxEffListPos(ListPos l, int i)
{
  /* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
  /* yaitu antara 0..lengthListPos(l)-1 */
  /* ALGORITMA */
  return (isIdxValidListPos(l, i)) && (ELMT(l, i) != VAL_UNDEF);
}

/* ********** TEST KOSONG/PENUH ********** */

/* *** Test List kosong *** */
boolean isEmptyListPosListPos(ListPos l)
{
  /* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
  /* ALGORITMA */
  return lengthListPos(l) == 0;
}

/* *** Test List penuh *** */
boolean isFullListPos(ListPos l)
{
  /* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
  /* ALGORITMA */
  return lengthListPos(l) == CAPACITY;
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */

/* *** Mendefinisikan isi List dari pembacaan *** */
void readListPos(ListPos *l)
{
  /* I.S. l sembarang */
  /* F.S. List l terdefinisi */
  /* Proses: membaca banyaknya elemen l dan mengisi nilainya */
  /* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
  /*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
  /*    Jika n tidak valid, tidak diberikan pesan kesalahan */
  /* 2. Jika 0 < n <= CAPACITY Lakukan n kali: 
            Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
  /*    Jika n = 0 hanya terbentuk List kosong */
  /* KAMUS */
  int len, i;

  /* ALGORITMA */
  do
  {
    scanf("%d", &len);
  } while (len < 0 || len > CAPACITY);

  CreateListPos(l);
  for (i = 0; i < len; i++)
  {
    scanf("%d", &(ELMT(*l, i)));
  }
}

void displayListPos(ListPos l)
{
  /* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
    siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
    karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
  /* I.S. l boleh kosong */
  /* F.S. Jika l tidak kosong: [e1,e2,...,en] */
  /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
  /* Jika List kosong : menulis [] */
  /* KAMUS */
  int i, len;

  /* ALGORITMA */
  printf("[");
  len = lengthListPos(l);
  for (i = 0; i < len; i++)
  {
    printf("%d%s", ELMT(l, i), (i + 1 != len) ? "," : "");
  }
  printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */

/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListPos plusMinusTab(ListPos l1, ListPos l2, boolean plus)
{
  /* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
  /* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada 
        indeks yang sama dijumlahkan */
  /* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi 
        elemen l2 pada indeks yang sama */
  ListPos l;
  int i, len;

  /* ALGORITMA */
  CreateListPos(&l);
  for (i = 0, len = lengthListPos(l1); i < len; i++)
  {
    if (plus)
      ELMT(l, i) = ELMT(l1, i) + ELMT(l2, i);
    else
      ELMT(l, i) = ELMT(l1, i) - ELMT(l2, i);
  }

  return l;
}

/* ********** OPERATOR RELASIONAL ********** */

/* *** Operasi pembandingan List: *** */
boolean isListPosEqual(ListPos l1, ListPos l2)
{
  /* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
    elemennya sama */
  /* KAMUS */
  /* int i, len; */
  /* boolean isEqual; */

  /* ALGORITMA */
  if (lengthListPos(l1) != lengthListPos(l2))
  {
    return false;
  }
  else
  {
    int i = 0, len = lengthListPos(l1);
    boolean isEqual = true;
    while (isEqual && (i < len))
    {
      if (ELMT(l1, i) != ELMT(l2, i))
        isEqual = false;
      else
        i++;
    }

    return isEqual;
  }
}

/* ********** SEARCHING ********** */

/* ***  Perhatian : List boleh kosong!! *** */
int indexOfListPos(ListPos l, ElType val)
{
  /* Search apakah ada elemen List l yang bernilai val */
  /* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
  /* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
  /* Skema Searching yang digunakan bebas */
  /* KAMUS */
  /* int i, len; */
  /* boolean isFound; */

  /* ALGORITMA */
  if (isEmptyListPos(l))
  {
    return IDX_UNDEF;
  }
  else
  {
    int i = 0, len = lengthListPos(l);
    boolean isFound = false;
    while (!isFound && (i < len))
    {
      if (ELMT(l, i) == val)
        isFound = true;
      else
        i++;
    }

    return isFound ? i : IDX_UNDEF;
  }
}

/* ********** NILAI EKSTREM ********** */

void extremesListPos(ListPos l, ElType *max, ElType *min)
{
  /* I.S. List l tidak kosong */
  /* F.S. Max berisi nilai terbesar dalam l
          Min berisi nilai terkecil dalam l */
  /* KAMUS */
  int i, len;

  /* ALGORITMA */
  *max = ELMT(l, 0);
  *min = ELMT(l, 0);
  for (i = 1, len = lengthListPos(l); i < len; i++)
  {
    if (ELMT(l, i) > *max)
      *max = ELMT(l, i);
    if (ELMT(l, i) < *min)
      *min = ELMT(l, i);
  }
}

/* ********** OPERASI LAIN ********** */

boolean isAllEvenListPos(ListPos l)
{
  /* Menghailkan true jika semua elemen l genap */
  /* KAMUS */
  /* int i, len; */
  /* boolean isEven; */

  /* ALGORITMA */
  if (isEmptyListPos(l))
  {
    return true;
  }
  else
  {
    int i = 0, len = lengthListPos(l);
    boolean isEven = true;
    while (isEven && (i < len))
    {
      if (ELMT(l, i) % 2 != 0)
        isEven = false;
      else
        i++;
    }

    return isEven;
  }
}

/* ********** SORTING ********** */

void sortListPos(ListPos *l, boolean asc)
{
  /* I.S. l boleh kosong */
  /* F.S. Jika asc = true, l terurut membesar */
  /*      Jika asc = false, l terurut mengecil */
  /* Proses : Mengurutkan l dengan salah satu algoritma sorting,
    algoritma bebas */
  /* KAMUS */
  /* int pass, len, i, iSwap; */
  /* ElType tmp; */

  /* ALGORITMA */
  if (!isEmptyListPos(*l))
  {
    /* Selection Sort */
    int pass = 0, len = lengthListPos(*l);
    for (; pass < len; pass++)
    {
      int iSwap = pass, i = pass + 1;
      for (; i < len; i++)
      {
        if ((asc && ELMT(*l, i) < ELMT(*l, iSwap)) ||
            (!asc && ELMT(*l, i) > ELMT(*l, iSwap)))
          iSwap = i;
      }

      ElType tmp = ELMT(*l, pass);
      ELMT(*l, pass) = ELMT(*l, iSwap);
      ELMT(*l, iSwap) = tmp;
    }
  }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */

/* *** Menambahkan elemen terakhir *** */
void insertLastListPos(ListPos *l, ElType val)
{
  /* Proses: Menambahkan val sebagai elemen terakhir List */
  /* I.S. List l boleh kosong, tetapi tidak penuh */
  /* F.S. val adalah elemen terakhir l yang baru */
  /* ALGORITMA */
  ELMT(*l, lengthListPos(*l)) = val;
}

/* ********** MENGHAPUS ELEMEN ********** */

void deleteLastListPos(ListPos *l, ElType *val)
{
  /* Proses : Menghapus elemen terakhir List */
  /* I.S. List tidak kosong */
  /* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
  /*      Banyaknya elemen List berkurang satu */
  /*      List l mungkin menjadi kosong */
  /* ALGORITMA */
  *val = ELMT(*l, lengthListPos(*l) - 1);
  ELMT(*l, lengthListPos(*l) - 1) = VAL_UNDEF;
}
