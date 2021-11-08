/**
 * File: queue.c
 * Tanggal: 2021/10/06
 * NIM / Nama: 13520024 / Hilya Fadhilah Imania
 *
 * queue.c
 * Implementasi ADT Queue
 */
#include <stdio.h>
#include "queue.h"

/* *** Kreator *** */
void CreateQueue(Queue *q)
{
  /* I.S. sembarang */
  /* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
  /* - Index head bernilai IDX_UNDEF */
  /* - Index tail bernilai IDX_UNDEF */
  /* Proses : Melakukan alokasi, membuat sebuah q kosong */
  /* ALGORITMA */
  IDX_HEADQueue(*q) = IDX_UNDEF;
  IDX_TAILQueue(*q) = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean isEmptyQueue(Queue q)
{
  /* Mengirim true jika q kosong: lihat definisi di atas */
  /* ALGORITMA */
  return IDX_HEADQueue(q) == IDX_UNDEF && IDX_TAILQueue(q) == IDX_UNDEF;
}
boolean isFullQueue(Queue q)
{
  /* Mengirim true jika tabel penampung elemen q sudah penuh */
  /* yaitu jika index head bernilai 0 dan index tail bernilai CAPACITYQueue-1 */
  /* ALGORITMA */
  return IDX_HEADQueue(q) == 0 && IDX_TAILQueue(q) == (CAPACITYQueue - 1);
}
int lengthQueue(Queue q)
{
  /* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
  /* ALGORITMA */
  if (isEmptyQueue(q))
  {
    return 0;
  }

  return IDX_TAILQueue(q) - IDX_HEADQueue(q) + 1;
}

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElType val)
{
  /* Proses: Menambahkan val pada q dengan aturan FIFO */
  /* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
  /* F.S. val menjadi TAIL yang baru, IDX_TAILQueue "mundur".
          Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen q
          menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */
  /* KAMUS */
  int head;

  /* ALGORITMA */
  if (isEmptyQueue(*q))
  {
    IDX_HEADQueue(*q) = 0;
    IDX_TAILQueue(*q) = 0;
    HEADQueue(*q) = val;
  }
  else
  {
    if (IDX_TAILQueue(*q) == (CAPACITYQueue - 1))
    {
      head = IDX_HEADQueue(*q);
      while (IDX_HEADQueue(*q) <= IDX_TAILQueue(*q))
      {
        ElType tmp = HEADQueue(*q);
        IDX_HEADQueue(*q) -= head;
        HEADQueue(*q) = tmp;
        IDX_HEADQueue(*q) += head;
        ++IDX_HEADQueue(*q);
      }
      IDX_HEADQueue(*q) = 0;
      IDX_TAILQueue(*q) -= head;
    }

    ++IDX_TAILQueue(*q);
    TAILQueue(*q) = val;
  }
}

void dequeue(Queue *q, ElType *val)
{
  /* Proses: Menghapus val pada q dengan aturan FIFO */
  /* I.S. q tidak mungkin kosong */
  /* F.S. val = nilai elemen HEAD pd I.S., HEAD dan IDX_HEADQueue "mundur"; 
          q mungkin kosong */
  /* ALGORITMA */
  if (!isEmptyQueue(*q))
  {
    *val = HEADQueue(*q);
    ++IDX_HEADQueue(*q);

    if (IDX_HEADQueue(*q) > IDX_TAILQueue(*q))
    {
      IDX_HEADQueue(*q) = IDX_UNDEF;
      IDX_TAILQueue(*q) = IDX_UNDEF;
    }
  }
}

/* *** Display Queue *** */
void displayQueue(Queue q)
{
  /* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
    siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
    karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
  /* I.S. q boleh kosong */
  /* F.S. Jika q tidak kosong: [e1,e2,...,en] */
  /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
  /* Jika Queue kosong : menulis [] */
  /* KAMUS */
  int i;
  /* ALGORITMA */
  printf("[");
  if (!isEmptyQueue(q))
  {
    while (IDX_HEADQueue(q) <= IDX_TAILQueue(q))
    {
      printf("%d%s", HEADQueue(q), (IDX_HEADQueue(q) + 1 <= IDX_TAILQueue(q) ? "," : ""));
      ++IDX_HEADQueue(q);
    }
  }
  printf("]");
}