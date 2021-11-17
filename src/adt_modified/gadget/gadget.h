#ifndef GADGET_H_INCLUDED
#define GADGET_H_INCLUDED

#include "../../game_header.h"
#define CAPACITY_INV 5

typedef char *name;

typedef struct {
    name nama;
    int harga;
    char key;
} NamaGadget;

typedef struct {
    NamaGadget daftar[CAPACITY_INV];
} Inventory;

#define GADGET(l,i) (l).daftar[(i)].nama
#define HARGA(l,i) (l).daftar[(i)].harga
#define KEY(l,i) (l).daftar[(i)].key

#define Kain {"Kain Pembungkus Waktu",800,'a'}
#define Senter {"Senter Pembesar",1200,'b'}
#define Pintu {"Pintu Kemana Saja",1500,'c'}
#define Mesin {"Mesin Waktu",3000,'d'}
#define Pengecil {"Senter Pengecil",800,'e'}

NamaGadget DaftarGadget[5];



boolean isFullInv(Inventory inv);
void CreateInv(Inventory *inv);
void BuyGadget(Inventory *inv, int *uang);
void DisplayGadget(Inventory *inv,int *waktu, Tas *tas,TDList todo,DaftarPesanan psn,Player *p,ListPointDin lb);
void UseGadget(NamaGadget gdg,int *waktu, Tas *tas,DaftarPesanan psn,Player *p,ListPointDin lb);
void AddGadget(Inventory *inv,NamaGadget gdg);
NamaGadget isGadget(Inventory inv, char key);
void deleteGadget(Inventory *inv, int i);


#endif // GADGET_H_INCLUDED
