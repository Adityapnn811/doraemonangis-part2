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
  IDX_HEAD(*q) = IDX_UNDEF;
  IDX_TAIL(*q) = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean isEmpty(Queue q)
{
  /* Mengirim true jika q kosong: lihat definisi di atas */
  /* ALGORITMA */
  return IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF;
}
boolean isFull(Queue q)
{
  /* Mengirim true jika tabel penampung elemen q sudah penuh */
  /* yaitu jika index head bernilai 0 dan index tail bernilai CAPACITY-1 */
  /* ALGORITMA */
  return IDX_HEAD(q) == 0 && IDX_TAIL(q) == (CAPACITY - 1);
}
int length(Queue q)
{
  /* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
  /* ALGORITMA */
  if (isEmpty(q))
  {
    return 0;
  }

  return IDX_TAIL(q) - IDX_HEAD(q) + 1;
}

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElType val)
{
  /* Proses: Menambahkan val pada q dengan aturan FIFO */
  /* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
  /* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
          Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen q
          menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */
  /* KAMUS */
  int head;

  /* ALGORITMA */
  if (isEmpty(*q))
  {
    IDX_HEAD(*q) = 0;
    IDX_TAIL(*q) = 0;
    HEAD(*q) = val;
  }
  else
  {
    if (IDX_TAIL(*q) == (CAPACITY - 1))
    {
      head = IDX_HEAD(*q);
      while (IDX_HEAD(*q) <= IDX_TAIL(*q))
      {
        ElType tmp = HEAD(*q);
        IDX_HEAD(*q) -= head;
        HEAD(*q) = tmp;
        IDX_HEAD(*q) += head;
        ++IDX_HEAD(*q);
      }
      IDX_HEAD(*q) = 0;
      IDX_TAIL(*q) -= head;
    }

    ++IDX_TAIL(*q);
    TAIL(*q) = val;
  }
}

void dequeue(Queue *q, ElType *val)
{
  /* Proses: Menghapus val pada q dengan aturan FIFO */
  /* I.S. q tidak mungkin kosong */
  /* F.S. val = nilai elemen HEAD pd I.S., HEAD dan IDX_HEAD "mundur"; 
          q mungkin kosong */
  /* ALGORITMA */
  if (!isEmpty(*q))
  {
    *val = HEAD(*q);
    ++IDX_HEAD(*q);

    if (IDX_HEAD(*q) > IDX_TAIL(*q))
    {
      IDX_HEAD(*q) = IDX_UNDEF;
      IDX_TAIL(*q) = IDX_UNDEF;
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
  if (!isEmpty(q))
  {
    while (IDX_HEAD(q) <= IDX_TAIL(q))
    {
      printf("%d%s", HEAD(q), (IDX_HEAD(q) + 1 <= IDX_TAIL(q) ? "," : ""));
      ++IDX_HEAD(q);
    }
  }
  printf("]");
}