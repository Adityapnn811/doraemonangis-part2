#ifndef PESANAN_H_INCLUDED
#define PESANAN_H_INCLUDED

#include "../../game_header.h"

#define CAPACITY_PSN 100
#define IDX_UNDEF -1

typedef struct {
    int TimeIn; // Waktu masuk item
    char PickUp; // bangunan tempat pick up item
    char DropOff; // bangunan untuk drop off item
    char ItemType; // tipe item, h, n, dll
    int TimePerish; // waktu hingga item hangus, hanya untuk item P, selain item P bernilai TIME_UNDEF
    boolean done;
} Pesanan;

#define TIMEIN(i) (i).TimeIn
#define PICKUP(i) (i).PickUp
#define DROPOFF(i) (i).DropOff
#define TYPE(i) (i).ItemType
#define TIMEPERISH(i) (i).TimePerish
#define DONE(i) (i).done

typedef struct {
    Pesanan daftar[CAPACITY_PSN];
    int idx_head;
    int idx_tail;
} DaftarPesanan;

#define IDX_HEADPSN(q) (q).idx_head
#define IDX_TAILPSN(q) (q).idx_tail
#define HEADPSN(q) (q).daftar[(q).idx_head]
#define TAILPSN(q) (q).daftar[(q).idx_tail]

void CreatePesanan(Pesanan *i, int TimeIn, char PickUp, char DropOff, char ItemType, int TimePerish);

void CreateDaftar(DaftarPesanan *dp);

void enqueuePsn(DaftarPesanan *dft, Pesanan pt);
void dequeuePsn(DaftarPesanan *dft);
void dequeuePsntoVal(DaftarPesanan *dft,Pesanan *pt);
boolean CmpPesanan(Pesanan P1, Pesanan P2);

boolean isEmptyDftr(DaftarPesanan p);
boolean isFullDftr(DaftarPesanan p);
int lengthDftr(DaftarPesanan q);

void PesananSelesai(DaftarPesanan *pt,Pesanan ps);







#endif // PESANAN_H_INCLUDED
