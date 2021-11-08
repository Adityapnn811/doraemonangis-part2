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
  CAPACITYListDin(*l) = capacity;
  NEFFListDin(*l) = 0;
  BUFFER(*l) = malloc(BUFFER_SIZE(capacity));
}

void dealocateListDin(ListDin *l)
{
  /* I.S. l terdefinisi; */
  /* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFFListDin(l)=0 */
  /* ALGORITMA */
  free(BUFFER(*l));
  NEFFListDin(*l) = 0;
  CAPACITYListDin(*l) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */

/* *** Banyaknya elemen *** */
int lengthListDin(ListDin l)
{
  /* Mengirimkan banyaknya elemen efektif list */
  /* Mengirimkan nol jika list l kosong */
  /* ALGORITMA */
  return NEFFListDin(l);
}

/* *** Selektor INDEKS *** */
IdxType getLastIdxListDin(ListDin l)
{
  /* Prekondisi : List l tidak kosong */
  /* Mengirimkan indeks elemen l terakhir */
  /* ALGORITMA */
  return NEFFListDin(l) - 1;
}

/* ********** Test Indeks yang valid ********** */

boolean isIdxValidListDin(ListDin l, int i)
{
  /* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
  /* yaitu antara indeks yang terdefinisi utk container*/
  /* ALGORITMA */
  return (i >= 0) && (i < CAPACITYListDin(l));
}

boolean isIdxEffListDin(ListDin l, IdxType i)
{
  /* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
  /* yaitu antara 0..NEFFListDin(l) */
  /* ALGORITMA */
  return isIdxValidListDin(l, i) && (i <= getLastIdxListDin(l));
}

/* ********** TEST KOSONG/PENUH ********** */

/* *** Test list kosong *** */
boolean isEmptyListDin(ListDin l)
{
  /* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
  /* ALGORITMA */
  return NEFFListDin(l) == 0;
}

/* *** Test list penuh *** */
boolean isFullListDin(ListDin l)
{
  /* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
  /* ALGORITMA */
  return NEFFListDin(l) == CAPACITYListDin(l);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */

/* *** Mendefinisikan isi list dari pembacaan *** */
void readListdin(ListDin *l)
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
  } while (len < 0 || len > CAPACITYListDin(*l));

  NEFFListDin(*l) = len;
  for (i = 0; i < len; i++)
  {
    scanf("%d", &(ELMTListDin(*l, i)));
  }
}

void displayListDin(ListDin l)
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
  len = lengthListDin(l);
  for (i = 0; i < len; i++)
  {
    printf("%d%s", ELMTListDin(l, i), (i + 1 != len) ? "," : "");
  }
  printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */

/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusListDin(ListDin l1, ListDin l2, boolean plus)
{
  /* Prekondisi : l1 dan l2 memiliki NEFFListDin sama dan tidak kosong */
  /* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
  /* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */
  /* KAMUS */
  ListDin l;
  int i, len;

  /* ALGORITMA */
  len = lengthListDin(l1);
  CreateListDin(&l, CAPACITYListDin(l1));
  NEFFListDin(l) = len;
  for (i = 0; i < len; i++)
  {
    if (plus)
      ELMTListDin(l, i) = ELMTListDin(l1, i) + ELMTListDin(l2, i);
    else
      ELMTListDin(l, i) = ELMTListDin(l1, i) - ELMTListDin(l2, i);
  }

  return l;
}

/* ********** OPERATOR RELASIONAL ********** */

/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2)
{
  /* Mengirimkan true jika l1 sama dengan l2 yaitu jika NEFFListDin l1 = l2 dan semua elemennya sama */
  /* KAMUS */
  /* int i, len; */
  /* boolean isEqual; */

  /* ALGORITMA */
  if (lengthListDin(l1) != lengthListDin(l2))
  {
    return false;
  }
  else
  {
    int i = 0, len = lengthListDin(l1);
    boolean isEqual = true;
    while (isEqual && (i < len))
    {
      if (ELMTListDin(l1, i) != ELMTListDin(l2, i))
        isEqual = false;
      else
        i++;
    }

    return isEqual;
  }
}

/* ********** SEARCHING ********** */

/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOfListDin(ListDin l, ElType val)
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
  if (isEmptyListDin(l))
  {
    return IDX_UNDEF;
  }
  else
  {
    int i = 0, len = lengthListDin(l);
    boolean isFound = false;
    while (!isFound && (i < len))
    {
      if (ELMTListDin(l, i) == val)
        isFound = true;
      else
        i++;
    }

    return isFound ? i : IDX_UNDEF;
  }
}

/* ********** NILAI EKSTREM ********** */

void extremesListDin(ListDin l, ElType *max, ElType *min)
{
  /* I.S. List l tidak kosong */
  /* F.S. max berisi nilai maksimum l;
          min berisi nilai minimum l */
  /* KAMUS */
  int i, len;

  /* ALGORITMA */
  *max = ELMTListDin(l, 0);
  *min = ELMTListDin(l, 0);
  for (i = 1, len = lengthListDin(l); i < len; i++)
  {
    if (ELMTListDin(l, i) > *max)
      *max = ELMTListDin(l, i);
    if (ELMTListDin(l, i) < *min)
      *min = ELMTListDin(l, i);
  }
}

/* ********** OPERASI LAIN ********** */

