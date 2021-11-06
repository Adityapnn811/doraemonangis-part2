/**
 * File: list_linked.c
 * Tanggal: 2021/10/21
 * NIM / Nama: 13520024 / Hilya Fadhilah Imania
 *
 * list_linked.c
 * Implementasi ADT Linked List
 */
#include <stdio.h>
#include "list_linked.h"

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateListLinkedLinked(List *l)
{
  /* I.S. sembarang             */
  /* F.S. Terbentuk list kosong */
  /* Algoritma */
  FIRST(*l) = NULL;
}

/****************** TEST LIST KOSONG ******************/
boolean isEmptyListLinkedListLinked(List l)
{
  /* Mengirim true jika list kosong */
  /* Algoritma */
  return FIRST(l) == NULL;
}

/****************** GETTER SETTER ******************/
ElType getElmtListLinked(List l, int idx)
{
  /* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
  /* F.S. Mengembalikan nilai elemen l pada indeks idx */
  /* Kamus */
  Address p;
  int i;

  /* Algoritma */
  p = FIRST(l);
  for (i = 0; i != idx; i++)
  {
    p = NEXT(p);
  }

  return INFO(p);
}

void setElmtListLinked(List *l, int idx, ElType val)
{
  /* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
  /* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */
  /* Kamus */
  Address p;
  int i;

  /* Algoritma */
  p = FIRST(*l);
  for (i = 0; i != idx; i++)
  {
    p = NEXT(p);
  }

  INFO(p) = val;
}

int indexOfListLinked(List l, ElType val)
{
  /* I.S. l, val terdefinisi */
  /* F.S. Mencari apakah ada elemen list l yang bernilai val */
  /* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
  /* Mengembalikan IDX_UNDEF jika tidak ditemukan */
  /* Kamus */
  Address p;
  int i;

  /* Algoritma */
  i = 0;
  p = FIRST(l);
  while (p != NULL && INFO(p) != val)
  {
    i++;
    p = NEXT(p);
  }

  return p != NULL ? i : IDX_UNDEF;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirstListLinkedListLinked(List *l, ElType val)
{
  /* I.S. l mungkin kosong */
  /* F.S. Melakukan alokasi sebuah elemen dan */
  /* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
  /* Jika alokasi gagal: I.S.= F.S. */
  /* Kamus */
  Address node, p;

  /* Algoritma */
  node = newNode(val);
  if (node != NULL)
  {
    if (isEmptyListLinked(*l))
    {
      FIRST(*l) = node;
    }
    else
    {
      NEXT(node) = FIRST(*l);
      FIRST(*l) = node;
    }
  }
}

void insertLastListLinkedListLinked(List *l, ElType val)
{
  /* I.S. l mungkin kosong */
  /* F.S. Melakukan alokasi sebuah elemen dan */
  /* menambahkan elemen list di akhir: elemen terakhir yang baru */
  /* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
  /* Kamus */
  Address node, p;

  /* Algoritma */
  node = newNode(val);
  if (node != NULL)
  {
    if (isEmptyListLinked(*l))
    {
      FIRST(*l) = node;
    }
    else
    {
      for (p = FIRST(*l); NEXT(p) != NULL; p = NEXT(p))
      {
        continue;
      }

      NEXT(p) = node;
    }
  }
}

void insertAtListLinked(List *l, ElType val, int idx)
{
  /* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
  /* F.S. Melakukan alokasi sebuah elemen dan */
  /* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
  /* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
  /* Kamus */
  Address node, p;
  int i;

  /* Algoritma */
  node = newNode(val);
  if (node != NULL)
  {
    if (idx == 0)
    {
      insertFirstListLinked(l, val);
    }
    else
    {
      p = FIRST(*l);
      for (i = 0; i < idx - 1; i++)
      {
        p = NEXT(p);
      }

      NEXT(node) = NEXT(p);
      NEXT(p) = node;
    }
  }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirstListLinkedListLinked(List *l, ElType *val)
{
  /* I.S. List l tidak kosong  */
  /* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
  /*      dan alamat elemen pertama di-dealokasi */
  /* Kamus */
  Address p;

  /* Algoritma */
  p = FIRST(*l);
  *val = INFO(p);
  FIRST(*l) = NEXT(p);
  free(p);
}

void deleteLastListLinked(List *l, ElType *val)
{
  /* I.S. list tidak kosong */
  /* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
  /*      dan alamat elemen terakhir di-dealokasi */
  /* Kamus */
  Address p;

  /* Algoritma */
  p = FIRST(*l);

  if (NEXT(p) == NULL)
  {
    *val = INFO(p);
    free(p);
    FIRST(*l) = NULL;
  }
  else
  {
    while (NEXT(p) != NULL && NEXT(NEXT(p)) != NULL)
    {
      p = NEXT(p);
    }

    *val = INFO(NEXT(p));
    free(NEXT(p));
    NEXT(p) = NULL;
  }
}

void deleteAtListLinked(List *l, int idx, ElType *val)
{
  /* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
  /* F.S. val diset dengan elemen l pada indeks ke-idx. */
  /*      Elemen l pada indeks ke-idx dihapus dari l */
  /* Kamus */
  Address node, p;
  int i;

  /* Algoritma */
  if (idx == 0)
  {
    deleteFirstListLinked(l, val);
  }
  else
  {
    p = FIRST(*l);
    for (i = 0; i < idx - 1; i++)
    {
      p = NEXT(p);
    }

    node = NEXT(p);
    *val = INFO(node);
    NEXT(p) = NEXT(NEXT(p));
    free(node);
  }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayListLinked(List l)
{
  /* I.S. List mungkin kosong */
  /* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
  /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
  /* Jika list kosong : menulis [] */
  /* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
  /* Kamus */
  Address p;

  /* Algoritma */
  printf("[");
  for (p = FIRST(l); p != NULL; p = NEXT(p))
  {
    printf("%d%s", INFO(p), (NEXT(p) != NULL) ? "," : "");
  }
  printf("]");
}

int lengthListLinked(List l)
{
  /* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
  /* Kamus */
  Address p;
  int i;

  /* Algoritma */
  i = 0;
  for (p = FIRST(l); p != NULL; p = NEXT(p))
  {
    i++;
  }

  return i;
}

/****************** PROSES TERHADAP LIST ******************/
List concatListLinked(List l1, List l2)
{
  /* I.S. l1 dan l2 sembarang */
  /* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
  /* Konkatenasi dua buah list : l1 dan l2    */
  /* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
  /* Tidak ada alokasi/dealokasi pada prosedur ini */
  /* Kamus */
  List l3;
  Address p;

  /* Algoritma */
  CreateListLinked(&l3);

  for (p = FIRST(l1); p != NULL; p = NEXT(p))
  {
    insertLastListLinked(&l3, INFO(p));
  }

  for (p = FIRST(l2); p != NULL; p = NEXT(p))
  {
    insertLastListLinked(&l3, INFO(p));
  }

  return l3;
}
