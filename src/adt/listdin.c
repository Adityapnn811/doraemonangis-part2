/**
 * File: listdin.c
 * Tanggal: 2021/09/14
 * NIM / Nama: 13520024 / Hilya Fadhilah Imania
 *
 * listdin.c
 * Implementasi ADT List dengan array dinamis eksplisit
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listdin.h"

#define BUFFER_SIZE(c) (sizeof(ElType) * (c))

/* ********** KONSTRUKTOR ********** */

/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity)
{
  /* I.S. l sembarang, capacity > 0 */
  /* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
  /* ALGORITMA */
  CAPACITY(*l) = capacity;
  NEFF(*l) = 0;
  BUFFER(*l) = malloc(BUFFER_SIZE(capacity));
}

void dealocate(ListDin *l)
{
  /* I.S. l terdefinisi; */
  /* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
  /* ALGORITMA */
  free(BUFFER(*l));
  NEFF(*l) = 0;
  CAPACITY(*l) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */

/* *** Banyaknya elemen *** */
int length(ListDin l)
{
  /* Mengirimkan banyaknya elemen efektif list */
  /* Mengirimkan nol jika list l kosong */
  /* ALGORITMA */
  return NEFF(l);
}

/* *** Selektor INDEKS *** */
IdxType getLastIdx(ListDin l)
{
  /* Prekondisi : List l tidak kosong */
  /* Mengirimkan indeks elemen l terakhir */
  /* ALGORITMA */
  return NEFF(l) - 1;
}

/* ********** Test Indeks yang valid ********** */

boolean isIdxValid(ListDin l, int i)
{
  /* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
  /* yaitu antara indeks yang terdefinisi utk container*/
  /* ALGORITMA */
  return (i >= 0) && (i < CAPACITY(l));
}

boolean isIdxEff(ListDin l, IdxType i)
{
  /* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
  /* yaitu antara 0..NEFF(l) */
  /* ALGORITMA */
  return isIdxValid(l, i) && (i <= getLastIdx(l));
}

/* ********** TEST KOSONG/PENUH ********** */

/* *** Test list kosong *** */
boolean isEmpty(ListDin l)
{
  /* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
  /* ALGORITMA */
  return NEFF(l) == 0;
}

/* *** Test list penuh *** */
boolean isFull(ListDin l)
{
  /* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
  /* ALGORITMA */
  return NEFF(l) == CAPACITY(l);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */

/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l)
{
  /* I.S. l sembarang dan sudah dialokasikan sebelumnya */
  /* F.S. List l terdefinisi */
  /* Proses : membaca banyaknya elemen l dan mengisi nilainya */
  /* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
  /*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
  /*    Jika N tidak valid, tidak diberikan pesan kesalahan */
  /* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
        0 satu per satu diakhiri enter */
  /*    Jika N = 0; hanya terbentuk l kosong */
  /* KAMUS */
  int len, i;

  /* ALGORITMA */
  do
  {
    scanf("%d", &len);
  } while (len < 0 || len > CAPACITY(*l));

  NEFF(*l) = len;
  for (i = 0; i < len; i++)
  {
    scanf("%d", &(ELMT(*l, i)));
  }
}

void displayList(ListDin l)
{
  /* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
    antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
    di tengah, atau di belakang, termasuk spasi dan enter */
  /* I.S. l boleh kosong */
  /* F.S. Jika l tidak kosong: [e1,e2,...,en] */
  /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
  /* Jika list kosong : menulis [] */
  /* KAMUS */
  int i, len;

  /* ALGORITMA */
  printf("[");
  len = length(l);
  for (i = 0; i < len; i++)
  {
    printf("%d%s", ELMT(l, i), (i + 1 != len) ? "," : "");
  }
  printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */

/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus)
{
  /* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
  /* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
  /* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */
  /* KAMUS */
  ListDin l;
  int i, len;

  /* ALGORITMA */
  len = length(l1);
  CreateListDin(&l, CAPACITY(l1));
  NEFF(l) = len;
  for (i = 0; i < len; i++)
  {
    if (plus)
      ELMT(l, i) = ELMT(l1, i) + ELMT(l2, i);
    else
      ELMT(l, i) = ELMT(l1, i) - ELMT(l2, i);
  }

  return l;
}

/* ********** OPERATOR RELASIONAL ********** */

/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2)
{
  /* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */
  /* KAMUS */
  /* int i, len; */
  /* boolean isEqual; */

  /* ALGORITMA */
  if (length(l1) != length(l2))
  {
    return false;
  }
  else
  {
    int i = 0, len = length(l1);
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

/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val)
{
  /* Search apakah ada elemen List l yang bernilai val */
  /* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
  /* Jika tidak ada, mengirimkan IDX_UNDEF */
  /* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
  /* Skema Searching yang digunakan bebas */
  /* KAMUS */
  /* int i, len; */
  /* boolean isFound; */

  /* ALGORITMA */
  if (isEmpty(l))
  {
    return IDX_UNDEF;
  }
  else
  {
    int i = 0, len = length(l);
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

void extremes(ListDin l, ElType *max, ElType *min)
{
  /* I.S. List l tidak kosong */
  /* F.S. max berisi nilai maksimum l;
          min berisi nilai minimum l */
  /* KAMUS */
  int i, len;

  /* ALGORITMA */
  *max = ELMT(l, 0);
  *min = ELMT(l, 0);
  for (i = 1, len = length(l); i < len; i++)
  {
    if (ELMT(l, i) > *max)
      *max = ELMT(l, i);
    if (ELMT(l, i) < *min)
      *min = ELMT(l, i);
  }
}

/* ********** OPERASI LAIN ********** */

void copyList(ListDin lIn, ListDin *lOut)
{
  /* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
  /* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
  /* Proses : Menyalin isi lIn ke lOut */
  /* ALGORITMA */
  CreateListDin(lOut, CAPACITY(lIn));
  memcpy(BUFFER(*lOut), BUFFER(lIn), BUFFER_SIZE(CAPACITY(lIn)));
  NEFF(*lOut) = NEFF(lIn);
}

ElType sumList(ListDin l)
{
  /* Menghasilkan hasil penjumlahan semua elemen l */
  /* Jika l kosong menghasilkan 0 */
  /* ALGORITMA */
  long int sum;
  int i, len;

  /* ALGORITMA */
  sum = 0;
  len = length(l);
  for (i = 0; i < len; i++)
  {
    sum += ELMT(l, i);
  }
  return sum;
}

int countVal(ListDin l, ElType val)
{
  /* Menghasilkan berapa banyak kemunculan val di l */
  /* Jika l kosong menghasilkan 0 */
  /* ALGORITMA */
  int i, len, occ;

  /* ALGORITMA */
  occ = 0;
  len = length(l);
  for (i = 0; i < len; i++)
  {
    if (ELMT(l, i) == val)
      ++occ;
  }
  return occ;
}

boolean isAllEven(ListDin l)
{
  /* Menghailkan true jika semua elemen l genap. l boleh kosong */
  /* KAMUS */
  /* int i, len; */
  /* boolean isEven; */

  /* ALGORITMA */
  if (isEmpty(l))
  {
    return true;
  }
  else
  {
    int i = 0, len = length(l);
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

void sort(ListDin *l, boolean asc)
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
  if (!isEmpty(*l))
  {
    /* Selection Sort */
    int pass = 0, len = length(*l);
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
void insertLast(ListDin *l, ElType val)
{
  /* Proses: Menambahkan val sebagai elemen terakhir list */
  /* I.S. List l boleh kosong, tetapi tidak penuh */
  /* F.S. val adalah elemen terakhir l yang baru */
  /* ALGORITMA */
  ELMT(*l, length(*l)) = val;
  ++NEFF(*l);
}

/* ********** MENGHAPUS ELEMEN ********** */

void deleteLast(ListDin *l, ElType *val)
{
  /* Proses : Menghapus elemen terakhir list */
  /* I.S. List tidak kosong */
  /* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
  /*      Banyaknya elemen list berkurang satu */
  /*      List l mungkin menjadi kosong */
  /* ALGORITMA */
  *val = ELMT(*l, getLastIdx(*l));
  --NEFF(*l);
}

/* ********* MENGUBAH UKURAN ARRAY ********* */

void growList(ListDin *l, int num)
{
  /* Proses : Menambahkan capacity l sebanyak num */
  /* I.S. List sudah terdefinisi */
  /* F.S. Ukuran list bertambah sebanyak num */
  /* ALGORITMA */
  int newCap;
  ElType *p;

  /* KAMUS */
  newCap = CAPACITY(*l) + num;
  p = (ElType *)realloc(BUFFER(*l), BUFFER_SIZE(newCap));
  if (p != NULL)
  {
    BUFFER(*l) = p;
    CAPACITY(*l) = newCap;
  }
}

void shrinkList(ListDin *l, int num)
{
  /* Proses : Mengurangi capacity sebanyak num */
  /* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
  /* F.S. Ukuran list berkurang sebanyak num. */
  BUFFER(*l) = (ElType *)realloc(BUFFER(*l), BUFFER_SIZE(CAPACITY(*l) - num));
  CAPACITY(*l) -= num;
}

void compactList(ListDin *l)
{
  /* Proses : Mengurangi capacity sehingga nEff = capacity */
  /* I.S. List lidak kosong */
  /* F.S. Ukuran nEff = capacity */
  /* ALGORITMA */
  int newCap;
  ElType *p;

  /* KAMUS */
  newCap = NEFF(*l);
  p = realloc(BUFFER(*l), BUFFER_SIZE(newCap));
  if (p != NULL)
  {
    BUFFER(*l) = p;
    CAPACITY(*l) = newCap;
  }
}