void copyListDin(ListDin lIn, ListDin *lOut)
{
  /* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
  /* F.S. lOut berisi salinan dari lIn (identik, NEFFListDin dan capacity sama) */
  /* Proses : Menyalin isi lIn ke lOut */
  /* ALGORITMA */
  CreateListDin(lOut, CAPACITYListDin(lIn));
  memcpy(BUFFER(*lOut), BUFFER(lIn), BUFFER_SIZE(CAPACITYListDin(lIn)));
  NEFFListDin(*lOut) = NEFFListDin(lIn);
}

ElType sumListDin(ListDin l)
{
  /* Menghasilkan hasil penjumlahan semua elemen l */
  /* Jika l kosong menghasilkan 0 */
  /* ALGORITMA */
  long int sum;
  int i, len;

  /* ALGORITMA */
  sum = 0;
  len = lengthListDin(l);
  for (i = 0; i < len; i++)
  {
    sum += ELMTListDin(l, i);
  }
  return sum;
}

int countValListDin(ListDin l, ElType val)
{
  /* Menghasilkan berapa banyak kemunculan val di l */
  /* Jika l kosong menghasilkan 0 */
  /* ALGORITMA */
  int i, len, occ;

  /* ALGORITMA */
  occ = 0;
  len = lengthListDin(l);
  for (i = 0; i < len; i++)
  {
    if (ELMTListDin(l, i) == val)
      ++occ;
  }
  return occ;
}

boolean isAllEvenListDin(ListDin l)
{
  /* Menghailkan true jika semua elemen l genap. l boleh kosong */
  /* KAMUS */
  /* int i, len; */
  /* boolean isEven; */

  /* ALGORITMA */
  if (isEmptyListDin(l))
  {
    return true;
  }
  else
  {
    int i = 0, len = lengthListDin(l);
    boolean isEven = true;
    while (isEven && (i < len))
    {
      if (ELMTListDin(l, i) % 2 != 0)
        isEven = false;
      else
        i++;
    }

    return isEven;
  }
}

/* ********** SORTING ********** */

void sortListDin(ListDin *l, boolean asc)
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
  if (!isEmptyListDin(*l))
  {
    /* Selection Sort */
    int pass = 0, len = lengthListDin(*l);
    for (; pass < len; pass++)
    {
      int iSwap = pass, i = pass + 1;
      for (; i < len; i++)
      {
        if ((asc && ELMTListDin(*l, i) < ELMTListDin(*l, iSwap)) ||
            (!asc && ELMTListDin(*l, i) > ELMTListDin(*l, iSwap)))
          iSwap = i;
      }

      ElType tmp = ELMTListDin(*l, pass);
      ELMTListDin(*l, pass) = ELMTListDin(*l, iSwap);
      ELMTListDin(*l, iSwap) = tmp;
    }
  }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */

/* *** Menambahkan elemen terakhir *** */
void insertLastListDin(ListDin *l, ElType val)
{
  /* Proses: Menambahkan val sebagai elemen terakhir list */
  /* I.S. List l boleh kosong, tetapi tidak penuh */
  /* F.S. val adalah elemen terakhir l yang baru */
  /* ALGORITMA */
  ELMTListDin(*l, lengthListDin(*l)) = val;
  ++NEFFListDin(*l);
}

/* ********** MENGHAPUS ELEMEN ********** */

void deleteLastListDin(ListDin *l, ElType *val)
{
  /* Proses : Menghapus elemen terakhir list */
  /* I.S. List tidak kosong */
  /* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
  /*      Banyaknya elemen list berkurang satu */
  /*      List l mungkin menjadi kosong */
  /* ALGORITMA */
  *val = ELMTListDin(*l, getLastIdxListDin(*l));
  --NEFFListDin(*l);
}

/* ********* MENGUBAH UKURAN ARRAY ********* */

void growListDin(ListDin *l, int num)
{
  /* Proses : Menambahkan capacity l sebanyak num */
  /* I.S. List sudah terdefinisi */
  /* F.S. Ukuran list bertambah sebanyak num */
  /* ALGORITMA */
  int newCap;
  ElType *p;

  /* KAMUS */
  newCap = CAPACITYListDin(*l) + num;
  p = (ElType *)realloc(BUFFER(*l), BUFFER_SIZE(newCap));
  if (p != NULL)
  {
    BUFFER(*l) = p;
    CAPACITYListDin(*l) = newCap;
  }
}

void shrinkListDin(ListDin *l, int num)
{
  /* Proses : Mengurangi capacity sebanyak num */
  /* I.S. List sudah terdefinisi, ukuran capacity > num, dan NEFFListDin < capacity - num. */
  /* F.S. Ukuran list berkurang sebanyak num. */
  BUFFER(*l) = (ElType *)realloc(BUFFER(*l), BUFFER_SIZE(CAPACITYListDin(*l) - num));
  CAPACITYListDin(*l) -= num;
}

void compactListDin(ListDin *l)
{
  /* Proses : Mengurangi capacity sehingga NEFFListDin = capacity */
  /* I.S. List lidak kosong */
  /* F.S. Ukuran NEFFListDin = capacity */
  /* ALGORITMA */
  int newCap;
  ElType *p;

  /* KAMUS */
  newCap = NEFFListDin(*l);
  p = realloc(BUFFER(*l), BUFFER_SIZE(newCap));
  if (p != NULL)
  {
    BUFFER(*l) = p;
    CAPACITYListDin(*l) = newCap;
  }
}
