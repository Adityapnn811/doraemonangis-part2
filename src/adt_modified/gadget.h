#ifndef GADGET_H_INCLUDED
#define GADGET_H_INCLUDED

#include "src/models/boolean.h"
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

const NamaGadget Kain;
const NamaGadget Senter;
const NamaGadget Pintu;
const NamaGadget Mesin;
const NamaGadget Pengecil;

NamaGadget DaftarGadget[5];


boolean isFullInv(Inventory inv);
void CreateInv(Inventory *inv);
void Buy(Inventory *inv, int *uang);
void DisplayGadget(Inventory *inv);
void UseGadget(NamaGadget gdg);
void AddGadget(Inventory *inv,NamaGadget gdg);
NamaGadget isGadget(Inventory inv, char key);
void deleteGadget(Inventory *inv, int i);


#endif // GADGET_H_INCLUDED
